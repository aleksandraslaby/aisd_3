#include <iostream>
#include <fstream>
#include <cstdlib>

 // LISTA JEDNOKIERUNKOWA
 // ALEKSANDRA SLABY
 // 169840, 1FS-DI

using namespace std;


struct USOS //lista USOS ktorej elementami beda indeksy studentow
    {
    int indeks; //indeks każdego studenta zawiera się w zakresie wartości int
    USOS *nastepny; // wskaznik na nastepny element na liscie

    USOS(); // konstruktor do wywolywania przy tworzeniu listy


 USOS(int indeks)
    {
        this->indeks = indeks;
        nastepny = NULL;
    }

void wypisz() //funkcja wypisujaca element z listy, zostanie użyta pozniej
    {
    cout << "Numer indeksu: " << indeks << endl;
    }
    };

    //WYSZUKIWANIE ELEMENTOW
void wyszukiwanie(USOS *glowa, int student) //wyszukiwanie konkretnego indeksu studenta
{
    while(glowa != NULL && (glowa->indeks)!=student) // petla wykonuje sie dopoki nie znajdziemy konta z podanym indeksem lub nie przeszukamy calej listy
        {
        glowa = glowa->nastepny;
        }
        if (glowa == NULL) //gdy dojdziemy do konca, a indeksu nie ma to wyswietlamy komunikat
            cout << "Student o takim indeksie nie istnieje. Sprawdz poprawnosc indeksu i sprobuj ponownie. "  << endl;
        else
            glowa->wypisz();
}

    //WYSWIETLANIE CALEJ LISTY
void wyswietlanie(USOS *glowa) //wyswietlamy liste elementow
    {
    cout << "Lista studentow :"<< endl;

    while(glowa != NULL) //dopoki nie dojdziemy do konca
        {
        glowa->wypisz(); // wypisanie konta
        glowa = glowa->nastepny; // przejscie na kolejny element
        }
    }

    //USUWANIE PODANEGO ELEMENTU
bool usuwanie_zadanego(USOS **glowa, int student) //usuwanie studenta o podanym indeksie
{
    if ((*glowa) == NULL) //najpierw sprawdzamy czy na liscie mamy jakiekolwiek elementy
    return false;

    USOS *temp = (*glowa), *temp2 = NULL; //wskazniki do sprawdzania listy

        while(temp != NULL && (temp->indeks)!=student) // dopoki nie znajdziemy konta USOS z podanym indeksem lub nie przeszukamy calego USOSA
            {
            temp2 = temp;
            temp = temp->nastepny;
            }

    if (temp == NULL) //jesli doszlismy do konca a indeksu nie ma zwracamy false
    return false;

        else if (temp == (*glowa))
        {
        (*glowa) = (*glowa)->nastepny;
        delete temp;
        }
            else
            {
            temp2->nastepny = temp->nastepny;
            delete temp;
            }
        return true;
}

    //DODAWANIE ELEMENTU NA KONIEC LISTY
void na_koniec(USOS *&glowa, int nowy_indeks) //dodawanie na koniec
{
    USOS *nowa = new USOS(nowy_indeks);    // tworzy nowy element listy
    nowa->indeks = nowy_indeks;

    if (glowa==0) // sprawdzamy czy to pierwszy element listy
    {
        // jeżeli tak to nowy element jest teraz początkiem listy
        glowa = nowa;
    }
        else
        {
        // w przeciwnym wypadku wędrujemy na koniec listy
        USOS *temp = glowa;

            while (temp->nastepny)
            {            // znajdujemy wskaźnik na ostatni element
                temp = temp->nastepny;
            }

        temp->nastepny = nowa;  // ostatni element wskazuje na nasz nowy


        }
}

    //DODAWANIE ELEMENTU NA POCZATEK LISTY
void na_poczatek(USOS **glowa, int nowy_indeks) //dodawanie na poczatek
{

    USOS *nowa = new USOS(nowy_indeks); //nowy element

    nowa->nastepny = (*glowa);

    (*glowa) = nowa; //dodaj na poczatek (glowa)
}


    //RESETOWANIE CALEJ LISTY
