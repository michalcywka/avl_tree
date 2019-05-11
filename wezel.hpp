#include <iostream>
using namespace std;

class Wezel
{
    Wezel *lewy_syn;
    Wezel *prawy_syn;
    int klucz;
    int wysokosc;

    public:
    Wezel(int kluczyk,Wezel* synekL, Wezel* synekP);
    int zwrocKlucz();
    int zwrocWysokosc();
    Wezel* zwrocLewegoSyna();
    Wezel* zwrocPrawegoSyna();
    void ustawKlucz(int kluczyk);
    void ustawWysokosc(int wysokosci);
    void ustawLewegoSyna(Wezel* synek);
    void ustawPrawegoSyna(Wezel* synek);
};

Wezel::Wezel(int kluczyk,Wezel* synekL, Wezel* synekP)
{
    this->lewy_syn=synekL;
    this->prawy_syn=synekP;
    this->klucz=kluczyk;
}

int Wezel::zwrocKlucz()
{
    return this->klucz;
}

int Wezel::zwrocWysokosc()
{

    if(this==nullptr) return 0;
    else return this->wysokosc;
}

Wezel* Wezel::zwrocLewegoSyna()
{
    return this->lewy_syn;
}

Wezel* Wezel::zwrocPrawegoSyna()
{
    return this->prawy_syn;
}
void Wezel::ustawKlucz(int kluczyk)
{
    this->klucz=kluczyk;
}

void Wezel::ustawWysokosc(int wysokosci)
{
    this->wysokosc=wysokosci;
}

void Wezel::ustawLewegoSyna(Wezel* synek)
{
    this->lewy_syn=synek;
}
void Wezel::ustawPrawegoSyna(Wezel* synek)
{
    this->prawy_syn=synek;
}

