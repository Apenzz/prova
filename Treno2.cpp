// CMakeProva2.cpp: definisce il punto di ingresso dell'applicazione.
//

#include "Treno2.h"

using namespace std;

Treno::Treno(std::list<Station*>& railway, int codice, int origin, int tipo, std::vector<int> timetable) {
	if (tipo == 1)
		vMax = 160;
	if (tipo == 2)
		vMax = 240;
	if (tipo == 3) {
		vMax = 300;
	}
	if (origin == 0) {
		current = railway.begin();
		next = current++;
		end = railway.end()--;
	}
	if (origin == 1) {
		current = railway.end()--;
		next = current--;
		end = railway.begin();
	}
	CODICE = codice;
	v = 0;
	ritardo = 0;
	distS = 0;
	timetable_current = 0;
	TabOrari = timetable;
}

void Treno::CambioVel(int vel) {
	v = vel;
}

void Treno::Incremento() {
	if (origin == 0) {
		current++;
		next++;
	}
	else {
		current--;
		next--;
	}
}

int Treno::timetable_time() {
	return TabOrari[timetable_current++];
}

void Treno::add_ritardo(int rit) {
	ritardo = ritardo + rit;
}

int Treno::getRitardo() { return ritardo; }
Station* Treno::getNext() { return *next; }
Station* Treno::getCurrent() { return *current; }
Station* Treno::getEnd() { return *end; }