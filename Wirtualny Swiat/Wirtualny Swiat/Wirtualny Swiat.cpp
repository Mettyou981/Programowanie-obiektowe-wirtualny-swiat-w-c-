#include "Swiat.h"
#include <conio.h>
#include <iostream>

int main() {
    Swiat swiat(20, 20);
    swiat.inicjalizujSwiat();
    bool running = true;
    while (running) {
        swiat.rysujSwiat();
        swiat.wyczyscZdarzenia();

        std::cout << "\nSterowanie: strzalki - ruch, a - aktywuj umiejetnosc, q - wyjscie\n";

        int key = _getch();
        switch (key) {
        case 72: // strzałka w górę
            swiat.getCzlowiek()->setKierunek(Czlowiek::GORA);
            swiat.wykonajTure();
            break;
        case 80: // strzałka w dół
            swiat.getCzlowiek()->setKierunek(Czlowiek::DOL);
            swiat.wykonajTure();
            break;
        case 75: // strzałka w lewo
            swiat.getCzlowiek()->setKierunek(Czlowiek::LEWO);
            swiat.wykonajTure();
            break;
        case 77: // strzałka w prawo
            swiat.getCzlowiek()->setKierunek(Czlowiek::PRAWO);
            swiat.wykonajTure();
            break;
        case 'a':
            swiat.getCzlowiek()->aktywujUmiejetnosc();
            break;
        case 'q':
            running = false;
            break;
        }
    }

    return 0;
}