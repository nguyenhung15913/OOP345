#include "Racecar.h"
namespace sdds {
	Racecar::Racecar(std::istream& in) :  Car(in) {
		std::string temp = "";
		temp = topSpeedStr();
		m_booster = std::stod(temp);
		m_booster = (m_booster * Car::topSpeed()) ;
		m_booster += Car::topSpeed();
	}

	void Racecar::display(std::ostream& out) const {
		out << "| "  <<std::right << setw(10) << Car::getMaker() << " | " << std::left <<setw(6) << Car::condition() << " | " << setw(6) << fixed << setprecision(2) << m_booster << " |*";
	}

	double Racecar::topSpeed() const {
		return m_booster;
	}
}