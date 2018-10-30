#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

void pobierzLinieIZapiszDoWektora (vector <string> &adresaci, string nazwaPliku)
{
    string imie, nazwisko, nr_tel, id, adres, email, adresat;

    string linia;
    int nr_linii=1;

    fstream plik;

    plik.open(nazwaPliku.c_str(), ios::in);

    if(plik.good()==false)
        cout<<"Nie mozna otworzyc pliku!";

    while (getline(plik, linia))
    {
        switch (nr_linii)
        {
        case 1:
            id=linia;
            break;
        case 2:
            imie=linia;
            break;
        case 3:
            nazwisko=linia;
            break;
        case 4:
            nr_tel=linia;
            break;
        case 5:
            adres= linia;
            break;
        case 6:
            email = linia;
            break;
        }
        nr_linii++;
        if (nr_linii> 6)
        {
            adresat = id + '|' + imie + '|' + nazwisko + '|' + nr_tel + '|' + adres + '|' + email + '|';
            adresaci.push_back(adresat);

            nr_linii = 1;
        }
    }
    plik.close();
}

void przeslijDaneDoPliku (vector <string> &adresaci, string nazwaPliku)
{
    fstream plik;
    string nazwaNowegoPliku = nazwaPliku  + "_nowy_format.txt";
    plik.open(nazwaNowegoPliku.c_str(),ios::out | ios::app);

    for (int i =0; i<adresaci.size(); i++)
    {
        plik << adresaci[i] << endl;
    }
    plik.close();

    cout << "Dane z pliku " << nazwaPliku << " zostaly przekonwertowane i zapisane do pliku " << nazwaNowegoPliku << endl;
}
int main()
{
    vector <string> adresaci;
    string nazwaPliku;
    cout << "Podaj nazwe pliku, ktory chcesz konwertowac: " << endl;
    cin >> nazwaPliku;

    pobierzLinieIZapiszDoWektora(adresaci, nazwaPliku);
    przeslijDaneDoPliku(adresaci, nazwaPliku);

    return 0;
}
