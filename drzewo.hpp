#include <iostream>
using namespace std;
#ifndef FUNKCJE_HPP_
#include "funkcje.hpp"
#endif // FUNKCJE_HPP_

Wezel *StworzNowyWezel(int kluczyk)
{
    Wezel *nowyWezel= new Wezel(kluczyk,nullptr,nullptr);
    nowyWezel->ustawWysokosc(1);
    return nowyWezel;
}
Wezel *DodajSyna(Wezel *korzen, int kluczyk)
{
    if(korzen==nullptr)
    {
        korzen=StworzNowyWezel(kluczyk);
        return korzen;
    }

    else if(kluczyk<korzen->zwrocKlucz())
    {
        korzen->ustawLewegoSyna(DodajSyna(korzen->zwrocLewegoSyna(),kluczyk));
    }
    else if(kluczyk>korzen->zwrocKlucz())
    {
        korzen->ustawPrawegoSyna(DodajSyna(korzen->zwrocPrawegoSyna(),kluczyk));
    }
    else //klucze nie moga byc sobie rowne
        return korzen;

    //korzen->ustawWysokosc(1+maks(korzen->zwrocPrawegoSyna()->,korzen->zwrocLewegoSyna()->zwrocWysokosc()));
    korzen->ustawWysokosc((maks(korzen->zwrocPrawegoSyna()->zwrocWysokosc(),korzen->zwrocLewegoSyna()->zwrocWysokosc()))+1);

    int balans = zwrocBalans(korzen);

   if(balans>1 && kluczyk<korzen->zwrocLewegoSyna()->zwrocKlucz())
        return prawaRotacja(korzen);

    if(balans<-1 && kluczyk>korzen->zwrocPrawegoSyna()->zwrocKlucz())
        return lewaRotacja(korzen);

    if(balans>1 && kluczyk>korzen->zwrocLewegoSyna()->zwrocKlucz())
       {
           korzen->ustawLewegoSyna(lewaRotacja(korzen->zwrocLewegoSyna()));
         return prawaRotacja(korzen);
       }

       if(balans<-1 && kluczyk<korzen->zwrocPrawegoSyna()->zwrocKlucz())
       {
           korzen->ustawPrawegoSyna(prawaRotacja(korzen->zwrocPrawegoSyna()));
         return lewaRotacja(korzen);
       }
       return korzen;


}
Wezel* ZnajdzNajmniejszy(Wezel* korzen)
{
    while(korzen->zwrocLewegoSyna()!=nullptr) korzen=korzen->zwrocLewegoSyna();
    return korzen;

}
Wezel *Usun(Wezel *korzen,int kluczyk)
{

    if(korzen==nullptr) return korzen;
    else if(kluczyk<korzen->zwrocKlucz())
    {
        korzen->ustawLewegoSyna(Usun(korzen->zwrocLewegoSyna(),kluczyk));
    }
    else if(kluczyk>korzen->zwrocKlucz())
    {
        korzen->ustawPrawegoSyna(Usun(korzen->zwrocPrawegoSyna(),kluczyk));
    }
    else
    {
        if(korzen->zwrocLewegoSyna()==nullptr || korzen->zwrocPrawegoSyna()==nullptr  )
        {
            Wezel *tymczasowy=korzen->zwrocLewegoSyna()?korzen->zwrocLewegoSyna():korzen->zwrocPrawegoSyna();
            if(tymczasowy==nullptr)
            {
                tymczasowy=korzen;
                korzen=nullptr;
            }
            else *korzen=*tymczasowy;
            delete tymczasowy;
        }
        else
        {
            Wezel *tymczasowy=ZnajdzNajmniejszy(korzen->zwrocPrawegoSyna());
            korzen->ustawKlucz(tymczasowy->zwrocKlucz());

            korzen->ustawPrawegoSyna(Usun(korzen->zwrocPrawegoSyna(),tymczasowy->zwrocKlucz()));
        }
        }
    if(korzen==nullptr)
        return korzen;

    korzen->ustawWysokosc((maks(korzen->zwrocPrawegoSyna()->zwrocWysokosc(),korzen->zwrocLewegoSyna()->zwrocWysokosc()))+1);
    int balans = zwrocBalans(korzen);


   if(balans>1 && zwrocBalans(korzen->zwrocLewegoSyna())>=0)
        return prawaRotacja(korzen);

    if(balans<-1 && zwrocBalans(korzen->zwrocPrawegoSyna())<=0)
        return lewaRotacja(korzen);

    if(balans>1 && zwrocBalans(korzen->zwrocLewegoSyna())<0)
       {
           korzen->ustawLewegoSyna(lewaRotacja(korzen->zwrocLewegoSyna()));
         return prawaRotacja(korzen);
       }

       if(balans<-1 && zwrocBalans(korzen->zwrocPrawegoSyna())>0)
       {
           korzen->ustawPrawegoSyna(prawaRotacja(korzen->zwrocPrawegoSyna()));
         return lewaRotacja(korzen);
       }
       return korzen;

}


