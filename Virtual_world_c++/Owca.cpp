#include "Owca.h"


Owca::Owca(Swiat &swiat_ref, int x, int y) :Zwierzeta(swiat_ref, x, y)
{
	this->sila = 4;
	this->inicjatywa = 4;
	this->symbol = 'O';
	this->kolor_symbolu = FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
}


Owca::~Owca()
{
}

bool Owca::obrona(Organizmy* agresor)
{
	return false;
}
