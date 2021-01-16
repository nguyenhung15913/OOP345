// Name: Hung Nguyen
// Seneca Student ID: 101984185
// Seneca email: hnguyen97@myseneca.ca
// Date of completion: 11/26/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _SDDS_UTILITIES_H
#define _SDDS_UTILITIES_H
#include <string>
#include <iostream>

	class Utilities {
		size_t m_widthField = 1;
		static char m_delimiter;
	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
	



#endif // !_SDDS_UTILITIES_H
