// Name: Hung Nguyen
// Seneca Student ID: 101984185
// Seneca email: hnguyen97@myseneca.ca
// Date of completion: 11/26/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _LINEMANAGER_H
#define _LINEMANAGER_H
#include "Workstation.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>
class LineManager {
	std::vector<Workstation*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;
	
	Workstation* m_firstStation = nullptr;
public:
	LineManager(const std::string& fileName, std::vector<Workstation*>& address, std::vector<CustomerOrder>& cusOrder);
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations() const;
	void displayStationsSorted() const;
};
#endif // !_LINEMANAGER_H
