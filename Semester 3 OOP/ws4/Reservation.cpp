#include "Reservation.h"
#include <iomanip>
namespace sdds {
	Reservation::Reservation() {
		resID[9] = '\0';
		nameOfRes = "";
		email = "";
		numOfPpl = 0;
		day = 0;
		hour = 0;
	}

	Reservation::Reservation(const std::string& res) {
		resID[9] = '\0';
		nameOfRes = "";
		email = "";
		numOfPpl = 0;
		day = 0;
		hour = 0;
		std::string temp;
		std::string id_temp;
		std::string nameTemp;
		std::string emailTemp;
		int noTemp;
		unsigned int day1;
		temp = res;
		temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
		id_temp = temp.substr(0, 8);
		temp.erase(0, 8);
		std::string::size_type pos = temp.find(',');
		nameTemp = temp.substr(0, pos);
		temp.erase(0, pos + 1);
		pos = temp.find(',');
		emailTemp = temp.substr(0, pos);
		temp.erase(0, pos + 1);
		noTemp = std::stoi(temp.substr(0, pos));
		temp.erase(0, 2);
		day1 = std::stoi(temp.substr(0, pos ));
		temp.erase(0, 2);
		this->hour = std::stoi(temp.substr(0, pos));
		strcpy(this->resID, id_temp.c_str());
		this->nameOfRes = nameTemp;
		this->email = emailTemp;
		this->numOfPpl = noTemp;
		this->day = day1;
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& value) {
		size_t width = value.email.length();
		if (value.hour >= 6 && value.hour <= 9) {
			os << "Reservation " << value.resID << " ";
			os << right << setw(10) << value.nameOfRes << "  <";
			os  << value.email << left  << setw(22 - width) <<">" <<" Breakfast on day " << value.day << " @ " << value.hour << ":00 for " << value.numOfPpl << " people." << endl;
		}
		else if (value.hour >= 11 && value.hour <= 15) {
			os << "Reservation " << value.resID << " ";
			os << right << setw(10) << value.nameOfRes << "  <";
			os << value.email << left  << setw(22 - width) << ">" << " Lunch on day " << value.day << " @ " << value.hour << ":00 for " << value.numOfPpl << " people." << endl;
		}
		else if (value.hour >= 17 && value.hour <= 21) {
			os << "Reservation " << value.resID << " ";
			os << right << setw(10) << value.nameOfRes << "  <";
			os << value.email << left  << setw(22 - width) << ">" << " Dinner on day " << value.day << " @ " << value.hour << ":00 for " << value.numOfPpl << " people." << endl;
		}
		else {
			os << "Reservation " << value.resID << " ";
			os << right << setw(10) << value.nameOfRes << "  <";
			os << value.email << left  << setw(22 - width) << ">" << " Drinks on day " << value.day << " @ " << value.hour << ":00 for " << value.numOfPpl << " people." << endl;
		}
		return os;
	}
}