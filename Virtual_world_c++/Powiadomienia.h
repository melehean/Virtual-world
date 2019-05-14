#pragma once
#include "Enum.h"
#include "Konsola.h"
#include "CONST.h"
#include <queue>
#include <string>
using namespace std;
class Powiadomienia
{
public:
	Powiadomienia(Konsola *moja_konsola);
	~Powiadomienia();
	void powiadomienia(pair<char, char> czlony, powiadomienia_obopulne wybor);
	void powiadomienia(char czlon, powiadomienia_pojedyncze wybor);
	void stworz_komunikaty();
	void komunikaty_czysc();
private:
	queue<string> kolejka;
	Konsola *moja_konsola;
	rodzaj spr_rodzaj(char symbol);

};

