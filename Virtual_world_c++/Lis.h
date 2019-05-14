#pragma once
#include "Zwierzeta.h"

class Lis :
	public Zwierzeta
{
public:
	Lis(Swiat & swiat_ref, int x, int y);
	~Lis();
private:
	bool obrona(Organizmy* agresor)override;
	void akcja()override;
	bool mozliwosc_wykonania_ruchu();
};

