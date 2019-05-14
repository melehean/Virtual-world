#pragma once
#include "Rosliny.h"

class Mlecz :
	public Rosliny
{
public:
	Mlecz(Swiat& swiat_ref, int x, int y);
	~Mlecz();
private:
	bool obrona(Organizmy* agresor)override;
	void akcja()override;
	
};

