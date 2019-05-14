#include "Czlowiek.h"
#include "CONST.h"
#include <conio.h>



Czlowiek::Czlowiek(Swiat &swiat_ref, int x, int y) :Zwierzeta(swiat_ref, x, y)
{
	this->inicjatywa = 4;
	this->sila = 5;
	this->symbol = 'C';
	this->kolor_symbolu = FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	this->kursor = 0;
	this->czy_moc = false;//domyslnie moc wylaczona
	this->licznik_mocy = -1;//tylko jak jest -1 mozna ustawic moc specjalna
}

void Czlowiek::akcja()
{
	if (kursor == KURSOR_DOL || kursor == KURSOR_GORA || kursor == KURSOR_LEWO || kursor == KURSOR_PRAWO)
	{
		pair<int, int>przesuniecie;
		pair<int, int>nowa_lokalizacja;
		if (kursor == KURSOR_GORA)przesuniecie = { 0,-1 };
		else if (kursor == KURSOR_DOL) przesuniecie = { 0,1 };
		else if (kursor == KURSOR_LEWO) przesuniecie = { -1,0 };
		else if (kursor == KURSOR_PRAWO) przesuniecie = { 1,0 };
		nowa_lokalizacja.first = przesuniecie.first + this->polozenie.first;
		nowa_lokalizacja.second = przesuniecie.second + this->polozenie.second;
		swiat_ref.wykonaj_ruch(this->polozenie, nowa_lokalizacja);
	}
	if (kursor == MOC && this->licznik_mocy == -1)//uruchomienie mocy specjalnej
	{
		this->licznik_mocy = 0;
		czy_moc = true;
		this->moc_specjalna();
		return;
	}
	if (this->licznik_mocy == 5)//jezeli minelo 5 tur to moc juz nie jest aktywna
	{
		this->czy_moc = false;
	}
	if (this->licznik_mocy >= 0 && licznik_mocy < 5 && czy_moc == true)//aktywna moc
	{
		this->licznik_mocy++;
		this->moc_specjalna();
	}
	if (this->czy_moc == false && this->licznik_mocy > 0)this->licznik_mocy--;//5 tur przerwy pomiedzy wywolaniami mocy
	if (this->czy_moc == false && this->licznik_mocy == 0)this->licznik_mocy = -1;//ponowna mozliwosc wlaczenia mocy
}


Czlowiek::~Czlowiek()
{

}

bool Czlowiek::obrona(Organizmy* agresor)//domyslnie czlowiek sie nie broni - moc specjalna zaimplementowana w akcji
{
	return false;
}

bool Czlowiek::czy_czlowiek(Organizmy* organizm)
{
	if (organizm == NULL)return false;
	else if (Czlowiek *test = dynamic_cast<Czlowiek*>(organizm))return true;
	return false;
}

void Czlowiek::set_kursor(int znak)
{
	this->kursor=znak;
}

void Czlowiek::moc_specjalna()
{
	int i, j;
	for (i = -1; i < 2; i++)
	{
		for (j = -1; j < 2; j++)
		{
			if ((i != 0 || j != 0) && swiat_ref.puste_miejsce({ this->polozenie.first + i, this->polozenie.second + j }) == false)
			{
				if (swiat_ref.poza_tablice({ this->polozenie.first + i, this->polozenie.second + j }) == false)
				{
					char czlon = swiat_ref.get_symbol_na_planszy({ this->polozenie.first + i, this->polozenie.second + j });
					swiat_ref.przekaz_powiadomienie(czlon, SPALENIE);
					swiat_ref.usun_organizm({ this->polozenie.first + i, this->polozenie.second + j });
				}
			}
		}
	}
}

bool Czlowiek::get_czy_moc()
{
	if (this == NULL)return false;
	return this->czy_moc;
}

int Czlowiek::get_licznik()
{
	if (this == NULL)return 0;
	return this->licznik_mocy;
}

void Czlowiek::set_czy_moc(bool czy_moc)
{
	this->czy_moc = czy_moc;
}
void Czlowiek::set_licznik(int licznik)
{
	this->licznik_mocy = licznik;
}