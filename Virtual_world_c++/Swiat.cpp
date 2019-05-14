#include "Swiat.h"
#include "Czlowiek.h"
#include "Owca.h"
#include "Antylopa.h"
#include "Barszcz_sosnowskiego.h"
#include "Guarana.h"
#include "Lis.h"
#include "Wilk.h"
#include "Wilcza_jagoda.h"
#include "Zolw.h"
#include "Trawa.h"
#include "Mlecz.h"
#include <conio.h>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;


Swiat::Swiat(pair<int,int> rozmiar, Konsola *moja_konsola, Menu *moje_menu) :rozmiar(rozmiar)
{
	this->moja_konsola = moja_konsola;
	this->moje_menu = moje_menu;
	this->moje_powiadomienia = new Powiadomienia(this->moja_konsola);
	this->tura = 0;
	int i,j;
	this->plansza = new Organizmy**[this->rozmiar.second];
	for (i = 0; i < this->rozmiar.second; i++)
		this->plansza[i] = new Organizmy*[this->rozmiar.first];	

	for (i = 0; i < this->rozmiar.second; i++)
		for (j = 0; j < this->rozmiar.first; j++)
			this->plansza[i][j] = NULL;
}



Swiat::~Swiat()
{

}

void Swiat::rysuj_swiat()
{
	this->moja_konsola->wroc_do_normy();
	this->moja_konsola->czysc();
	this->moja_konsola->ustaw_biel_tla();	
	int wspolrzedna_y = POCZATEK_PLANSZY_Y;
	this->moja_konsola->gotoxy(POCZATEK_PLANSZY_X, wspolrzedna_y);
	for (int i = 0; i < this->rozmiar.second; i++)
	{
		for (int j = 0; j < this->rozmiar.first; j++)
		{
			if(this->plansza[i][j]==NULL)_putch(' ');
			else
			{
				this->moja_konsola->ustaw_kolor(plansza[i][j]->get_kolor());
				cout << plansza[i][j]->get_symbol();
				this->moja_konsola->wroc_do_normy();
			}
			this->moja_konsola->ustaw_biel_tla();
		}
		this->moja_konsola->gotoxy(POCZATEK_PLANSZY_X, ++wspolrzedna_y);
	}
	this->moja_konsola->wroc_do_normy();
	this->moje_menu->stworz_legende();
	this->moje_menu->stworz_rozne(czlowiek->get_czy_moc(), this->tura);
	this->moje_menu->stworz_sterowanie();
	if (czlowiek == NULL)this->moje_menu->smierc();
	moje_powiadomienia->stworz_komunikaty();
}

bool Swiat::poza_tablice(pair<int, int>wspolrzedne)
{
	if (wspolrzedne.first < 0 || wspolrzedne.second < 0 || wspolrzedne.first >= rozmiar.first || wspolrzedne.second >= rozmiar.second)
		return true;
	return false;
}

bool Swiat::ruch_zwyciescy(pair<int,int>wspolrzedne, int sila)
{
	if ((!poza_tablice(wspolrzedne) 
		&& (plansza[wspolrzedne.second][wspolrzedne.first] == NULL 
			|| (plansza[wspolrzedne.second][wspolrzedne.first] != NULL 
				&& plansza[wspolrzedne.second][wspolrzedne.first]->get_sila() <= sila))))
		return true;
	return false;
}

bool Swiat::puste_miejsce(pair<int, int>wspolrzedne)
{
	if (!(poza_tablice(wspolrzedne)) && plansza[wspolrzedne.second][wspolrzedne.first] == NULL)return true;
	return false;
}

void Swiat::przekaz_powiadomienie(pair<char, char>czlony, powiadomienia_obopulne wybor)
{
	moje_powiadomienia->powiadomienia(czlony, wybor);
}
void Swiat::przekaz_powiadomienie(char czlon, powiadomienia_pojedyncze wybor)
{
	moje_powiadomienia->powiadomienia(czlon, wybor);
}

