#pragma once
#include "Station.h"
#include "Treno.h"
#include <queue>

class Parking_lot{
public:
	//Parking_lot();
	virtual void add_to_parking(const Treno* tr);
		virtual Treno* remove_from_parking();
		virtual bool is_parking_empty();
private:
	std::queue<Treno> parking_lot;
}

