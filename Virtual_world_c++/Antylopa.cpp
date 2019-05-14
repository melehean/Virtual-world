#include "Antylopa.h"





Antylopa::Antylopa(Swiat &swiat_ref, int x, int y) :Zwierzeta(swiat_ref, x, y)
{
	this->sila = 4;
	this->inicjatywa = 4;
	this->symbol = 'A';
	this->kolor_symbolu = FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
}

void Antylopa::akcja()
{
	pair<int, int>przesuniecie;
	pair<int, int>nowa_lokalizacja;
	przesuniecie.first = przesuniecie.second = 0;
	nowa_lokalizacja.first = przesuniecie.first + this->polozenie.first;
	nowa_lokalizacja.second = przesuniecie.second + this->polozenie.second;
	while ((przesuniecie.first == 0 && przesuniecie.second == 0) || (swiat_ref.poza_tablice(nowa_lokalizacja)))
	{
		przesuniecie.first = rand() % 5 - 2;
		przesuniecie.second = rand() % 5 - 2;
		nowa_lokalizacja.first = przesuniecie.first + this->polozenie.first;
		nowa_lokalizacja.second = przesuniecie.second + this->polozenie.second;
	}
	swiat_ref.wykonaj_ruch(this->polozenie, nowa_lokalizacja);
}

Antylopa::~Antylopa()
{
}

bool Antylopa::obrona(Organizmy* agresor)
{
	if (this->mozliwosc_wykonania_ruchu())
	{
		pair<int, int>przesuniecie;
		pair<int, int>nowa_lokalizacja;
		przesuniecie.first = przesuniecie.second = 0;
		nowa_lokalizacja.first = przesuniecie.first + this->polozenie.first;
		nowa_lokalizacja.second = przesuniecie.second + this->polozenie.second;
		while ((przesuniecie.first == 0 && przesuniecie.second == 0) || (!swiat_ref.puste_miejsce(nowa_lokalizacja)))
		{
			przesuniecie.first = rand() % 3 - 1;
			przesuniecie.second = rand() % 3 - 1;
			nowa_lokalizacja.first = przesuniecie.first + this->polozenie.first;
			nowa_lokalizacja.second = przesuniecie.second + this->polozenie.second;
		}
		swiat_ref.wykonaj_ruch(this->polozenie, nowa_lokalizacja);
		pair<char, char>czlony;
		czlony.first = this->symbol; czlony.second = agresor->get_symbol();
		swiat_ref.przekaz_powiadomienie(czlony, UCIECZKA);
		return true;
	}
	return false;
}

bool Antylopa::mozliwosc_wykonania_ruchu()
{
	int szansa = rand() % 2;
	bool czy_moze_sie_ruszyc = false;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if ((i != 0 || j != 0) && swiat_ref.puste_miejsce({ this->polozenie.first + i, this->polozenie.second + j }))
				czy_moze_sie_ruszyc = true;
	if (szansa == 0 && czy_moze_sie_ruszyc)return true;
	return false;
}