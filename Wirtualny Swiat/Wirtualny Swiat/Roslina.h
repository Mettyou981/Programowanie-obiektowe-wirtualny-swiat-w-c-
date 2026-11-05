#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
protected:
    double prawdRozsiania;

public:
    Roslina(int sila, int x, int y, Swiat* swiat, double prawdRozsiania);

    // Metody wymagane przez Organizm
    void akcja() override;
    void kolizja(Organizm* inny) override;

    // Metody czysto wirtualne (musz¹ byæ zaimplementowane przez klasy pochodne)
    virtual void rysowanie() const = 0;
    virtual std::string getNazwa() const = 0;
    virtual Organizm* stworzKopie(int x, int y) const = 0;
};