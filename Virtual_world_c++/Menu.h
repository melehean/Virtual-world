#pragma once
#include "Konsola.h"
#include <utility>
#include <string>

using namespace std;
class Menu
{
public:
	Menu(Konsola *moja_konsola);
	~Menu();
	void pobierz_rozmiar(pair<int,int> *rozmiar);
	void stworz_legende();
	void stworz_rozne(bool czy_moc, int tura);
	void stworz_sterowanie();
	void smierc();
	void pobierz_nazwe_pliku_do_zapisu(string *nazwa);
	void pobierz_nazwe_pliku_do_wczytania(string *nazwa);
	char stworz_menu();
	void pobierz_rozmiar_z_pliku(pair<int, int> *rozmiar, string nazwa_pliku);
private:
	Konsola *moja_konsola;
};

