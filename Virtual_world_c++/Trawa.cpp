#include "Trawa.h"




Trawa::Trawa(Swiat& swiat_ref, int x, int y) :Rosliny(swiat_ref, x, y)
{
	this->sila = 0;
	this->symbol = 'T';
	this->prawdopodobienstwo = 7;
	this->kolor_symbolu = FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
}


Trawa::~Trawa()
{
}

bool Trawa::obrona(Organizmy* agresor)
{
	return false;
}