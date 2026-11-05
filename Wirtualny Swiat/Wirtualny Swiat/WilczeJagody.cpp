#include "WilczeJagody.h"
#include "Swiat.h"
#include <iostream>

WilczeJagody::WilczeJagody(int x, int y, Swiat* swiat)
    : Roslina(99, x, y, swiat, 0.1) {
} // 10% szans na rozsianie

void WilczeJagody::kolizja(Organizm* inny) {
    // Zabija wszystkie organizmy oprócz cz³owieka
    if (inny->getNazwa() != "Czlowiek") {
        getSwiat()->usunOrganizm(inny);
    }
    getSwiat()->usunOrganizm(this); // Roœlina zawsze ginie
}

char WilczeJagody::getZnak() const {
    return 'j'; // ma³a litera zgodnie z konwencj¹
}

void WilczeJagody::rysowanie() const {
    std::cout << getZnak();
}

std::string WilczeJagody::getNazwa() const {
    return "WilczeJagody";
}

Organizm* WilczeJagody::stworzKopie(int x, int y) const {
    return new WilczeJagody(x, y, getSwiat());
}