void Swiat::dodaj_organizm(pair<int,int>polozenie, char wybor)
{
	switch (wybor)
	{
	case 'C':
		plansza[polozenie.second][polozenie.first] = new Czlowiek(*this, polozenie.first,polozenie.second);
		break;
	case 'W':
		plansza[polozenie.second][polozenie.first] = new Wilk(*this, polozenie.first, polozenie.second);
		break;
	case 'O':
		plansza[polozenie.second][polozenie.first] = new Owca(*this, polozenie.first, polozenie.second);
		break;
	case 'L':
		plansza[polozenie.second][polozenie.first] = new Lis(*this, polozenie.first, polozenie.second);
		break;
	case 'Z':
		plansza[polozenie.second][polozenie.first] = new Zolw(*this, polozenie.first, polozenie.second);
		break;
	case 'A':
		plansza[polozenie.second][polozenie.first] = new Antylopa(*this, polozenie.first, polozenie.second);
		break;
	case 'T':
		plansza[polozenie.second][polozenie.first] = new Trawa(*this, polozenie.first, polozenie.second);
		break;
	case 'M':
		plansza[polozenie.second][polozenie.first] = new Mlecz(*this, polozenie.first, polozenie.second);
		break;
	case 'G':
		plansza[polozenie.second][polozenie.first] = new Guarana(*this, polozenie.first, polozenie.second);
		break;
	case 'J':
		plansza[polozenie.second][polozenie.first] = new Wilcza_jagoda(*this, polozenie.first, polozenie.second);
		break;
	case 'B':
		plansza[polozenie.second][polozenie.first] = new Barszcz_sosnowskiego(*this, polozenie.first, polozenie.second);
		break;
	}
	ruch.push_back(plansza[polozenie.second][polozenie.first]);
	przekaz_powiadomienie(plansza[polozenie.second][polozenie.first]->get_symbol(), NARODZINY);
}

bool Swiat::porownaj( Organizmy * a,  Organizmy * b)
{
	if (a->get_inicjatywa() == b->get_inicjatywa())
		return a->get_wiek() > b->get_wiek();
	return a->get_inicjatywa() > b->get_inicjatywa();
}

void Swiat::wykonaj_ture()
{
	sort(ruch.begin(), ruch.end(), porownaj);
	this->tura++;
	this->rozmiar_ruchu = ruch.size();
	for (iterator_organizmow = 0; iterator_organizmow < rozmiar_ruchu; iterator_organizmow++)
		this->ruch[iterator_organizmow]->akcja();
	for (iterator_organizmow = 0; iterator_organizmow < rozmiar_ruchu; iterator_organizmow++)
		this->ruch[iterator_organizmow]->postarz_organizm();
	this->rysuj_swiat();
}

void Swiat::wykonaj_ruch(pair<int, int> wspolrzedne_obecne, pair<int, int>wspolrzedne_nowe)
{
	if (plansza[wspolrzedne_nowe.second][wspolrzedne_nowe.first] == NULL)
	{
		plansza[wspolrzedne_nowe.second][wspolrzedne_nowe.first] = plansza[wspolrzedne_obecne.second][wspolrzedne_obecne.first];
		plansza[wspolrzedne_obecne.second][wspolrzedne_obecne.first]=NULL;
		if(plansza[wspolrzedne_nowe.second][wspolrzedne_nowe.first]!=NULL)plansza[wspolrzedne_nowe.second][wspolrzedne_nowe.first]->set_polozenie(wspolrzedne_nowe);
	}
	else
	{
		if(plansza[wspolrzedne_obecne.second][wspolrzedne_obecne.first]!=NULL)
			plansza[wspolrzedne_obecne.second][wspolrzedne_obecne.first]->kolizja(plansza[wspolrzedne_nowe.second][wspolrzedne_nowe.first]);
	}
}

void Swiat::usun_organizm(Organizmy& organizm)
{
	if (czlowiek->czy_czlowiek(&organizm) == true)czlowiek = NULL;
	for (int i = 0; i < ruch.size(); i++)
		if (&organizm == ruch[i])
		{
			ruch.erase(ruch.begin() + i); //usuwanie zjedzonego organizmu z kolejki
			if (this->rozmiar_ruchu > i) //jesli zjedzone zostalo dziecko narodzone w tej turze to rozmiar vectora sie nie zmienia
				this->rozmiar_ruchu--;
			if (iterator_organizmow >= i) //jesli zjedzony organizm jest wczesniej w kolejce to vector sie spisuje do tylu wiec i wskaznik trzeba przesunac
				iterator_organizmow--;
			break;
		}
	plansza[organizm.get_polozenie().second][organizm.get_polozenie().first] = NULL;
	delete &organizm;
}

