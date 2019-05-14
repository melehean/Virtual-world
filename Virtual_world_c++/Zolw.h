#pragma once
#include "Zwierzeta.h"

class Zolw :
	public Zwierzeta
{
public:
	Zolw(Swiat & swiat_ref, int x, int y);
	~Zolw();
private:
	bool obrona(Organizmy* agresor) override;
	void akcja()override;
	bool mozliwosc_wykonania_ruchu();

};

