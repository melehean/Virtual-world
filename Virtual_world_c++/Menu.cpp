#include "Menu.h"
#include "CONST.h"
#include "Powiadomienia.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;


Menu::Menu(Konsola *moja_konsola)
{
	this->moja_konsola = moja_konsola;
}

Menu::~Menu()
{
}

void Menu::pobierz_rozmiar(pair<int,int>*rozmiar)
{
	int x, y;
	this->moja_konsola->gotoxy(POCZATEK_X, POCZATEK_Y);
	cout << "Podaj dlugosc i szerokosc planszy, zatwierdz enterem";
	this->moja_konsola->gotoxy(POCZATEK_X, POCZATEK_Y + ODS_Y);
	cin >> x >> y;
	rozmiar->first = x;
	rozmiar->second = y;
	moja_konsola->czysc();
}

void Menu::stworz_legende()
{
	this->moja_konsola->gotoxy(POCZATEK_X, POCZATEK_Y);
	this->moja_konsola->ustaw_biel_tla();
	cout << "  W  I  R  T  U  A  L  N  Y      S  W  I  A  T  ";
	int wspolrzedna_y = POCZATEK_MENU_Y;
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, wspolrzedna_y);
	cout << "Autor Michal Sieczczynski";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "nr indeksu 175989        ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	this->moja_konsola->wroc_do_normy();
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	this->moja_konsola->ustaw_biel_tla();
	cout << "         Legenda         ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "A - antylopa             ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "B - barszcz sosnowskiego ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "C - czlowiek             ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "G - guarana              ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "J - wilcze jagody        ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "L - lis                  ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "M - mlecz                ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "O - owca                 ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "T - trawa                ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "W - wilk                 ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "Z - zolw                 ";
}

void Menu::stworz_rozne(bool czy_moc, int tura)
{
	string pom = to_string(tura);
	int i = 0;
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, POCZATEK_ROZNE_Y);
	this->moja_konsola->ustaw_biel_tla();
	cout << "Tura: " << pom;
	while (pom.size() + i +6 < DL_LEGENDA)//+6 - dlugosc slowa "Tura: " 
	{
		cout << ' ';
		i++;
	}
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, POCZATEK_ROZNE_Y+1);
	if (czy_moc == true)cout << "Moc specjalna wlaczona   ";
	else cout << "Moc specjalna wylaczona  ";
}

void Menu::stworz_sterowanie()
{
	int wspolrzedna_y = POCZATEK_STEROWANIA_Y;
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, wspolrzedna_y);
	this->moja_konsola->ustaw_biel_tla();
	cout << "       Sterowanie        ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "Strzalki - poruszanie    ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "p - moc specjalna        ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "s - zapis do pliku       ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "r - wczytaj plik         ";
	this->moja_konsola->gotoxy(POCZATEK_MENU_X, ++wspolrzedna_y);
	cout << "q - opusc gre            ";
}

void Menu::smierc()
{
	this->moja_konsola->gotoxy(POCZATEK_KONCA_X, POCZATEK_KONCA_Y);
	this->moja_konsola->ustaw_biel_tla();
	cout << "CZLOWIEK UMARL - PRZYKRO MI :(";
}

void Menu::pobierz_nazwe_pliku_do_zapisu(string *nazwa)
{
	this->moja_konsola->czysc();
	string nazwa_pliku;
	this->moja_konsola->gotoxy(POCZATEK_X, POCZATEK_Y);
	cout << "Podaj nazwe pliku za zapisu, zatwierdz enterem";
	this->moja_konsola->gotoxy(POCZATEK_X, POCZATEK_Y + ODS_Y);
	cin >> nazwa_pliku;
	*nazwa = nazwa_pliku;
	this->moja_konsola->czysc();
}

void Menu::pobierz_nazwe_pliku_do_wczytania(string *nazwa)
{
	string nazwa_pliku;
	ifstream in;
	do
	{
		this->moja_konsola->czysc();
		this->moja_konsola->gotoxy(POCZATEK_X, POCZATEK_Y);
		cout << "Podaj nazwe pliku do wczytania, zatwierdz enterem";
		this->moja_konsola->gotoxy(POCZATEK_X, POCZATEK_Y + ODS_Y);
		cin >> nazwa_pliku;
		nazwa_pliku += ".txt";
		in.open(nazwa_pliku);
	} while (in.is_open() == false);
	in.close();
	*nazwa = nazwa_pliku;
	this->moja_konsola->czysc();
}

char Menu::stworz_menu()
{
	char kursor;
	int wspolrzedna_y = POCZATEK_Y;
	this->moja_konsola->gotoxy(POCZATEK_X, wspolrzedna_y);
	cout << "Witaj w grze Wirtualny Swiat!";
	wspolrzedna_y += ODS_Y;
	this->moja_konsola->gotoxy(POCZATEK_X, wspolrzedna_y);
	cout << "Nacisnij klawisz n, aby wybrac nowa gre";
	wspolrzedna_y += ODS_Y;
	this->moja_konsola->gotoxy(POCZATEK_X, wspolrzedna_y);
	cout << "Nacisnij klawisz r, aby wczytac gre";
	wspolrzedna_y += ODS_Y;
	this->moja_konsola->gotoxy(POCZATEK_X, wspolrzedna_y);
	cout << "Nacisnij inny, dowolny klawisz, aby opuscic gre";
	while (kursor = _getch())
	{
		if (kursor == NOWA_GRA || kursor == WCZYTAJ)
		{
			this->moja_konsola->czysc();
			return kursor;
		}
	}
}

void Menu::pobierz_rozmiar_z_pliku(pair<int, int> *rozmiar, string nazwa_pliku)
{
	pair<int, int>pom;
	ifstream in;
	in.open(nazwa_pliku);
	in >> pom.first >> pom.second;
	rozmiar->first = pom.first;
	rozmiar->second = pom.second;
	in.close();
}
