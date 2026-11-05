#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {
public:
    Zolw(int x, int y, Swiat* swiat);
    ~Zolw() = default;

    void akcja() override;
    bool odbijAtak(Organizm* atakujacy) const override;
    std::string getNazwa() const override;
    char getZnak() const override;
    Organizm* stworzKopie(int x, int y) const override;
};