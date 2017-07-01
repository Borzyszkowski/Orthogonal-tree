//TP_2017_03_15
//Code::Blocks IDE 16.01
//=== TDM-GCC Compiler Suite for Windows ===
//---           GCC 4.9 Series           ---
//***   Standard MinGW 32-bit Edition    ***

//Jan Michalik 165420 AIR 1 ETI
//Bartlomiej Borzyszkowski 165561 AIR 1 ETI

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct wezel {
    int value;
    wezel *nastepny;    // wskaźnik na następny element
    wezel();
};

wezel::wezel() {
    nastepny = 0;
}

struct lista {
    wezel *pierwszy;  // wskaźnik na początek listy
    void dodaj_wartosc (int value);
    void wyswietl_liste ();
    lista();
};

lista::lista() {
    pierwszy = 0;
}

void lista::dodaj_wartosc(int value)
{
    wezel *nowa = new wezel;    // tworzy nowy element listy
    nowa->value = value;
    if (pierwszy==0) // sprawdzamy czy to pierwszy element listy
    {
        pierwszy = nowa;  // jeżeli tak to nowy element jest teraz początkiem listy
    }

    else  // w przeciwnym wypadku idziemy na koniec listy
    {
        wezel *temp = pierwszy;
        while (temp->nastepny)
        {
            temp = temp->nastepny;  // wskaźnik na ostatni element
        }
        temp->nastepny = nowa;  // ostatni element wskazuje na nowy
        nowa->nastepny = 0;
    }
}

void lista::wyswietl_liste()
{
srand(time(NULL));
wezel *temp = pierwszy;

    cout << temp->value << endl;
    temp=temp->nastepny;

while(temp)
{
    int p=rand()%6+1;
    int pomocnicza=1;
    int q=0;
    int z=rand()%2+1;
    for(int j=0; j<p; j++)
    {
            int n=rand()%3+1;
            for (int w=0; w<n; w++)
            {
                if(pomocnicza==1)
                {
                    if (j>0)
                    {
                    cout<<"|";
                    cout<<"    ";
                    }
                    if (j>1)
                    {
                        for (int m=1; m<q; m++){
                        cout<<"     ";}
                    }
                    cout<<"|"<<"----";
                    cout << temp->value << endl;
                    temp=temp->nastepny;
                    if(!temp)
                    exit (1);
                }
                if(pomocnicza==2)
                {
                    cout<<"|";
                    for (int m=0; m<1; m++){
                    cout<<"    ";}

                    if (w==0)
                    {
                        cout<<"|"<<"----";
                        cout << temp->value << endl;
                        temp=temp->nastepny;
                        if(!temp)
                        exit (1);
                        continue;
                    }
                    else
                    {
                        for (int m=1; m<2; m++){
                            cout<<"|";
                            cout<<"    ";}
                    }

                    cout<<"|"<<"----";
                    cout << temp->value << endl;
                    temp=temp->nastepny;
                    if(!temp)
                    exit (1);
                }
            }
        pomocnicza=z;
        q++;
    }
}
}
int main()
{
    lista *drzewo = new lista;    //tworzymy liste
    int ile;
    int wstawiany;
    cout<<"Techniki Programowania - PROJEKT 1. zad. 2. | Jan Michalik | Bartlomiej Borzyszkowski | AiR 1 ETI |"<<endl<<endl;
    cout<<"Witamy w programie generujacym ortogonalne drzewo liczbowe."<<endl;
    cout<<"Podaj ilosc liczb, ktore chcesz umiescic w drzewie: "<<endl;
    cin>>ile;
    cout<<"Podaj kolejne liczby: "<<endl;
    for (int i=0; i<ile; i++){
        cout<<i+1<<": ";
        cin>>wstawiany;
        drzewo->dodaj_wartosc(wstawiany);}

    cout<<"Podane liczby zostaly umieszczone w drzewie."<<endl;
    cout<<"Sa one powiazane na zasadzie listy sasiedztwa."<<endl;
    cout<<"Uklad drzewa jest za kazdym razem losowy."<<endl;
    cout<<endl<<"Ortogonalna wizualizacja drzewa wyglada nastepujaco: "<<endl<<endl;

    drzewo->wyswietl_liste();

    delete (drzewo);

    return 0;
}