void reset(USOS *&glowa) //usuwamy całą listę
{
    USOS *nowa;
    while (glowa != NULL) //dopoki lista nie bedzie pusta usuwamy elementy
    {
        nowa = glowa;
        glowa = nowa->nastepny;
        delete nowa;
    }
}

    //ZLICZANIE WSZYSTKICH ELEMENTOW
void zliczanie(USOS *glowa)
{
    USOS *temp;
    int licznik = 0; //poczatkowy licznik ustawiamy na zero

     temp = glowa;

        while(temp != NULL) //dopoki nie przejdziemy przez wszystkie elementy to zwiekszamy licznik
        {
            licznik++;
            temp = temp->nastepny;
        }

    cout<< "Liczba elementow listy: " << licznik << endl;
}

//FUNKCJA WYPISUJACA DO PLIKU
void drukowanie(USOS *glowa)

{
    ofstream wynik;
       wynik.open("lista.txt");

	while (glowa != NULL) {
		wynik << glowa->indeks<<endl;

		glowa = glowa->nastepny;
	}
}

//ODCZYT CZESCI DANYCH Z PLIKU
void wczytywanie(USOS * & glowa)
{
    USOS * nowa, * ostatni;
    ostatni = nowa = NULL;

    ifstream plik;
    plik.open("dane.txt");

    int indeksWczytywany;

        while (!plik.eof())
            {
            plik >> indeksWczytywany;

            ostatni = nowa;
            nowa = new USOS(indeksWczytywany);

            nowa -> nastepny = NULL;
            if (ostatni == NULL)
                glowa = nowa;
            else
            ostatni -> nastepny = nowa;

            }
}


    int main()
    {
    char opcja;
    int indeks;
    USOS *glowa = NULL; // glowa listy - wskaznik na pierwszy element

    wczytywanie(glowa);

        cout << "Witaj w systemie USOS! Wybierz, co chcesz zrobic: "<<endl;
        cout << "'1' jesli chcesz dodac studenta do USOSA na poczatek listy"<<endl;
        cout << "'2' jesli chcesz dodac studenta na koniec listy"<<endl;
        cout << "'3' jesli chcesz wypisac liste indeksow znajdujaca sie w USOSie"<<endl;
        cout << "'4' jesli chcesz wyszukac konkretnego studenta po jego indeksie"<<endl;
        cout << "'5' jesli chcesz zresetowac cala liste. Operacji nie da sie cofnac"<<endl;
        cout << "'6' jesli chcesz usunac studenta z USOSA"<<endl;
        cout << "'7' jesli chcesz poznac ilosc elementow na liscie"<<endl;
        cout << "'X' jesi chcesz zakonczyc program"<<endl;
        cout << "W razie pytan technicznych prosimy o kontakt na maila 169840@stud.prz.edu.pl "<<endl;


while (cin >> opcja)
{
    switch (opcja)
    {
        case '1':
        cout<< "Podaj indeks: "<< endl;
        cin >> indeks;
        na_poczatek(&glowa, indeks);
        drukowanie(glowa);
        break;

            case '2':
            cout<<"Podaj indeks: "<< endl;
            cin >> indeks;
            na_koniec(glowa, indeks);
            drukowanie(glowa);
            break;

        case '3': wyswietlanie(glowa);
        break;

            case '4':
            cout << "Podaj indeks: ";
            cin >> indeks;
            wyszukiwanie(glowa, indeks);
            break;

        case '5': reset(glowa);
        cout<< "Zresetowano liste studentow." << endl;
        drukowanie(glowa);
        break;

            case '6':
            cout << "Podaj indeks: ";
            cin >> indeks;
            if (!usuwanie_zadanego(&glowa, indeks))
            cout << "Nie odnaleziono studenta z podanym indeksem" << endl;
            else
             drukowanie(glowa);
            cout << "Konto USOS z podanym indeksem zostalo usuniete" << endl;
            break;

        case '7': zliczanie(glowa);
        break;

            case 'X':
            return 0;
            break;

        default:
        cout << "Komunikat nie jest jasny. Sprobuj ponownie."<<endl;
        break;


    }
}
return 0;
}
