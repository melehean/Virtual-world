#include "Rosliny.h"




Rosliny::Rosliny(Swiat& swiat_ref, int x, int y) :Organizmy(swiat_ref, x, y)
{
	this->inicjatywa = 0;
}


Rosliny::~Rosliny()
{
}

void Rosliny::kolizja(Organizmy* osobnik_obronny)
{
	return;
}

void Rosliny::akcja()
{
	if (this->mozliwosc_rozmnazania())
	{
		pair<int, int>przesuniecie;
		pair<int, int>nowa_lokalizacja;
		przesuniecie.first = przesuniecie.second = 0;
		nowa_lokalizacja.first = przesuniecie.first + this->polozenie.first;
		nowa_lokalizacja.second = przesuniecie.second + this->polozenie.second;
		while (przesuniecie.first == 0 && przesuniecie.second == 0 || (swiat_ref.puste_miejsce(nowa_lokalizacja)==false))
		{
			przesuniecie.first = rand() % 3 - 1;
			przesuniecie.second = rand() % 3 - 1;
			nowa_lokalizacja.first = przesuniecie.first + this->polozenie.first;
			nowa_lokalizacja.second = przesuniecie.second + this->polozenie.second;
		}
		swiat_ref.dodaj_organizm(nowa_lokalizacja, this->symbol);
	}
}

bool Rosliny::mozliwosc_rozmnazania()
{
	int szansa = rand() % 100;
	bool czy_jest_miejsce_na_nasiona = false;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if ((i != 0 || j != 0) && swiat_ref.puste_miejsce({ this->polozenie.first + i, this->polozenie.second + j })==true)
				czy_jest_miejsce_na_nasiona = true;

	if (szansa < this->prawdopodobienstwo && czy_jest_miejsce_na_nasiona==true)return true;
	return false;
}
