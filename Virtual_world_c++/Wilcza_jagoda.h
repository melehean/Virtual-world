#pragma once
#include "Rosliny.h"
class Wilcza_jagoda :
	public Rosliny
{
public:
	Wilcza_jagoda(Swiat& swiat_ref, int x, int y);
	~Wilcza_jagoda();
private:
	bool obrona(Organizmy* agresor) override;

};

