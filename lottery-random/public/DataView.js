 window.onload = function () {//Ta funkcja jest wywoływana, gdy strona zostanie w pełni załadowana. Ustawia początkowy stan elementów na stronie, takich jak ukrycie kodu QR i timera, oraz resetuje zawartość div'a z kodem QR.
            document.getElementById('qrcode').innerHTML = '';//Resetuje zawartość div'a z kodem QR, aby upewnić się, że jest pusty przy każdym załadowaniu strony.
        };//ten kod resetuje zawartość div'a z kodem QR

        function mongoDBCompassDataProtectionFilter() {
            const UserId = "{{user.encryptedId}}";
            const compasURL = `mongodb://localhost:27017/lottery-database?readPreference=primary&directConnection=false&ssl=false`;
            document.getElementById('connecting-string').textContent = compasURL;
        }

        function AttemptsCount() {
            const userId = "{{user.encryptedId}}";//Używa zaszyfrowanego ID użytkownika jako klucza do przechowywania i pobierania liczby prób oraz czasu ostatniej próby z localStorage, co pozwala na indywidualne śledzenie prób dla każdego użytkownika.
            const storageKey = `attempts_${userId}`;
            const timeKey = `lastAttempt_${userId}`;

            const savedAttempts = localStorage.getItem(storageKey);//Pobiera z localStorage liczbę pozostałych prób dla danego użytkownika, jeśli istnieje.
            const lastAttempt = localStorage.getItem(timeKey);
            const now = new Date().getTime();

            if (lastAttempt) {
                const timeDifference = now - parseInt(lastAttempt);
                const hoursElapsed = timeDifference / (1000 * 60 * 60);//Sprawdź, czy minęło 24 godziny
                if (hoursElapsed >= 24) {
                    localStorage.setItem(storageKey, '2');
                    localStorage.removeItem(timeKey);
                    return 2;
                }
            }
            // Jeśli istnieje zapisane liczba prób, zwróć ją, w przeciwnym razie ustaw domyślną wartość 2 i zwróć ją.
            return savedAttempts ? parseInt(savedAttempts) : 2;//Domyślnie 2 próby, ponieważ pierwsza próba jest wykonywana bezpośrednio po załadowaniu strony, a użytkownik ma jeszcze 2 próby do wykorzystania.
        }

        let attempts = AttemptsCount();
        document.getElementById('attempts-display').textContent = attempts;

        function toBase64(string) {
            return window.btoa(unescape(string));
        }//pozwala obsługiwać ciągi znaków w formacie Base64 i obce znaki nie będące znakami łacińskimi.

        function decrypteData() {
            if (attempts <= 0) {
                alert('Przekroczono limit prób odszyfrowania danych. Spróbuj ponownie za 24h');
                return;
            }

            const qrString = "__рэтэзІугъэбзнкІыэр";
            const URL = `https://www.google.com/search?q=${encodeURIComponent(qrString)}`;//Generuje URL do wyszukiwarki Google z zakodowanym ciągiem znaków, który będzie używany do generowania kodu QR. Użytkownik będzie musiał zeskanować ten kod QR, aby uzyskać dostęp do klucza weryfikacyjnego potrzebnego do odszyfrowania danych.

            // Zawsze czyść div przed generacją
            const qrDiv = document.getElementById("qrcode");
            qrDiv.innerHTML = '';
            qrDiv.style.display = "block";

            // Zawsze generuj kod QR po kliknięciu
            new QRCode(qrDiv, {
                text: URL,
                width: 320,
                height: 320
            });

            const userInput = prompt('Wprowadź klucz weryfikacyjny, aby odblokować dostęp do danych (VerifyingComponent):');
            if (!userInput) {
                alert('Nie wprowadzono klucza weryfikacyjnego');
                return;
            }
            const VerifyingComponent = userInput;//Pobiera klucz weryfikacyjny od użytkownika za pomocą promptu. Ten klucz będzie porównywany z predefiniowanym kluczem weryfikacyjnym, aby sprawdzić, czy użytkownik ma autoryzację do odszyfrowania danych.

            const resolvingKey = "ІункІыбзэр_гъэтэрэз";

            const normalize = str => str ? str.normalize('NFC').replace(/\s+/g, '').trim() : '';//Oczyszczenie kodu z możliwych znaków wsatwionych automatycznie
            const inputNormalized = normalize(VerifyingComponent);
            const keyNormalized = normalize(resolvingKey);

            // Porównanie z normalizacją
            if (inputNormalized !== keyNormalized) {
                alert('❌ Nieprawidłowy klucz weryfikacyjny! Brak autoryzacji dostępu.');
                attempts--;
                document.getElementById('attempts-display').textContent = attempts;//Wyświetl pozostałe próby
                const userId = "{{user.encryptedId}}";
                const attemptsForUsage = `attempts_${userId}`;
                const timeFrame = `lastAttempt_${userId}`;
                localStorage.setItem(attemptsForUsage, attempts.toString());//Zapisz aktualną liczbę prób w localStorage, aby śledzić, ile prób pozostało dla danego użytkownika.
                localStorage.setItem(timeFrame, new Date().getTime().toString());
                return;
            } else {
                showDataView();
            }

            function showDataView() {
                const userInformation = {
                    email: "{{ user.email }}",
                    userName: "{{ user.userName }}",
                    userId: "{{ user.id }}",
                    password: "{{ user.password }}"
                }

                const newInnerHTML = document.getElementById('user-details');
                newInnerHTML.innerHTML += `
                 <div class="user-info2" style="margin-top: 20px; padding: 15px; border: 2px solid #28a745; border-radius: 5px; background-color: #e6ffed;">
                     <h3>Informacje{jawne} o użytkowniku</h3>
                     <p><strong>Nazwa użytkownika:</strong> ${userInformation.userName}</p>
                     <p><strong>ObjectId:<strong>${userInformation.userId}</p>
                     <p><strong>Email:</strong> ${userInformation.email}</p>
                     <p><strong>Hasło:</strong> ${userInformation.password}</p>
                 </div>
                `}

            attempts--;//Zmniejsz liczbę prób po każdej próbie odszyfrowania, niezależnie od wyniku, aby zapewnić, że użytkownik ma ograniczoną liczbę prób do wykorzystania.
            document.getElementById('attempts-display').textContent = attempts;

            const userId = "{{user.encryptedId}}";
            const attemptsForUsage = `attempts_${userId}`;
            const timeFrame = `lastAttempt_${userId}`

            localStorage.setItem(attemptsForUsage, attempts.toString());
            localStorage.setItem(timeFrame, new Date().getTime().toString());

            document.getElementById('timing-inference').style.display = 'block';

            let timing = 30;
            const timer = setInterval(() => {
                timing--;
                document.getElementById('timing-inference').textContent = `Dane będą widoczne przez ${timing} sekund.`;
                if (timing <= 0) {
                    clearInterval(timer);
                    document.getElementById('timing-inference').style.display = 'none';//Ukryj timer
                    document.getElementById('qrcode').style.display = 'none';
                    const infoBlock = newInnerHTML.querySelector('.user-info2');
                    if (infoBlock) {
                        infoBlock.remove();//Usuń blok informacji o użytkowniku
                    }
                    alert('Dostęp do danych wygasł.');
                }
            }, 1000);//1000 oznacza, że timer będzie aktualizowany co sekundę, a dane będą widoczne przez 30 sekund po poprawnym wprowadzeniu klucza weryfikacyjnego.
        }

        function unlockProtectedLink() {
            const userInput = prompt('Wprowadź klucz weryfikacyjny, aby odblokować dostęp do danych (VerifyingComponent2):');
            if (!userInput) {
                alert('Nie wprowadzono hasła. Spróbuj ponownie.');
                return;
            }
            const VerifyingComponent2 = userInput;
            const resolvingKey2 = "24842671195248FGDS033hd";

            const normalize = str => str ? str.normalize('NFC').replace(/\s+/g, '').trim() : '';
            const inputNormalized = normalize(VerifyingComponent2);
            const keyNormalized = normalize(resolvingKey2);//normalizacja w celu uniknięcia problemów z formatowaniem lub niezamierzonymi znakami

            if (inputNormalized === keyNormalized) {
                document.getElementById('protected-link').style.filter = 'none';
                alert('✅ Dostęp odblokowany!');
            } else {
                alert('Nieprawidłowe hasło. Spróbuj ponownie.');
            }
        } 