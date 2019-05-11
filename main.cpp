
#include <iostream>

#ifndef WEZEL_HPP_
#include "wezel.hpp"
#endif // WEZEL_HPP_

#ifndef DRZEWO_HPP_
#include "drzewo.hpp"
#endif // DRZEWO_HPP_



int main()
{

    int opcja;
    int pomocnik;

    Wezel* korzenWskaznik;
    korzenWskaznik=nullptr;

    korzenWskaznik=DodajSyna(korzenWskaznik,9);
    korzenWskaznik=DodajSyna(korzenWskaznik,5);
    korzenWskaznik=DodajSyna(korzenWskaznik,10);
    korzenWskaznik=DodajSyna(korzenWskaznik,0);
    korzenWskaznik=DodajSyna(korzenWskaznik,6);
    korzenWskaznik=DodajSyna(korzenWskaznik,11);
    korzenWskaznik=DodajSyna(korzenWskaznik,-1);
    korzenWskaznik=DodajSyna(korzenWskaznik,1);
    korzenWskaznik=DodajSyna(korzenWskaznik,2);


    //Preorder(korzenWskaznik);

    /*korzenWskaznik=Usun(korzenWskaznik, 10);
     korzenWskaznik=Usun(korzenWskaznik, 2);
      korzenWskaznik=Usun(korzenWskaznik, 6);
    cout<<"Po usunieciu:"<<endl;*/
    //Preorder(korzenWskaznik);


    while(opcja!=0)
    {
        cout << endl;
        cout << "Wybierz opcje:" <<endl;
        cout << "1. Dodaj element do drzewa" <<endl;
        cout << "2. Usun element z drzewa" <<endl;
        cout << "3. Wyswietl korzen drzewa" <<endl;
        cout << "4. Wyswietl wysokosc drzewa" <<endl;
        cout << "5. Przejscie preorder" <<endl;
        cout << "6. Przejscie inorder" <<endl;
        cout << "7. Przejscie postorder" <<endl;
        cout << "0. Zamknij program" <<endl;
        cout << endl;
        cin >> opcja;
        switch(opcja)
        {
        case 1:
            cout << "Prosze podac ilosc elementow, ktore chcesz dodac" << endl;
            int ilosc;
            cin >> ilosc;
            while(ilosc>0)
            {
                cout << "Prosze podac klucz, ktore chcesz dodac" << endl;
                cin >> pomocnik;
                if(PrzeszukajDrzewo(korzenWskaznik, pomocnik))
                    cout << "Klucz juz istnieje, prosze podac inny" << endl;
                else
                        {
                        korzenWskaznik=DodajSyna(korzenWskaznik,pomocnik);
                        ilosc--;
                        }
            }
            break;
        case 2:
            cout << "Prosze podac klucz, ktore chcesz usunac" << endl;
            cin >> pomocnik;
            if(!PrzeszukajDrzewo(korzenWskaznik, pomocnik))
                    cout << "Klucz nie istnieje, prosze podac inny" << endl;
                else
                        {
                        korzenWskaznik=Usun(korzenWskaznik,pomocnik);
                        }
            break;

        case 3:
            cout << "Korzeniem jest klucz:" << endl;
            cout << korzenWskaznik->zwrocKlucz()<<endl;
            break;
        case 4:
            cout << "Wysokosc drzewa:" << endl;
            cout << WyswietlWysokoscDrzewa(korzenWskaznik) << endl;
            break;
        case 5:
            cout << "Przejscie preorder:" << endl;
            Preorder(korzenWskaznik);
            break;
        case 6:
            cout << "Przejscie inorder: "<< endl;
            Inorder(korzenWskaznik);
            break;
        case 7:
            cout << "Przejscie postorder:" << endl;
            Postorder(korzenWskaznik);
            break;
        }

    }
    return 0;
}

