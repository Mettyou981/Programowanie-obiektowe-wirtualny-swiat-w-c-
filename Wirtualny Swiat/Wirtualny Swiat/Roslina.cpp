#include "Roslina.h"
#include <random>
#include <vector>
#include <utility>
#include "Swiat.h"
Roslina::Roslina(int sila, int x, int y, Swiat* swiat, double prawdRozsiania)
    : Organizm(sila, 0, x, y, swiat), prawdRozsiania(prawdRozsiania) {
}

void Roslina::akcja() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    if (dis(gen) < prawdRozsiania) {
        const int directions[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

        for (int i = 0; i < 4; ++i) {
            int newX = getPozycja().first + directions[i][0];
            int newY = getPozycja().second + directions[i][1];

            if (getSwiat()->czyWGranicach(newX, newY) &&
                !getSwiat()->znajdzOrganizm(newX, newY)) {
                getSwiat()->dodajOrganizm(stworzKopie(newX, newY));
                break;
            }
        }
    }
}

void Roslina::kolizja(Organizm* inny) {
    getSwiat()->usunOrganizm(this);
}