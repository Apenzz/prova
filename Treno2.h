// CMakeProva2.h: file di inclusione per file di inclusione di sistema standard,
// o file di inclusione specifici del progetto.

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Station.h"
#include <list>


class Treno{
public:
	Treno(std::list<Station*>& railway, int codice, int origin, int tipo, std::vector<int> timetable);
	void CambioVel(int vel);
	void Incremento();
	int timetable_time();
	void add_ritardo(int rit);
	int getRitardo();
	Station* getNext();
	Station* getCurrent();
	Station* getEnd();
private:
	//int tipo;
	int v;
	int distS;
	int ritardo;
	int vMax;
	const int vMedia = 80;
	int CODICE;
	int origin;
	vector<int> TabOrari;
	int timetable_current;
	std::list<Station*>::iterator current;
	std::list<Station*>::iterator next;
	std::list<Station*>::iterator end;
	//enum stato { FermoInStazione, InPartenza, VelDiCrociera };
};


// TODO: Fare riferimento qui alle intestazioni aggiuntive richieste dal programma.
