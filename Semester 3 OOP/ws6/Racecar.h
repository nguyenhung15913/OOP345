#ifndef _SDDS_RACECAR_H
#define _SDDS_RACECAR_H
#include "Car.h"
#include <iostream>
#include <string>
#include <sstream>
namespace sdds {
	class Racecar : public Car {
	private:
		double m_booster = 0;
	public :
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}

#endif // !_SDDS_RACECAR_H
