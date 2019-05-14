#pragma once
#include "Zwierzeta.h"

class Czlowiek :
	public Zwierzeta
{
public:
	Czlowiek(Swiat & swiat_ref, int x, int y);
	void set_kursor(int znak);
	bool get_czy_moc();
	int get_licznik();
	void set_czy_moc(bool czy_moc);
	void set_licznik(int licznik);
	bool czy_czlowiek(Organizmy* organizm);
	~Czlowiek();
private:
	bool obrona(Organizmy* agresor)override;
	void akcja()override;
	void moc_specjalna();
	int kursor;
	int licznik_mocy;
	int czy_moc;
	
	
};

