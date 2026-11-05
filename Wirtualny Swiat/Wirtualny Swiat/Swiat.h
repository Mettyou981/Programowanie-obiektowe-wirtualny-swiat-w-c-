#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Organizm.h"
#include "Czlowiek.h"

class Swiat {
private:
    int szerokosc;
    int wysokosc;
    int tura;
    std::vector<Organizm*> organizmy;
    std::vector<std::string> zdarzenia;
    Czlowiek* czlowiek;

    void sortujOrganizmy();
    void losujPozycje(int& x, int& y) const;

public:
    Swiat(int szerokosc, int wysokosc);
    ~Swiat();

    void wykonajTure();
    void rysujSwiat() const;
    void inicjalizujSwiat();

    void dodajOrganizm(Organizm* organizm);
    void usunOrganizm(Organizm* organizm);
    void wyczyscZdarzenia();
    void dodajZdarzenie(const std::string& zdarzenie);

    Organizm* znajdzOrganizm(int x, int y) const;
    bool czyWGranicach(int x, int y) const;
    bool czyWolnePole(int x, int y) const;

    int getSzerokosc() const { return szerokosc; }
    int getWysokosc() const { return wysokosc; }
    int getTura() const { return tura; }
    Czlowiek* getCzlowiek() const { return czlowiek; }

    Swiat(const Swiat&) = delete;
    Swiat& operator=(const Swiat&) = delete;
};