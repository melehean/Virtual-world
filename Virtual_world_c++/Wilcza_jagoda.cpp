#include "Wilcza_jagoda.h"



Wilcza_jagoda::Wilcza_jagoda(Swiat& swiat_ref, int x, int y) :Rosliny(swiat_ref, x, y)
{
	this->sila = 99;
	this->symbol = 'J';
	this->prawdopodobienstwo = 3;
	this->kolor_symbolu = FOREGROUND_BLUE | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
}


Wilcza_jagoda::~Wilcza_jagoda()
{

}

bool Wilcza_jagoda::obrona(Organizmy* agresor)
{
	pair<char, char>czlony;
	czlony.first = this->symbol; czlony.second = agresor->get_symbol();
	swiat_ref.przekaz_powiadomienie(czlony, ZATRUCIE);
	swiat_ref.przekaz_powiadomienie(agresor->get_symbol(), SMIERC);
	swiat_ref.usun_organizm(*agresor);
	return true;
}
