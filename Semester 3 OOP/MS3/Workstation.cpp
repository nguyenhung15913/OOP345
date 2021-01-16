// Name: Hung Nguyen
// Seneca Student ID: 101984185
// Seneca email: hnguyen97@myseneca.ca
// Date of completion: 11/26/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"

Workstation::Workstation(const std::string& record):Station(record) {
	this->m_pNextStation = nullptr;
}

void Workstation::runProcess(std::ostream& os) {
	if (m_orders.empty()) {
		return;
	}

	m_orders.front().fillItem(*this, os);
}

bool Workstation::moveOrder() {
	if (m_orders.empty()) {
		return false;
	}

	if (m_orders.front().isItemFilled(this->getItemName()) && m_pNextStation) {
		*m_pNextStation += std::move(m_orders.front());
		m_orders.pop_front();
		return true;
	}
	else {
		return false;
	}
}

void Workstation::setNextStation(Station& station) {
	m_pNextStation = (Workstation*) &station;
}

const Workstation* Workstation::getNextStation() const {
	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order) {
	if (m_orders.empty()) {
		return false;
	}

	if (m_orders.front().isOrderFilled()) {
		order = std::move(m_orders.front());
		m_orders.pop_front();
		return true;
	}
	else {
		return false;
	}
}

void Workstation::display(std::ostream& os) const {
	if (m_pNextStation == nullptr) {
		os << getItemName() << " --> " << "END OF LINE" << endl;
	}
	else {
		os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
	}
}

Workstation& Workstation::operator+=(CustomerOrder&&order) {
	m_orders.push_back(std::move(order));
	return *this;
}