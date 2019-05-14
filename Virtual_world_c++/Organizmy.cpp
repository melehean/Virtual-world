#include "Organizmy.h"

Organizmy::Organizmy(Swiat &swiat_ref, int x,int y):swiat_ref(swiat_ref)
{
	this->polozenie.first = x;
	this->polozenie.second = y;
	this->wiek = 0;
}

void Organizmy::postarz_organizm()
{
	this->wiek++;
}

int Organizmy::get_kolor()
{
	return this->kolor_symbolu;
}

int Organizmy::get_wiek()
{
	return this->wiek;
}
int Organizmy::get_inicjatywa()
{
	return this->inicjatywa;
}
int Organizmy::get_sila()
{
	return this->sila;
}
pair<int,int> Organizmy::get_polozenie()
{
	return this->polozenie;
}
char Organizmy::get_symbol()
{
	return this->symbol;
}
void Organizmy::set_wiek(int wiek)
{
	this->wiek = wiek;
}
void Organizmy::set_inicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
void Organizmy::set_sila(int sila)
{
	this->sila = sila;
}
void Organizmy::set_polozenie(pair<int,int> polozenie)
{
	this->polozenie.first = polozenie.first;
	this->polozenie.second = polozenie.second;
}
void Organizmy::set_symbol(char symbol)
{
	this->symbol = symbol;
}