void Swiat::usun_organizm(pair<int, int>wspolrzedne)
{
	if (czlowiek->czy_czlowiek(plansza[wspolrzedne.second][wspolrzedne.first]) == true)czlowiek = NULL;
	for (int i = 0; i < ruch.size(); i++)
		if (plansza[wspolrzedne.second][wspolrzedne.first] == ruch[i])
		{
			ruch.erase(ruch.begin() + i); //usuwanie zjedzonego organizmu z vectora
			if (this->rozmiar_ruchu > i) //jesli zjedzone zostalo dziecko narodzone w tej turze to rozmiar vectora sie nie zmienia
				this->rozmiar_ruchu--;
			if (iterator_organizmow >= i) //vector sie spisuje do tylu wiec iterator trzeba przesunac
				iterator_organizmow--;
			break;
		}
	plansza[wspolrzedne.second][wspolrzedne.first] = NULL;
}

void Swiat::zmien_na_planszy(pair<int, int>obecne, pair<int, int>nowe)
{
	plansza[nowe.second][nowe.first] = plansza[obecne.second][obecne.first];
	plansza[obecne.second][obecne.first] = NULL;
	if(plansza[nowe.second][nowe.first]!=NULL)plansza[nowe.second][nowe.first]->set_polozenie(nowe);
}

void Swiat::start(moment_wczytania wybor, string nazwa)
{
	char znak;
	if (wybor == W_TRAKCIE)//jezeli zaczynamy nowa rozgrywke, czyli juz nie mozna wczytac przed rozgrywka
	{
		this->dodaj_poczatkowe_organizmy();
		this->rysuj_swiat();
	}
	else this->wczytaj_swiat(PRZED, nazwa);//jezeli wczytujemy na poczatku rozgrywki
	while (czlowiek != NULL)
	{
		znak = this->czytaj_znak(czlowiek->get_polozenie());
		if (znak == OPUSC_GRE)return;
		else if(znak!=NIE_DOTYCZY)czlowiek->set_kursor(znak);
		this->wykonaj_ture();
	}
	while (true)
	{
		kursor = _getch();
		if (kursor == OPUSC_GRE)return;
	}
}

void Swiat::dodaj_poczatkowe_organizmy()
{
	//jezeli byloby mniej niz 10x10 to nie pojawilyby sie zwierzeta na plaszy, gdyby nie warunek i ustawienie na 1
	int wspolczynnik = this->rozmiar.first*this->rozmiar.second < 100 ? 1 : this->rozmiar.first*this->rozmiar.second / 100;
	//aby przy malych rozmiarach plansz nie bylo za duzo organizmow
	int losowanie = this->rozmiar.first*this->rozmiar.second >= 100 ? LICZBA_ORGANIMZOW : max(this->rozmiar.first, this->rozmiar.second);
	int dodanie = this->rozmiar.first*this->rozmiar.second >= 100 ? 5 : min(5, min(this->rozmiar.first, this->rozmiar.second));
	int poczatkowa_liczba_organizmow = (rand() % losowanie + dodanie)*wspolczynnik;
	pair<int, int> polozenie;
	this->dodaj_organizm({0,0}, 'C');
	czlowiek = dynamic_cast<Czlowiek*>(plansza[0][0]);
	char typ;
	string symbole = "WOLZATMGJB";
	for (int i = 0; i < poczatkowa_liczba_organizmow; i++)
	{
		polozenie.first = polozenie.second = 0;
		while ((polozenie.first == 0 && polozenie.second == 0) || (!this->puste_miejsce(polozenie)))
		{
			polozenie.first = rand() % this->rozmiar.first;
			polozenie.second = rand() % this->rozmiar.second;
			typ = symbole[i % LICZBA_ORGANIMZOW];//aby na planszy byly wszystkie organizmy
		}
		this->dodaj_organizm(polozenie, typ);
	}
}

bool Swiat::czy_zwierze_na_planszy(pair<int, int>wspolrzedne)
{
	if (this->poza_tablice(wspolrzedne) == true)return false;
	if (plansza[wspolrzedne.second][wspolrzedne.first] == NULL)return false;
	if (Zwierzeta *test = dynamic_cast<Zwierzeta*>(plansza[wspolrzedne.second][wspolrzedne.first]))
		return true;
	return false;
}

char Swiat::get_symbol_na_planszy(pair<int, int>wspolrzedne)
{
	return plansza[wspolrzedne.second][wspolrzedne.first]->get_symbol();
}

