#include "Zolw.h"





Zolw::Zolw(Swiat &swiat_ref, int x, int y) :Zwierzeta(swiat_ref, x, y)
{
	this->sila = 2;
	this->inicjatywa = 1;
	this->symbol = 'Z';
	this->kolor_symbolu = FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
}


Zolw::~Zolw()
{
}

void Zolw::akcja()
{
	if (mozliwosc_wykonania_ruchu() == true)Zwierzeta::akcja();
	else return;
}

bool Zolw::mozliwosc_wykonania_ruchu()
{
	int losowa = rand() % 100;
	if (losowa < 75)return false;
	else return true;
}

bool Zolw::obrona(Organizmy* agresor)
{
	if (agresor->get_sila() < 5 && agresor->get_sila()>0)
	{
		pair<char, char>czlony;
		czlony.first = this->symbol; czlony.second = agresor->get_symbol();
		swiat_ref.przekaz_powiadomienie(czlony, OPOR);
		return true;
	}
	return false;
}

