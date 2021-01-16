#ifndef _SDDS_MOVIE_H
#define _SDDS_MOVIE_H
#include <iostream>
#include <string>
#include "SpellChecker.h"
#include <iomanip>
using namespace std;
namespace sdds {
	class Movie {
		std::string m_title;
		int m_year;
		std::string m_des;
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(m_des);
		}
		friend ostream& operator<<(ostream& os, const Movie& value);
	};
}
#endif // !_SDDS_MOVIE_H
