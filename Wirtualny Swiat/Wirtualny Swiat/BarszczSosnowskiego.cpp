#include "BarszczSosnowskiego.h"
#include "CyberOwca.h"
#include "Swiat.h"
#include <vector>
#include <iostream>
BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat* swiat)
    : Roslina(10, x, y, swiat, 0.05) {
}

void BarszczSosnowskiego::akcja() {
    // Sprawdzanie wszystkich 8 kierunków (4 podstawowe + 4 po skosie)
    const std::vector<std::pair<int, int>> kierunki = {
        {-1,-1}, {-1,0}, {-1,1},  // lewy górny, góra, prawy górny
        {0,-1},          {0,1},    // lewo,          prawo
        {1,-1},  {1,0},  {1,1}     // lewy dolny, dó³, prawy dolny
    };

    for (const auto& kierunek : kierunki) {
        int dx = kierunek.first;
        int dy = kierunek.second;
        int newX = getPozycja().first + dx;
        int newY = getPozycja().second + dy;

        if (getSwiat()->czyWGranicach(newX, newY)) {
            Organizm* org = getSwiat()->znajdzOrganizm(newX, newY);
            if (org && dynamic_cast<Zwierze*>(org) && !dynamic_cast<CyberOwca*>(org)) {
                getSwiat()->usunOrganizm(org);
                getSwiat()->dodajZdarzenie("Barszcz zabija " + org->getNazwa());
            }
        }
    }

    Roslina::akcja(); // Standardowe rozprzestrzenianie
}

void BarszczSosnowskiego::kolizja(Organizm* inny) {
    if (!dynamic_cast<CyberOwca*>(inny)) {
        getSwiat()->usunOrganizm(inny);
        getSwiat()->dodajZdarzenie(inny->getNazwa() + " zjada Barszcz i ginie");
        getSwiat()->usunOrganizm(this);
    }
}

std::string BarszczSosnowskiego::getNazwa() const {
    return "BarszczSosnowskiego";
}

char BarszczSosnowskiego::getZnak() const {
    return 'B';
}

Organizm* BarszczSosnowskiego::stworzKopie(int x, int y) const {
    return new BarszczSosnowskiego(x, y, getSwiat());
}

void BarszczSosnowskiego::rysowanie() const {
    // Implementacja wizualizacji - np. kolorowanie na czerwono
    std::cout << "\033[1;31m" << getZnak() << "\033[0m";
}