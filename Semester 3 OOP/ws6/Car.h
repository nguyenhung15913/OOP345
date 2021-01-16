#ifndef _SDDS_CAR_H
#define _SDDS_CAR_H
#include "Vehicle.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
namespace sdds {
	class Car : public Vehicle {
		std::string maker = "";
		std::string m_condition = "";
		double top_speed = 0;
		std::string top_speed_str = "";
	public:
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		std::string& topSpeedStr();
		std::string getMaker() const;
	};
}

#endif // !_SDDS_CAR_H
