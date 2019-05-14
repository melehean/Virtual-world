#pragma once
#include "Zwierzeta.h"

class Wilk :
	public Zwierzeta
{
public:
	Wilk(Swiat & swiat_ref, int x, int y);
	~Wilk();
private:
	bool obrona(Organizmy* agresor)override;

};

