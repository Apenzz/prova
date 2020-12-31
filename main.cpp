#include <iostream>
#include <fstream>
#include<vector>
#include<sstream>

int main() {

	std::vector<std::string> stazioni;
	std::vector<int> principali;
	std::vector<int> distanze;


	std::ifstream linea_ferroviaria;
	linea_ferroviaria.open("line_description.txt");

	
	int i = 1;

	if (linea_ferroviaria.is_open())
	{
		
		std::string line;
		getline(linea_ferroviaria, line);

		stazioni.push_back(line);			//stazione di partenza
		principali.push_back(0);			//è principale???
		distanze.push_back(0);				//distanza = 0km
		
		
		while (std::getline(linea_ferroviaria, line)) {				//prossima riga (finchè ce ne sono)
			
			std::string name;										//variabile "string" di appoggio	
			stazioni.push_back(name);								//eseguo qui un push back "vuoto" cosi inizializza i nomi delle stazioni e nel loop successivo posso usare += nel caso in cui il nome sia formato da più parole
			int integers;											//variabile "int" di appoggio (per verificare il tipo di dato in input)

			std::stringstream ss(line);								//creo uno string stream formato da tutta la linea
		
			while (ss>>name || !ss.eof())							//loop che prosegue fino a fine linea (!ss.eof() facoltativo, fa >> in automatico)	
			{
				
				if (std::stringstream(name) >> integers)			//utilizzo uno string stream per verificare se la prossima word è un integer
				{
					
					principali.push_back(integers);					//se entra significa che ha trovato 0/1 cioè il valore da inserire nell'array "principali"
					ss >> integers;									//passa alla parola(numero) successiva (distanza)
					distanze.push_back(integers);					//inserisco nell'array "distanze"
		
				}
				else
					stazioni[i]+=name+" ";							//se non è un numero significa che il nome della stazione è formato da più parole quindi lo aggiungo
			}
			i++;
		}
		
		linea_ferroviaria.close();									//chiudo stream di input del file
	}
	else
		std::cout << "Unable to open file.";
	


	//funziona?
	for (int j = 0; j < i; j++)
	{
		std::cout << "stazione: " << stazioni[j];
		std::cout << "; principale? ";
		if (principali[j] == 0)
			std::cout << "SI";
		else
			std::cout << "NO";
		std::cout << "; distanza: " << distanze[j] <<"."<< std::endl;
	}

	return 0;
}