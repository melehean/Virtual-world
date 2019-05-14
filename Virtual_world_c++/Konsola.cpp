#include "Konsola.h"



Konsola::Konsola()
{
	this->out = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Konsola::gotoxy(int x, int y) 
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(this->out, pos);
}

void Konsola::ustaw_kolor(int kolor)
{
	SetConsoleTextAttribute(this->out, kolor);
}

void Konsola::ustaw_biel_tla()
{
	SetConsoleTextAttribute(this->out, BACKGROUND_BLUE| BACKGROUND_RED| BACKGROUND_GREEN);
}

void Konsola::wroc_do_normy()
{
	SetConsoleTextAttribute(this->out, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
}

void Konsola::czysc()
{
	system("cls");
}


Konsola::~Konsola()
{
}
