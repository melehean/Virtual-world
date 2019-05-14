#pragma once
#include "Zwierzeta.h"

class Owca :
	public Zwierzeta
{
public:
	Owca(Swiat & swiat_ref, int x, int y);
	~Owca();
private:
	bool obrona(Organizmy* agresor)override;
};

