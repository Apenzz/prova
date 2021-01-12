#include "Station.h"
#include "Main_station.h"
#include "Local_station.h"
#include "Treno.h"
#include "railway_input.h"
#include "trains_input.h"

//#include "Simulation.h"

int main()
{	
	std::list<Station*> railway = stations_input();														//inizializzo tutte le stazioni

	for (std::list<Station*>::iterator itr = railway.begin(); itr != railway.end(); itr++)				//prova di stampa RAILWAY
	{
		std::cout << " -nome: " << (*itr)->get_name();
		std::cout << "-tipo: " << (*itr)->get_type();
		std::cout << " -distanza: " << (*itr)->get_distance();
		std::cout << " -indirizzo: " << *itr<<"\n";
	}

	
	std::vector<Treno> trains = timetable_input(railway);												//inizializzo tutti i treni


	for (int i = 0; i < trains.size(); i++)
	{
		std::cout << "Treno " << i << " in partenza alle ore: " << trains[i].timetable_time() << "\n";
	}

}


