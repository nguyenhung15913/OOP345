#include "Book.h"
namespace sdds {
	Book::Book() {
		m_author = "";
		m_title = "";
		m_publicCountry = "";
		m_yearOfPublic = 0;
		m_price = 0;
		m_des = "";
	}
	const std::string& Book::title() const {
		return m_title;
	}

	const std::string& Book::country() const {
		return m_publicCountry;
	}

	const size_t& Book::year() const {
		return m_yearOfPublic;
	}

	double& Book::price() {
		return m_price;
	}

	Book::Book(const std::string& strBook) {
		m_author = "";
		m_title = "";
		m_publicCountry = "";
		m_yearOfPublic = 0;
		m_price = 0;
		m_des = "";
		std::string temp = strBook;
		std::string::size_type pos = temp.find(',');
		m_author = temp.substr(0, pos);
		temp.erase(0, pos + 1);
		pos = temp.find(',');
		m_title = temp.substr(0, pos);
		temp.erase(0, pos + 1);
		pos = temp.find(',');
		m_publicCountry = temp.substr(0, pos);
		temp.erase(0, pos + 1);
		pos = temp.find(',');
		m_price = std::stod(temp.substr(0, pos));
		temp.erase(0, pos + 1);
		pos = temp.find(',');
		m_yearOfPublic = std::stoi(temp.substr(0, pos));
		temp.erase(0, pos + 1);
		pos = temp.find(',');
		m_des = temp;
		// delete leading spaces
		auto pos1 = m_title.find_first_not_of(' '); // Find spaces before the string
		auto pos2 = m_title.find_last_not_of(' '); //Find spaces after the string
		m_title = m_title.substr(pos1, (pos2 - pos1) + 1); // Take only string without leading and ending spaces
		pos1 = m_publicCountry.find_first_not_of(' ');
		pos2 = m_publicCountry.find_last_not_of(' ');
		m_publicCountry = m_publicCountry.substr(pos1, (pos2 - pos1) + 1);
		pos1 = m_des.find_first_not_of(' ');
		m_des.erase(0, pos1);
		pos1 = m_author.find_first_not_of(' ');
		pos2 = m_author.find_last_not_of(' ');
		m_author = m_author.substr(pos1, (pos2 - pos1) + 1);
	}

	ostream& operator<<(ostream& os, const Book& value) {
		os << setw(20) << value.m_author << " | " << setw(22) << value.title() << " | " << setw(5) << value.country() << " | " << setw(4) << value.year()  << " | " << std::fixed << std::setprecision(2)  << setw(6) << value.m_price << " | " << value.m_des << endl;
		return os;
	}

}