#pragma once
#include <Windows.h>
class Konsola
{
public:
	Konsola();
	~Konsola();
	void gotoxy(int x, int y);
	void ustaw_kolor(int kolor);
	void ustaw_biel_tla();
	void czysc();
	void wroc_do_normy();
private:
	HANDLE out;
};

