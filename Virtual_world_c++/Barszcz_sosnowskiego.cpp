#include "Barszcz_sosnowskiego.h"



Barszcz_sosnowskiego::Barszcz_sosnowskiego(Swiat& swiat_ref, int x, int y)
	:Rosliny(swiat_ref, x,y)
{
	this->sila = 10;
	this->symbol = 'B';
	this->prawdopodobienstwo = 3;
	this->kolor_symbolu = FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
}

void Barszcz_sosnowskiego::akcja()
{
	Rosliny::akcja();
	int i, j;
	for (i = -1; i < 2; i++)
	{
		for (j = -1; j < 2; j++)
		{
			if ((i != 0 || j != 0) && swiat_ref.puste_miejsce({ this->polozenie.first + i, this->polozenie.second + j })==false)
			{
				if (swiat_ref.czy_zwierze_na_planszy({ this->polozenie.first + i, this->polozenie.second + j }) == true
					&&swiat_ref.poza_tablice({ this->polozenie.first + i, this->polozenie.second + j })==false)
				{
					pair<char, char>czlony;
					czlony.first = this->symbol; czlony.second = swiat_ref.get_symbol_na_planszy({ this->polozenie.first + i, this->polozenie.second + j });
					swiat_ref.przekaz_powiadomienie(czlony, POPARZENIE);
					swiat_ref.przekaz_powiadomienie(czlony.second, SMIERC);
					swiat_ref.usun_organizm({ this->polozenie.first + i, this->polozenie.second + j });
				}
			}
		}
	}		
}

Barszcz_sosnowskiego::~Barszcz_sosnowskiego()
{
}

bool Barszcz_sosnowskiego::obrona(Organizmy* agresor)
{
	pair<char, char>czlony;
	czlony.first = this->symbol; czlony.second = agresor->get_symbol();
	swiat_ref.przekaz_powiadomienie(czlony, POPARZENIE);
	swiat_ref.przekaz_powiadomienie(agresor->get_symbol(), SMIERC);
	swiat_ref.usun_organizm(*agresor);
	return true;
}
