#ifndef _SDDS_AUTOSHOP_H
#define _SDDS_AUTOSHOP_H
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include <iostream>
#include <list>
using namespace std;
namespace sdds {
	class Autoshop {
	private:
		std::vector<Vehicle*> m_vehicles  ;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
				if (test(*i)) {
					vehicles.push_back(*i);
				}
			}
		}
	};
}
#endif // !_SDDS_AUTOSHOP_H
