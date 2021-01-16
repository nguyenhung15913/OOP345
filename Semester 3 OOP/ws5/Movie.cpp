#include "Movie.h"
namespace sdds {
	Movie::Movie() {
		m_title = "";
		m_year = 0;
		m_des = "";
	}
	const std::string& Movie::title() const {
		return m_title;
	}
	Movie::Movie(const std::string& strMovie) {
		std::string temp = strMovie;
		auto pos = temp.find(',');
		m_title = temp.substr(0, pos);
		temp.erase(0, pos + 1);
		pos = temp.find(',');
		m_year = std::stoi(temp.substr(0, pos));
		temp.erase(0, pos + 1);
		m_des = temp;
		//trim spaces
		auto pos1 = m_des.find_first_not_of(' ');
		auto pos2 = m_des.find_last_not_of(' ');
		m_des = m_des.substr(pos1, (pos2 - pos1) + 1);
		pos1 = m_title.find_first_not_of(' ');
		pos2 = m_title.find_last_not_of(' ');
		m_title = m_title.substr(pos1, (pos2 - pos1) + 1);
	}

	ostream& operator<<(ostream& os, const Movie& value) {
		os << setw(40) <<value.m_title << " | " << setw(4) <<value.m_year << " | " << value.m_des << endl;
		return os;
	}
}