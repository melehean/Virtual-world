#include "Zwierzeta.h"



Zwierzeta::Zwierzeta(Swiat& swiat_ref, int x, int y):Organizmy(swiat_ref, x,y)
{

}


Zwierzeta::~Zwierzeta()
{

}

void Zwierzeta::rozmnazanie(pair<int,int>wspolrzedne)
	{
	int i,j;
	bool czy_jest_miejsce_atak=false;
	bool czy_jest_miejsce_obrona=false;
	pair<int, int>przesuniecie;
	pair<int, int>nowa_lokalizacja;
	pair<int, int>miejsce;
	for (i = -1; i < 2; i++)
	{
		for (j = -1; j < 2; j++)
		{
			if ((i != 0 || j != 0) && swiat_ref.puste_miejsce({ wspolrzedne.first + i,wspolrzedne.second + j })==true)
				czy_jest_miejsce_obrona = true;
			if ((i != 0 || j != 0) && swiat_ref.puste_miejsce({ this->polozenie.first + i,this->polozenie.second + j })==true)
				czy_jest_miejsce_atak = true;
		}
	}
	if (czy_jest_miejsce_atak == true || czy_jest_miejsce_obrona ==true)
	{
		przesuniecie.first = 0; przesuniecie.second = 0;
		nowa_lokalizacja.first = this->polozenie.first + przesuniecie.first;
		nowa_lokalizacja.second = this->polozenie.second + przesuniecie.second;
		if (czy_jest_miejsce_obrona==true)
		{
			miejsce.first = wspolrzedne.first;
			miejsce.second = wspolrzedne.second;
		}
		else if(czy_jest_miejsce_atak == true)
		{
			miejsce.first = this->polozenie.first;
			miejsce.second = this->polozenie.second;
		}
		while ((przesuniecie.first == 0 && przesuniecie.second == 0) ||
			(!swiat_ref.puste_miejsce(nowa_lokalizacja)))
		{
			przesuniecie.first = rand() % 3 - 1;
			przesuniecie.second = rand() % 3 - 1;
			nowa_lokalizacja.first = miejsce.first + przesuniecie.first;
			nowa_lokalizacja.second = miejsce.second + przesuniecie.second;
		}
		//if(swiat_ref.puste_miejsce(nowa_lokalizacja)==true)
		swiat_ref.dodaj_organizm(nowa_lokalizacja,this->symbol);
	}

	}

void Zwierzeta::akcja()
{
	pair<int, int>przesuniecie;
	pair<int, int>nowa_lokalizacja;
	przesuniecie.first = przesuniecie.second = 0;
	nowa_lokalizacja.first = przesuniecie.first + this->polozenie.first;
	nowa_lokalizacja.second = przesuniecie.second + this->polozenie.second;
	while (przesuniecie.first == 0 && przesuniecie.second == 0 || swiat_ref.poza_tablice(nowa_lokalizacja))
	{
		przesuniecie.first = rand() % 3 - 1;
		przesuniecie.second = rand() % 3 - 1;
		nowa_lokalizacja.first = przesuniecie.first + this->polozenie.first;
		nowa_lokalizacja.second = przesuniecie.second + this->polozenie.second;
	}
	swiat_ref.wykonaj_ruch(this->polozenie, nowa_lokalizacja);
}

void Zwierzeta::kolizja(Organizmy* osobnik_obronny)
{
	if (this->symbol == osobnik_obronny->get_symbol())
	{
		this->rozmnazanie(osobnik_obronny->get_polozenie());
	}
	else
	{
		if (osobnik_obronny->obrona(this) == true)//obroni sie
		{
			return;
		}
		else //nie ma wstepnej obrony
		{
			pair<char, char>czlony;
			czlony.first = this->symbol;czlony.second = osobnik_obronny->get_symbol();
			swiat_ref.przekaz_powiadomienie(czlony, WALKA);
			if (this->sila >= osobnik_obronny->get_sila())
			{
				swiat_ref.przekaz_powiadomienie(osobnik_obronny->get_symbol(), SMIERC);
				pair<int, int>pom = osobnik_obronny->get_polozenie();
				swiat_ref.usun_organizm(*osobnik_obronny);
				swiat_ref.zmien_na_planszy(this->polozenie, pom);
			}
			else
			{
				swiat_ref.przekaz_powiadomienie(this->symbol, SMIERC);
				swiat_ref.usun_organizm(*this);
			}
		}
	}
}

