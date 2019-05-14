#pragma once
#include "Rosliny.h"

class Trawa :
	public Rosliny
{
public:
	Trawa(Swiat& swiat_ref, int x, int y);
	~Trawa();
private:
	bool obrona(Organizmy* agresor)override;
};

