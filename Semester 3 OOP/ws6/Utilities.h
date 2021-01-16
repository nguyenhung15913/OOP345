#ifndef _SDDS_UTILITIES_H
#define _SDDS_UTILITIES_H
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"
#include <sstream>
namespace sdds {
	Vehicle* createInstance(std::istream& in);
}
#endif // !_SDDS_UTILITIES_H
