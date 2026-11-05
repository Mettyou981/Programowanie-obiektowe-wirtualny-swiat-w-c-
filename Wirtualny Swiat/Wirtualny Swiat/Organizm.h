#pragma once
#include <utility>
#include <string>
#include <stdexcept>

class Swiat;

class Organizm {
protected:
    int sila;
    int inicjatywa;
    std::pair<int, int> pozycja;
    std::pair<int, int> poprzedniaPozycja; // Dodane
    int wiek;
    Swiat* swiat;

public:
    Organizm(int sila, int inicjatywa, int x, int y, Swiat* swiat);
    virtual ~Organizm() = default;

    // Metody wirtualne
    virtual void akcja() = 0;
    virtual void kolizja(Organizm* inny) = 0;
    virtual void rysowanie() const = 0;
    virtual std::string getNazwa() const = 0;
    virtual char getZnak() const = 0;
    virtual void cofnijRuch(); // Dodane

    // Gettery i settery
    int getSila() const;
    int getInicjatywa() const;
    int getWiek() const;
    std::pair<int, int> getPozycja() const;
    Swiat* getSwiat() const;
    void setPozycja(int x, int y);
    void setSila(int sila);
    void postarz();

    // Metody specjalne
    virtual bool czyOdbilAtak(Organizm* atakujacy) const;
    virtual bool czyUciekl() const;
    virtual bool czyZasieg() const;
    virtual bool czyUmnoroz() const;
};