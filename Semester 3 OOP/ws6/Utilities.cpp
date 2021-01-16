#include "Utilities.h"
namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		std::string temp;
		std::stringstream str;
		std::string tagName = "";
		getline(in, temp);
		
		std::string::size_type pos = temp.find(',');
		tagName = temp.substr(0, pos);
		temp.erase(0, pos + 1);
		auto pos1 = tagName.find_first_not_of(' ');
		auto pos2 = tagName.find_last_not_of(' ');
		tagName = tagName.substr(pos1, (pos2 - pos1) + 1);
		str << temp;
		if (in.peek() == EOF + 1) {
			return nullptr;
		}
		if (tagName == "c" || tagName == "C") {
			Vehicle* vehicle;
			vehicle = new Car(str);
			return vehicle;
		} else if (tagName == "r" || tagName == "R") {
			Vehicle* vehicle2;
			vehicle2 = new Racecar(str);
			return vehicle2;
		} else {
			throw "Unrecognized record type: [t]" ;
		}	
	}
}