#include "Powiadomienia.h"
#include <iostream>

using namespace std;

Powiadomienia::Powiadomienia(Konsola *moja_konsola)
{
	this->moja_konsola = moja_konsola;
}


Powiadomienia::~Powiadomienia()
{

}

void Powiadomienia::powiadomienia(pair<char, char> czlony, powiadomienia_obopulne wybor)
{
	string komunikat = "";
	komunikat += czlony.first;
	switch (wybor)
	{
	case WALKA:
		komunikat += " walczy z ";
		break;
	case OPOR:
		komunikat += " odparl ";
		break;
	case WZMOCNIENIE:
		komunikat += " wzmocnila ";
		break;
	case ZATRUCIE:
		komunikat += " zatrula ";
		break;
	case POPARZENIE:
		komunikat += " poparzyl ";
		break;
	case UCIECZKA:
		komunikat += " uciekla przed ";
	}
	komunikat += czlony.second;
	this->kolejka.push(komunikat);
}
void Powiadomienia::powiadomienia(char czlon, powiadomienia_pojedyncze wybor)
{
	string komunikat = "";
	switch (wybor)
	{
	case SMIERC:
		if (spr_rodzaj(czlon) == ZENSKI)komunikat += "Umarla ";
		else komunikat += "Umarl ";
		break;
	case NARODZINY:
		if (spr_rodzaj(czlon) == ZENSKI)komunikat += "Urodzila sie ";
		else komunikat += "Urodzil sie ";
		break;
	case SPALENIE:
		if (spr_rodzaj(czlon) == ZENSKI)komunikat += "Splonela ";
		else komunikat += "Splonal ";
		break;
	}
	komunikat += czlon;
	this->kolejka.push(komunikat);
}
rodzaj Powiadomienia::spr_rodzaj(char symbol)
{
	switch (symbol)
	{
	case 'C':
		return MESKI;
	case 'A':
		return ZENSKI;
	case 'B':
		return MESKI;
	case 'G':
		return ZENSKI;
	case 'W':
		return MESKI;
	case 'L':
		return MESKI;
	case 'T':
		return ZENSKI;
	case 'M':
		return MESKI;
	case 'O':
		return ZENSKI;
	case 'J':
		return ZENSKI;
	case 'Z':
		return MESKI;
	}
}

void Powiadomienia::stworz_komunikaty()
{
	int ile = 0;
	this->moja_konsola->ustaw_biel_tla();
	int wspolrzedna_y = POCZATEK_KOMUNIKATOW_Y;
	this->moja_konsola->gotoxy(POCZATEK_KOMUNIKATOW_X, wspolrzedna_y++);
	cout << "    Komunikaty    ";
	this->moja_konsola->gotoxy(POCZATEK_KOMUNIKATOW_X, wspolrzedna_y++);
	while (!kolejka.empty()&&ile<=MAX_KOM)//ograniczam ilosc komunikatow, zeby nie ekran nie zjerzdzal
	{
		cout << kolejka.front();
		if (kolejka.front().size() < MAX_DL_KOMUNIKAT)
		{
			for (int i = kolejka.front().size(); i < MAX_DL_KOMUNIKAT; i++)cout << ' ';
		}
		this->moja_konsola->gotoxy(POCZATEK_KOMUNIKATOW_X, wspolrzedna_y++);
		kolejka.pop();
		ile++;
	}
	this->moja_konsola->wroc_do_normy();
}

void Powiadomienia::komunikaty_czysc()
{
	while (!kolejka.empty())
		kolejka.pop();
}