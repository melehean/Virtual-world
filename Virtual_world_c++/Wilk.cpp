#include "Wilk.h"



Wilk::Wilk(Swiat &swiat_ref, int x, int y) :Zwierzeta(swiat_ref, x, y)
{
	this->sila = 9;
	this->inicjatywa = 5;
	this->symbol = 'W';
	this->kolor_symbolu = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
}


Wilk::~Wilk()
{
}

bool Wilk::obrona(Organizmy* agresor)
{
	return false;
}
