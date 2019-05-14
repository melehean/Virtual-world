#include "Bardziej_glowna.h"
#include "Swiat.h"
#include "Konsola.h"
#include "Menu.h"
#include "Powiadomienia.h"
#include <iostream>
#include <time.h>


using namespace std;

int main()
{
	srand(time(NULL));
	Konsola *moja_konsola = new Konsola();
	Menu *moje_menu = new Menu(moja_konsola);
	char kursor = moje_menu->stworz_menu();
	pair<int, int>rozmiar = {};
	if (kursor == NOWA_GRA)
	{
		moje_menu->pobierz_rozmiar(&rozmiar);
		Swiat *moj_swiat = new Swiat(rozmiar, moja_konsola, moje_menu);
		moj_swiat->start(W_TRAKCIE, "");
	}
	else if (kursor == WCZYTAJ)
	{
		string nazwa_pliku;
		moje_menu->pobierz_nazwe_pliku_do_wczytania(&nazwa_pliku);
		moje_menu->pobierz_rozmiar_z_pliku(&rozmiar, nazwa_pliku);
		Swiat *moj_swiat = new Swiat(rozmiar, moja_konsola, moje_menu);
		moj_swiat->start(PRZED, nazwa_pliku);
	}
	return 0;
}