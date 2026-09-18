Wprowadzenie:
-Projekt o nazwie Rejestracja Bankowa jest jak widać w ostatnim zainicjowanym commit typem niepełnym aplikacji wymagającym dalszej kontynuacji.
-Ze względu na to,że ten projekt był towrzony przeze mnie samego bez pomocy osób współpracujących,co przełożyło się na to,że przy takiej wielkości i złożoności tegoż projektu będąc początkującym programistom zadał pewne trudności,które chciałbym przedstawić po krótce w tym opisie.
-Jednak ze względu na swój potencjał i wielkoskalowość jest to projekt,który ukaże państwu mój zamysł programistyczny,jak i również zakres potencjału jaki przedstawia ten projekt w aspekcie poprzeczki jaką postanowiłem powziąć,aby zaprezentować swoje umiejętności.

Opis skrócony funkcji działających:

(Opis dotyczy konkretnych kontrolek,które kryją za sobą odpowiednio desygnowane funkcje)
{Widok logowania}
-Zaloguj się
-Zarejestruj się
-DataGridView
-PictureBox
{Widok Rejestracji}
-Zarejestruj się
-Zaloguj się
-PictureBox
{Widok główny}
[Konto]
-Wykonaj transakcje 
-DataGridView(oba)
-Powtórz
-Edytuj dane transakcji
-Usuń transakcje 
-Zarchwizuj
-kontrolka wyboru daty(obie)
-ProgressBar(pod nazwą Postęp transakcji)
-ListBox(Wybierz typ przelewu)
[Rachunki]
-Wyszukaj rachunek bieżący
-DataGridView(oba)
-Wyszukaj rachunek zrealizowany
-Usuń rachunek
-Pobierz pojedynczy 
-WebBrowser(okno obok przycisku Szukaj)
-Szukaj
[Dane klienta]
-Modyfikuj
-Zatwierdź
-Wyślij do aktualizacji
-Edytuj dane
-DataGridView
-TextBox(pod nazwą Edycja informacji Bazy Danych)

[Wyjaśnienie dot.celu i powodu niekompletności wszystkich funkcjonalności]
Reszta kontrolek nie działa wg.zamierzonego celu ze względu na to,że nie zdążyłem czasowo poprawić ich struktur mając na uwadze proces poprawiania innych kontrolek formularza,aby ich funkcje mogły spełniać różnorodne funkcje,które prezentują wykorzystanie róznuch struktur kodu i funkcjonalności struktur typu SQL.
Wiele z tych nie poprawionych kontrolek ma powtarzalne lub lekko różniące się fukcje,więc nie starałem się skupiać się na ich szybkiej poprawie,aby poprawić te które zdecydowanie reprezentują zróżnicowane funkcje w celu ukazania jak zaprojektowałem różne spektrum funkcji o znacznie zmiennych przeznaczeniach.

[Zaznaczam,że byłbym przychylny lepiej zaprezentować państwu mój projekt osobiście podczas rozmowy,aby lepiej zarysować swój zamysł i wytłumaczyć koncepcje,aby projekt nie stracił na swoim potencjale poprzez to czego mu jeszcze brakuje]

Jak uruchomić
------------
Poniższe instrukcje opisują minimalne kroki potrzebne do zbudowania i uruchomienia aplikacji na systemie Windows przy użyciu Visual Studio.

Wymagania wstępne:
- System: Windows 10/11
- Visual Studio Community (2022 lub nowsze, np. 2026) z zainstalowanym obciążeniem "Desktop development with C++" (MSVC/C++ Build Tools)
- Git (do sklonowania repozytorium)

Klonowanie repozytorium:
1. Otworzyć terminal (PowerShell / pwsh) i wykonać:
   - git clone https://github.com/Mikolaj-2001/Portfolio-Projekty.git
2. Przejść do katalogu projektu:
   - cd "Portfolio-Projekty\Aplikacja-Bankowa\Rejestracja Bankowa"

Otwieranie i budowanie projektu:
1. W Visual Studio wybrać File -> Open -> Project/Solution i otworzyć plik: Rejestracja Bankowa\\Rejestracja Bankowa.sln
2. Wybrać konfigurację build (Debug/Release) oraz platformę (x86 lub x64) zgodnie z ustawieniami projektu.
3. Ustawić projekt startowy (jeśli nie jest ustawiony): prawy przycisk na projekcie -> Set as Startup Project.
4. Zbudować rozwiązanie: Build -> Build Solution (Ctrl+Shift+B).

