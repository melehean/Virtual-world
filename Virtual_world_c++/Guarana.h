#pragma once
#include "Rosliny.h"

class Guarana :
	public Rosliny
{
public:
	Guarana(Swiat& swiat_ref, int x, int y);
	~Guarana();
private:
	bool obrona(Organizmy* agresor) override;
	
};

