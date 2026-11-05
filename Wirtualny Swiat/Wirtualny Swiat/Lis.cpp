#include "Lis.h"
#include <vector>
#include <random>
#include <utility>
#include "Swiat.h"

Lis::Lis(int x, int y, Swiat* swiat)
    : Zwierze(3, 7, x, y, swiat) {
}

void Lis::akcja() {
    std::vector<std::pair<int, int>> mozliweRuchy;
    int x = getPozycja().first;
    int y = getPozycja().second;

    // SprawdŸ tylko 4 kierunki (góra, dó³, lewo, prawo)
    const int dx[] = { 0, 0, -1, 1 };
    const int dy[] = { -1, 1, 0, 0 };

    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newX < getSwiat()->getSzerokosc() &&
            newY >= 0 && newY < getSwiat()->getWysokosc()) {
            Organizm* org = getSwiat()->znajdzOrganizm(newX, newY);
            if (org == nullptr || org->getSila() <= getSila()) {
                mozliweRuchy.emplace_back(dx[i], dy[i]);
            }
        }
    }

    if (!mozliweRuchy.empty()) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, mozliweRuchy.size() - 1);
        auto ruch = mozliweRuchy[dis(gen)];
        this->ruch(ruch.first, ruch.second);
    }
}

std::string Lis::getNazwa() const {
    return "Lis";
}

char Lis::getZnak() const {
    return 'L';
}

Organizm* Lis::stworzKopie(int x, int y) const {
    return new Lis(x, y, getSwiat());
}