#pragma once
#include "Roslina.h"

class BarszczSosnowskiego : public Roslina {
public:
    BarszczSosnowskiego(int x, int y, Swiat* swiat);
    ~BarszczSosnowskiego() = default;

    void akcja() override;
    void kolizja(Organizm* inny) override;
    std::string getNazwa() const override;
    char getZnak() const override;
    Organizm* stworzKopie(int x, int y) const override;
    void rysowanie() const override; // Dodana brakuj¹ca metoda
};