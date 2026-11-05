#include "CyberOwca.h"
#include <climits>
#include <cmath>
#include "Swiat.h"
#include "BarszczSosnowskiego.h" // Zak³adaj¹c, ¿e taka klasa istnieje

CyberOwca::CyberOwca(int x, int y, Swiat* swiat)
    : Zwierze(10, 4, x, y, swiat) {
}

void CyberOwca::akcja() {
    // 1. Szukanie najbli¿szego barszczu
    std::pair<int, int> cel = { -1, -1 };
    int minOdleglosc = INT_MAX;

    for (int y = 0; y < getSwiat()->getWysokosc(); ++y) {
        for (int x = 0; x < getSwiat()->getSzerokosc(); ++x) {
            if (Organizm* org = getSwiat()->znajdzOrganizm(x, y)) {
                if (org->getNazwa() == "BarszczSosnowskiego") {
                    int odl = abs(x - getPozycja().first) + abs(y - getPozycja().second);
                    if (odl < minOdleglosc) {
                        minOdleglosc = odl;
                        cel = { x, y };
                    }
                }
            }
        }
    }

    // 2. Ruch w kierunku barszczu lub losowy
    if (cel.first != -1) {
        int dx = (cel.first > getPozycja().first) ? 1 :
            (cel.first < getPozycja().first) ? -1 : 0;
        int dy = (cel.second > getPozycja().second) ? 1 :
            (cel.second < getPozycja().second) ? -1 : 0;

        // SprawdŸ czy barszcz jest obok (mo¿na zjeœæ)
        if (minOdleglosc == 1) {
            if (Organizm* barszcz = getSwiat()->znajdzOrganizm(cel.first, cel.second)) {
                getSwiat()->usunOrganizm(barszcz); // Zjedzenie barszczu
                setPozycja(cel.first, cel.second); // Przejœcie na jego miejsce
            }
        }
        else {
            ruch(dx, dy); // Ruch w kierunku barszczu
        }
    }
    else {
        // Brak barszczu - ruch jak zwyk³a owca
        Zwierze::akcja();
    }
}

std::string CyberOwca::getNazwa() const {
    return "CyberOwca";
}

char CyberOwca::getZnak() const {
    return 'C';
}

Organizm* CyberOwca::stworzKopie(int x, int y) const {
    return new CyberOwca(x, y, getSwiat());
}