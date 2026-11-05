#include "Mlecz.h"
#include <iostream>
#include <cstdlib>
#include "Swiat.h"
Mlecz::Mlecz(int x, int y, Swiat* swiat)
    : Roslina(0, x, y, swiat, 0.3) {
}

// Dodajemy brakuj¹c¹ implementacjê
char Mlecz::getZnak() const {
    return 'M';
}

void Mlecz::rysowanie() const {
    std::cout << getZnak(); 
}

std::string Mlecz::getNazwa() const {
    return "Mlecz";
}

Organizm* Mlecz::stworzKopie(int x, int y) const {
    return new Mlecz(x, y, getSwiat());
}

void Mlecz::akcja() {
    for (int i = 0; i < 3; ++i) {
        if ((std::rand() % 100) < 30) {
            Roslina::akcja();
        }
    }
}