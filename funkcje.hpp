#include <iostream>
using namespace std;



bool PrzeszukajDrzewo(Wezel* korzen, int kluczyk)
{
    if(korzen==nullptr) return false;
    if(korzen->zwrocKlucz()==kluczyk) return true;
    else if(kluczyk<korzen->zwrocKlucz())
    {
        return PrzeszukajDrzewo(korzen->zwrocLewegoSyna(),kluczyk);
    }
    else
    {
        return PrzeszukajDrzewo(korzen->zwrocPrawegoSyna(),kluczyk);
    }
}


void Preorder(Wezel* korzen)
{
    if(korzen==nullptr) return;
    cout << korzen->zwrocKlucz() << endl;
    Preorder(korzen->zwrocLewegoSyna());
    Preorder(korzen->zwrocPrawegoSyna());
}
void Inorder(Wezel* korzen)
{
    if(korzen==nullptr) return;
    Inorder(korzen->zwrocLewegoSyna());
    cout << korzen->zwrocKlucz() << endl;
    Inorder(korzen->zwrocPrawegoSyna());
}
void Postorder(Wezel* korzen)
{
    if(korzen==nullptr) return;
    Postorder(korzen->zwrocLewegoSyna());
    Postorder(korzen->zwrocPrawegoSyna());
    cout << korzen->zwrocKlucz() << endl;
}

int maks(int a, int b)
{
    if(a>b) return a;
    else return b;
}
int WyswietlWysokoscDrzewa(Wezel* korzen)
{
    if(korzen==nullptr)
    {
        return -1;
    }
    return maks(WyswietlWysokoscDrzewa(korzen->zwrocLewegoSyna()),WyswietlWysokoscDrzewa(korzen->zwrocPrawegoSyna()))+1;

}
int zwrocBalans(Wezel* korzen)
{
    return korzen->zwrocLewegoSyna()->zwrocWysokosc() - korzen->zwrocPrawegoSyna()->zwrocWysokosc();
}

Wezel *prawaRotacja(Wezel *wezel)
{

    Wezel *w1 = wezel->zwrocLewegoSyna();
    Wezel *w2 = w1->zwrocPrawegoSyna();

    w1->ustawPrawegoSyna(wezel);
    wezel->ustawLewegoSyna(w2);

    wezel->ustawWysokosc(maks(wezel->zwrocLewegoSyna()->zwrocWysokosc(), wezel->zwrocPrawegoSyna()->zwrocWysokosc())+1);
    w1->ustawWysokosc(maks(w1->zwrocLewegoSyna()->zwrocWysokosc(),w1->zwrocPrawegoSyna()->zwrocWysokosc())+1);

    return w1;
}

Wezel *lewaRotacja(Wezel *wezel)
{
    Wezel *w1 = wezel->zwrocPrawegoSyna();
    Wezel *w2 = w1->zwrocLewegoSyna();

    w1->ustawLewegoSyna(wezel);
    wezel->ustawPrawegoSyna(w2);

    wezel->ustawWysokosc(maks(wezel->zwrocLewegoSyna()->zwrocWysokosc(), wezel->zwrocPrawegoSyna()->zwrocWysokosc())+1);
    w1->ustawWysokosc(maks(w1->zwrocLewegoSyna()->zwrocWysokosc(),w1->zwrocPrawegoSyna()->zwrocWysokosc())+1);

    return w1;
}
