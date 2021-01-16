#ifndef _SDDS_BOOK_H
#define _SDDS_BOOK_H
#include <string>
#include <iostream>
#include <iomanip> 
#include "SpellChecker.h"
using namespace std;
namespace sdds {
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_publicCountry;
		size_t m_yearOfPublic;
		double m_price;
		std::string m_des;
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend ostream& operator<<(ostream& os, const Book& value);
		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_des);
		}
	};
}

#endif // !_SDDS_BOOK_H
