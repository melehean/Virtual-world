#pragma once
#include "Konsola.h"
#include "Menu.h"
#include "CONST.h"
#include "Powiadomienia.h"
#include <Windows.h>
#include <vector>
#include <iostream>
using namespace std;
class Organizmy;
class Czlowiek;
class Swiat
{
private:
	vector<Organizmy*> ruch;
	pair<int,int> rozmiar;
	Organizmy ***plansza;
	Konsola *moja_konsola;
	Powiadomienia *moje_powiadomienia;
	int tura;
	int kursor;
	int iterator_organizmow;
	int rozmiar_ruchu;
	Czlowiek *czlowiek;
	Menu *moje_menu;
	void dodaj_poczatkowe_organizmy();
	void rysuj_swiat();
	void wykonaj_ture(); 
	int czytaj_znak(pair<int,int>wspolrzedne);
	void zapisz_swiat();
	void wczytaj_swiat(moment_wczytania wybor, string nazwa);
	void czysc_swiat();
	static bool porownaj(Organizmy*, Organizmy*);
public:
	Swiat(pair<int,int> rozmiar, Konsola *moja_konsola, Menu *moje_menu);
	~Swiat();
	bool poza_tablice(pair<int, int> wspolrzedne);
	bool ruch_zwyciescy(pair<int, int>wspolrzedne, int sila);
	bool puste_miejsce(pair<int, int>wspolrzedne);
	void przekaz_powiadomienie(pair<char, char>czlony, powiadomienia_obopulne wybor);
	void przekaz_powiadomienie(char czlon, powiadomienia_pojedyncze wybor);
	void dodaj_organizm(pair<int, int>polozenie, char wybor);
	void usun_organizm(Organizmy& organizm);
	void usun_organizm(pair<int, int>wspolrzedne);
	void wykonaj_ruch(pair<int, int> wspolrzedne_obecne, pair<int, int>wspolrzedne_nowe);
	void zmien_na_planszy(pair<int, int>obecne, pair<int, int>nowe);
	void start(moment_wczytania wybor, string nazwa);
	bool czy_zwierze_na_planszy(pair<int, int>wspolrzedne);
	char get_symbol_na_planszy(pair<int, int>wspolrzedne);


	
	

};

