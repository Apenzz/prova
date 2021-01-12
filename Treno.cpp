//AUTORE: Leonardo Fasolo

#include "Station.h"
#include "Treno.h"


using namespace std;

Treno::Treno(list<Station*>& railway, int cod, int origin, int tipo, vector<int> timetable) {
	if (tipo == 1)
		vMax = 160;
	else if (tipo == 2)
		vMax = 240;
	else {
		vMax = 300;
	}
	if (origin == 0) {
		curr = railway.begin();
		succ = curr++;
		fine = (railway.end())--;
	}
	else {
		curr = (railway.end())--;
		succ = curr--;
		fine = railway.begin();
	}
	codice= cod;
	v = 0;
	ritardo = 0;
	distS = 0;
	timetable_current = 0;
	TabOrari = timetable;
	type = tipo;
}

void Treno::CambioVel(int vel) {
	v = vel;
}

void Treno::Incremento() {
	if (origin == 0) {
		curr++;
		succ++;
	}
	else {
		curr--;
		succ--;
	}
}

int Treno::timetable_time() {
	return TabOrari[timetable_current++];
}

void Treno::add_ritardo(int rit) {
	ritardo = ritardo + rit;
}

int Treno::getRitardo() { return ritardo; }
int Treno::getCodice() { return codice; }
Station* Treno::getNext() { return *succ; }
Station* Treno::getCurrent() { return *curr; }
Station* Treno::getEnd() { return *fine; }
int Treno::get_type() { return type; }
int Treno::getVel() { return vMax; }