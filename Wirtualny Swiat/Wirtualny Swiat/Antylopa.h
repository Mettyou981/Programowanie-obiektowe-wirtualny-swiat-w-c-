#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
    Antylopa(int x, int y, Swiat* swiat);
    ~Antylopa() = default;

    void akcja() override;
    bool czyUcieka(Organizm* atakujacy) override;
    std::string getNazwa() const override;
    char getZnak() const override;
    Organizm* stworzKopie(int x, int y) const override;
};