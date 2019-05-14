#pragma once
#include "Zwierzeta.h"

class Antylopa :
	public Zwierzeta
{
public:
	Antylopa(Swiat & swiat_ref, int x, int y);
	~Antylopa();
private:
	bool obrona(Organizmy* agresor)override;
	bool mozliwosc_wykonania_ruchu();
	void akcja()override;
	
};

