#pragma once
#include "Organizmy.h"

class Rosliny :public Organizmy
{
public:
	Rosliny(Swiat& swiat_ref, int x, int y);
	~Rosliny();
protected:
	virtual bool obrona(Organizmy* agresor)override = 0;
	void kolizja(Organizmy* osobnik_obronny)override;
	bool mozliwosc_rozmnazania();
	virtual void akcja()override;
	int prawdopodobienstwo;
	
};

