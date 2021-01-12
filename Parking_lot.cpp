
#include "Parking_lot.h"

//Parking_lot();

virtual void Parking_lot::add_to_parking(const Treno* tr) {
	parking_lot.push(tr);
}


virtual Treno* Parking_lot::remove_from_parking() {
	Treno tr = parking_lot.front();
	parking_lot.pop();
	return tr;
}



virtual bool Parking_lot::is_parking_empty() {
	return parking_lot.empty();
}