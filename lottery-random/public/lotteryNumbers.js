function start() {
        document.getElementById('starting-form').style.display = 'none';
        // Pokazuje przyciski z numerami
        document.getElementById('switching-numbers').style.display = 'block';
        // Dodawanie klasy CSS do elementu HTML
        document.querySelectorAll('.number').forEach(number => {
            number.classList.add('spin');
        });
        // Usuwanie klasy CSS po 2 sekundach
        setTimeout(() => document.querySelectorAll('.number').forEach(number => number.classList.remove('spin')), 2000);
    }

    function pick(number) {
        // Przypisuje zdarzenie kliknięcia do elementu HTML
        event.target.classList.add('picked');
        // Ustawienie timeoutu na 0.5 sekundy i przekierowanie do akcji loterii
        setTimeout(() => window.location.href = `/user/action/lottery/${userId}?option=${number}`, 500);
    }