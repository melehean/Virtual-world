#pragma once
#include "Swiat.h"
using namespace std;
class Swiat;
class Organizmy
{
protected:
	int wiek;
	int inicjatywa;
	int sila;
	pair<int, int> polozenie;
	Swiat &swiat_ref;
	char symbol;
	int kolor_symbolu;
public:
	Organizmy(Swiat &swiat_ref, int x,int y);
	virtual void akcja()=0;
	virtual void kolizja(Organizmy* osobnik_obronny)=0;
	virtual bool obrona(Organizmy* agresor)=0;
	void postarz_organizm();
	//gettery
	int get_wiek();
	int get_kolor();
	int get_inicjatywa();
	int get_sila();
	pair<int, int> get_polozenie();
	char get_symbol();
	//settery
	void set_wiek(int wiek);
	void set_inicjatywa(int inicjatywa);
	void set_sila(int sila);
	void set_polozenie(pair<int, int> polozenie);
	void set_symbol(char symbol);
};

