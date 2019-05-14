#include "Lis.h"



Lis::Lis(Swiat &swiat_ref, int x, int y) :Zwierzeta(swiat_ref, x, y)
{
	this->sila = 3;
	this->inicjatywa = 7;
	this->symbol = 'L';
	this->kolor_symbolu = FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
}

void Lis::akcja()
{
	if (this->mozliwosc_wykonania_ruchu())
	{
		pair<int, int>przesuniecie;
		pair<int, int>nowa_lokalizacja;
		przesuniecie.first = przesuniecie.second = 0;
		nowa_lokalizacja.first = przesuniecie.first + this->polozenie.first;
		nowa_lokalizacja.second = przesuniecie.second + this->polozenie.second;
		while ((przesuniecie.first == 0 && przesuniecie.second == 0) || (swiat_ref.poza_tablice(nowa_lokalizacja)==true) 
			|| (swiat_ref.ruch_zwyciescy(nowa_lokalizacja, this->sila)==false))
		{
			przesuniecie.first = rand() % 3 - 1;
			przesuniecie.second = rand() % 3 - 1;
			nowa_lokalizacja.first = przesuniecie.first + this->polozenie.first;
			nowa_lokalizacja.second = przesuniecie.second + this->polozenie.second;
		}
		swiat_ref.wykonaj_ruch(this->polozenie, nowa_lokalizacja);
	}
}
bool Lis::mozliwosc_wykonania_ruchu()
{
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if ((i != 0 || j != 0) && swiat_ref.ruch_zwyciescy({ this->polozenie.first + i, this->polozenie.second + j }, this->sila)==true)
				return true;
	return false;
}


Lis::~Lis()
{
}

bool Lis::obrona(Organizmy* agresor)
{
	return false;
}
