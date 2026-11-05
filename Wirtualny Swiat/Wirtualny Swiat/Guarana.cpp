#include "Guarana.h"
#include <string>
#include <iostream>
#include <random>
#include "Swiat.h"
Guarana::Guarana(int x, int y, Swiat* swiat)
    : Roslina(0, x, y, swiat, 0.15) {
} // 15% szans na rozsianie

void Guarana::kolizja(Organizm* inny) {
    int nowaSila = inny->getSila() + 3;
    inny->setSila(nowaSila);
    getSwiat()->usunOrganizm(this); // Roœlina zostaje zjedzona
}

char Guarana::getZnak() const {
    return 'g'; // ma³a litera zgodnie z konwencj¹
}

void Guarana::rysowanie() const {
    std::cout << getZnak();
}

std::string Guarana::getNazwa() const {
    return "Guarana";
}

Organizm* Guarana::stworzKopie(int x, int y) const {
    return new Guarana(x, y, getSwiat());
}