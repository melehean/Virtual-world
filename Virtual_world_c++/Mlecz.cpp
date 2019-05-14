#include "Mlecz.h"


Mlecz::Mlecz(Swiat& swiat_ref, int x, int y) :Rosliny(swiat_ref, x, y)
{
	this->sila = 0;
	this->symbol = 'M';
	this->prawdopodobienstwo = 5;
	this->kolor_symbolu = FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
}


Mlecz::~Mlecz()
{
}

bool Mlecz::obrona(Organizmy* agresor)
{
	return false;
}

void Mlecz::akcja()
{
	for (int i = 0; i < 3; i++)
	{
		Rosliny::akcja();
	}
}