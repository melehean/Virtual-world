#pragma once
#include "Organizmy.h"
class Zwierzeta : public Organizmy
{
public:
	Zwierzeta(Swiat& swiat_ref, int x, int y);
	~Zwierzeta();
protected:
	virtual void akcja() override;
	void kolizja(Organizmy* osobnik_obronny)override;
	void rozmnazanie(pair<int,int>wspolrzedne);
	virtual bool obrona(Organizmy* agresor)override = 0;
};

