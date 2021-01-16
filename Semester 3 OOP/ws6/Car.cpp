#include "Car.h"
namespace sdds {
	Car::Car(std::istream& file) {
		std::string temp = "";
		getline(file, temp);
		std::string::size_type pos = temp.find(',');
		maker = temp.substr(0, pos);
		temp.erase(0, pos + 1);
		pos = temp.find(',');
		m_condition = temp.substr(0, pos);	
		if (m_condition.length() == 0 || m_condition == " ") {
			m_condition = "n";
		}
		temp.erase(0, pos + 1);
		pos = temp.find(',');
		if (pos > 0) {
			top_speed_str = temp.substr(0, pos);
		}
		temp.erase(0, pos + 1);
		//Remove spaces
		auto pos1 = maker.find_first_not_of(' '); // Find spaces before the string
		auto pos2 = maker.find_last_not_of(' '); //Find spaces after the string
		maker = maker.substr(pos1, (pos2 - pos1) + 1);
		pos1 = m_condition.find_first_not_of(' '); // Find spaces before the string
		pos2 = m_condition.find_last_not_of(' '); //Find spaces after the string
		m_condition = m_condition.substr(pos1, (pos2 - pos1) + 1);
		pos1 = top_speed_str.find_first_not_of(' '); // Find spaces before the string
		pos2 = top_speed_str.find_last_not_of(' '); //Find spaces after the string
		top_speed_str = top_speed_str.substr(pos1, (pos2 - pos1) + 1);
		pos1 = temp.find_first_not_of(' '); // Find spaces before the string
		pos2 = temp.find_last_not_of(' '); //Find spaces after the string
		temp = temp.substr(pos1, (pos2 - pos1) + 1);	
		if (m_condition != "n" && m_condition != "N" && m_condition != "u" && m_condition != "U" && m_condition != "b" && m_condition != "B") {
			throw "Invalid record!";
		}
		else {
			//Determine if top speed is a number 
			bool isNumber = (top_speed_str.find_first_not_of("0123456789") == std::string::npos);
			if (isNumber) {
				top_speed = std::stod(top_speed_str);
			}
			else {
				throw "Invalid record!";
			}
			top_speed_str = temp;
		}
	}

	std::string Car::condition() const {
		if (m_condition == "n" || m_condition == "N") {
			return "new";
		}
		else if (m_condition == "u" || m_condition == "U") {
			return "used";
		}
		else {
			return "broken";
		}
	}

	double Car::topSpeed() const {
		return top_speed;
	}

	void Car::display(std::ostream& out) const {	
		out << "| " << std::right << setw(10) << getMaker() << " | "<< std::left << setw(6) << condition() << " | " << setw(6) << fixed << setprecision(2) << topSpeed() << " |";
	}

	std::string& Car::topSpeedStr() {
		return top_speed_str;
	}

	std::string Car::getMaker() const {
		return maker;
	}
}