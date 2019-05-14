#pragma once
#include "Rosliny.h"
class Barszcz_sosnowskiego :
	public Rosliny
{
public:
	Barszcz_sosnowskiego(Swiat& swiat_ref, int x, int y);
	~Barszcz_sosnowskiego();
private:
	bool obrona(Organizmy* agresor) override;
	void akcja()override;
	
};

