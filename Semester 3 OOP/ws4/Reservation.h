#define _CRT_SECURE_NO_WARNINGS
#ifndef _SDDS_RESERVATION_H
#define _SDDS_RESERVATION_H
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;
#include <iostream>
#include <ostream>
namespace sdds {
	class Reservation {
		char resID[10];
		std::string nameOfRes;
		std::string email;
		int numOfPpl;
		unsigned int day;
		unsigned int hour;
	public:
		Reservation();
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& value);
	};
}



#endif // !_SDDS_RESERVATION_H