int Swiat::czytaj_znak(pair<int,int>wspolrzedne)
{
	pair<int, int>przesuniecie;
	pair<int, int>nowa_lokalizacja;
	przesuniecie.first = przesuniecie.second = 0;
	nowa_lokalizacja.first = przesuniecie.first + wspolrzedne.first;
	nowa_lokalizacja.second = przesuniecie.second + wspolrzedne.second;
	while (this->poza_tablice(nowa_lokalizacja) || (przesuniecie.first == 0 && przesuniecie.second == 0))
	{
		kursor = _getch();
		if (kursor == MOC)break;
		if (kursor == ZAPISZ)
		{
			this->zapisz_swiat();
			return NIE_DOTYCZY;
		}
		if (kursor == WCZYTAJ)
		{
			this->wczytaj_swiat(W_TRAKCIE, "");
			return NIE_DOTYCZY;
		}
		if (kursor == OPUSC_GRE)return kursor;
		if (kursor == KURSOR_GORA)przesuniecie = { 0,-1 };
		else if (kursor == KURSOR_DOL) przesuniecie = { 0,1 };
		else if (kursor == KURSOR_LEWO) przesuniecie = { -1,0 };
		else if (kursor == KURSOR_PRAWO) przesuniecie = { 1,0 };
		nowa_lokalizacja.first = przesuniecie.first + wspolrzedne.first;
		nowa_lokalizacja.second = przesuniecie.second + wspolrzedne.second;
	}
	return kursor;
}

void Swiat::zapisz_swiat()
{
	string nazwa;
	int i, j;
	this->moje_menu->pobierz_nazwe_pliku_do_zapisu(&nazwa);
	nazwa += ".txt";
	ofstream out;
	out.open(nazwa);
	out << this->rozmiar.first << " " << this->rozmiar.second << endl;
	out << this->tura << endl;
	for (i = 0; i < this->rozmiar.second; i++)
	{
		for (j = 0; j < this->rozmiar.first; j++)
		{
			if (plansza[i][j] != NULL)
			{
				out << j << " " << i << " ";
				out << plansza[i][j]->get_inicjatywa() << " ";
				out << plansza[i][j]->get_sila() << " ";
				out << plansza[i][j]->get_symbol() << " ";
				out << plansza[i][j]->get_wiek() << " ";
				if (plansza[i][j]->get_symbol() == 'C')
					out << czlowiek->get_czy_moc() << " " << czlowiek->get_licznik();
				out << endl;
			}
		}
	}
	out.close();
	this->rysuj_swiat();
}

void Swiat::czysc_swiat()
{
	this->moje_powiadomienia->komunikaty_czysc();
	for (int i = 0; i < this->rozmiar.second; i++)delete[] plansza[i];
	delete[] plansza;
	delete czlowiek;
	ruch.clear();
}

void Swiat::wczytaj_swiat(moment_wczytania wybor, string nazwa)
{
	int inicjatywa, sila, wiek, licznik;
	char symbol;
	pair<int, int>wspolrzedne;
	bool czy_moc;
	ifstream in;
	if (wybor == W_TRAKCIE)//jezeli bedzie przed to rozmiar zostanie przeczytany z pliku, a w swiecie nic nie bedzie
	{
		this->moje_menu->pobierz_nazwe_pliku_do_wczytania(&nazwa);
		this->czysc_swiat();
		in.open(nazwa);
		in >> this->rozmiar.first >> this->rozmiar.second;
		this->plansza = new Organizmy**[this->rozmiar.second];
		for (int i = 0; i < this->rozmiar.second; i++)
		plansza[i] = new Organizmy*[this->rozmiar.first];
		for (int i = 0; i < this->rozmiar.second; i++)
		for (int j = 0; j < this->rozmiar.first; j++)
			plansza[i][j] = NULL;
	}
	else
	{
		in.open(nazwa);
		in >> this->rozmiar.first >> this->rozmiar.second;
	}
	in >> this->tura;
	this->czlowiek = NULL;
	while (in >> wspolrzedne.first >> wspolrzedne.second)
	{
		in >> inicjatywa >> sila >> symbol >> wiek;
		this->dodaj_organizm(wspolrzedne, symbol);
		plansza[wspolrzedne.second][wspolrzedne.first]->set_inicjatywa(inicjatywa);
		plansza[wspolrzedne.second][wspolrzedne.first]->set_polozenie(wspolrzedne);
		plansza[wspolrzedne.second][wspolrzedne.first]->set_sila(sila);
		plansza[wspolrzedne.second][wspolrzedne.first]->set_symbol(symbol);
		plansza[wspolrzedne.second][wspolrzedne.first]->set_wiek(wiek);
		if (symbol == 'C')
		{
			in >> czy_moc >> licznik;
			this->czlowiek = dynamic_cast<Czlowiek*>(plansza[wspolrzedne.second][wspolrzedne.first]);
			czlowiek->set_licznik(licznik);
			czlowiek->set_czy_moc(czy_moc);
		}
	}
	in.close();
	this->rysuj_swiat();
}