Uruchamianie aplikacji:
- Po pomyślnym zbudowaniu uruchomić projekt z Visual Studio (F5 - debug lub Ctrl+F5 - bez debugowania).
- Alternatywnie uruchomić plik wykonywalny bezpośrednio z folderu wyjściowego np. bin\\Debug lub bin\\Release (ścieżka zależy od konfiguracji projektu).

Uwagi i rozwiązywanie problemów:
- Jeśli build zgłasza brakujące zależności, sprawdzić czy w repozytorium znajdują się foldery z bibliotekami (np. libs, thirdparty) i czy ścieżki projektu wskazują na nie poprawnie.
- Jeśli rozwiązanie używa zewnętrznych pakietów NuGet, w Visual Studio kliknąć prawym przyciskiem na solution i wybrać "Restore NuGet Packages".
- Jeśli pojawiają się błędy związane z architekturą (x86/x64), spróbować przełączyć platformę w konfiguracji projektu.
- Nie zaleca się budowania projektu bezpośrednio z katalogu synchronizowanego z OneDrive — lepiej sklonować repo lokalnie (np. C:\\dev\\).

Zorganizowana lista kroków (szybkie przypomnienie):
1) Zainstaluj Visual Studio z "Desktop development with C++".
2) Zainstaluj Git.
3) git clone https://github.com/Mikolaj-2001/Portfolio-Projekty.git
4) Otwórz Rejestracja Bankowa.sln w Visual Studio.
5) Ustaw konfigurację (Debug/Release) i platformę (x86/x64).
6) Build -> Build Solution.
7) Uruchom projekt (F5 lub uruchom exe z katalogu wyjściowego).

Dla testera — instrukcje testowe
--------------------------------
Cel: pozwolić osobie testującej sprawdzić działające funkcje i zgłosić błędy w uporządkowany sposób.

Wymagania przed testami:
- Prawidłowo zbudowane rozwiązanie (patrz wyżej). Jeśli pliki projektu (.vcxproj) lub źródła nie są obecne w sklonowanym repozytorium, skontaktuj się z autorem repozytorium w celu udostępnienia brakujących plików.
- Środowisko Windows z Visual Studio i uprawnieniami do uruchamiania aplikacji.

Scenariusze testowe (kroki i oczekiwany rezultat):
1) Logowanie
   - Kroki: uruchom aplikację -> na ekranie logowania wprowadź poprawne dane testowego konta -> kliknij "Zaloguj się".
   - Oczekiwane: przejście do widoku głównego konta bez błędów.

2) Rejestracja nowego użytkownika
   - Kroki: wybierz "Zarejestruj się" -> wypełnij formularz testowymi danymi -> zatwierdź.
   - Oczekiwane: konto utworzone, możliwość zalogowania się nowymi danymi.

3) Operacje na koncie (dodaj/edytuj/usun/archiwizuj transakcję)
   - Kroki: dodaj nową transakcję, edytuj ją, usuń/ zarchiwizuj.
   - Oczekiwane: operacje wykonane poprawnie, widoczne zmiany w widoku transakcji.

4) Rachunki (wyszukiwanie/pobieranie/usuwanie)
   - Kroki: skorzystaj z funkcji wyszukiwania rachunków, pobierz pojedynczy rachunek, usuń rachunek testowy.
   - Oczekiwane: wyniki wyszukiwania poprawne, plik/okno z rachunkiem dostępne, usunięcie skuteczne.

5) Modyfikacja danych klienta
   - Kroki: przejdź do sekcji Dane klienta -> zmień pole -> zatwierdź -> sprawdź widok i ewentualne zapisy w bazie.
   - Oczekiwane: zmiana zachowana i odzwierciedlona w aplikacji.

Jak raportować znalezione błędy:
- Podaj kroki reprodukcji (dokładne kliknięcia i dane wejściowe).
- Dołącz oczekiwany rezultat oraz rezultat rzeczywisty.
- Dodaj zrzuty ekranu i plik dziennika błędów, jeśli dostępny.
- Podaj konfigurację środowiska: Windows, wersja Visual Studio, konfiguracja build (Debug/Release), architektura (x86/x64).

Dodatkowe uwagi:
- Jeśli aplikacja korzysta z zewnętrznej bazy danych lub plików konfiguracyjnych, upewnij się, że tester otrzyma zestaw danych testowych (seed) lub instrukcję jak je przygotować.
- Jeśli napotkasz brakujące pliki projektu (.vcxproj, pliki źródłowe), dodaj do raportu informację o nazwach brakujących plików i ścieżkach wskazanych w pliku .sln.

