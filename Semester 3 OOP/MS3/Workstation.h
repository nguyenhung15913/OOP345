// Name: Hung Nguyen
// Seneca Student ID: 101984185
// Seneca email: hnguyen97@myseneca.ca
// Date of completion: 11/26/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _WORKSTATION_H
#define _WORKSTATION_H
#include <deque>
#include "CustomerOrder.h"
class Workstation: public Station {
	std::deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation;
public:
	
	Workstation(Workstation&) = delete;
	Workstation& operator=(Workstation&) = delete;
	Workstation(Workstation&&) = delete;
	Workstation& operator=(Workstation&&) = delete;

	Workstation(const std::string& record);
	void runProcess(std::ostream&);
	bool moveOrder();
	void setNextStation(Station& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&) const;
	Workstation& operator+=(CustomerOrder&&);
};


#endif // !_WORKSTATION_H
