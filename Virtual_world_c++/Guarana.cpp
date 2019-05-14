#include "Guarana.h"


Guarana::Guarana(Swiat& swiat_ref, int x, int y) :Rosliny(swiat_ref, x, y)
{
	this->sila = 0;
	this->symbol = 'G';
	this->prawdopodobienstwo = 5;
	this->kolor_symbolu = FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
}


Guarana::~Guarana()
{
}

bool Guarana::obrona(Organizmy* agresor)
{
	pair<char, char>czlony;
	czlony.first = this->symbol; czlony.second = agresor->get_symbol();
	swiat_ref.przekaz_powiadomienie(czlony, WZMOCNIENIE);
	agresor->set_sila(agresor->get_sila() + 3);
	return false;
}
