// Name: Hung Nguyen
// Seneca Student ID: 101984185
// Seneca email: hnguyen97@myseneca.ca
// Date of completion: 11/26/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _SDDS_STATION_H
#define _SDDS_STATION_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

	class Station {
	private:
		unsigned int station_id;
		std::string nameOfItem;
		std::string desOfStation;
		unsigned int serialNumb;
		unsigned int itemLeft;
		//static data
		static unsigned int m_widthField;
		static unsigned int id_generator;
	public:
		Station(const std::string&);
		const std::string& getItemName() const;
		unsigned int getNextSerialNumber();
		unsigned int getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
	


#endif // !_SDDS_STATION_H
