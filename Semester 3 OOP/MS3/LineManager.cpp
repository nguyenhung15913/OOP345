// Name: Hung Nguyen
// Seneca Student ID: 101984185
// Seneca email: hnguyen97@myseneca.ca
// Date of completion: 11/26/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"

LineManager::LineManager(const std::string& fileName, std::vector<Workstation*>& address, std::vector<CustomerOrder>& cusOrder) {
	Utilities utils;
	std::ifstream file(fileName);
	if (!file.is_open()) {
		throw string("ERROR: Failed to open the file");
	}

	std::string temp = "";
	std::string CurStation = "";
	std::string NextStation = "";
	size_t pos;
	bool more;
	while (!file.eof()) {
		pos = 0;
		std::getline(file, temp);

		CurStation = utils.extractToken(temp, pos, more);
		if (more) {
			NextStation = utils.extractToken(temp, pos, more);
		}
		else {
			NextStation = "";
		}

		for (size_t i = 0; i < address.size(); i++) {
			if (address[i]->getItemName() == CurStation) {
				for (size_t j = 0; j < address.size(); j++) {
					if (address[j]->getItemName() == NextStation) {
						address[i]->setNextStation(*address[j]);
					}
				}

				if (m_firstStation == nullptr) {
					m_firstStation = address[i];
				}
			}
		}
	}

	
	file.close();

	for (size_t k = 0; k < cusOrder.size(); k++) {
		ToBeFilled.push_back(std::move(cusOrder[k]));
	}

	m_cntCustomerOrder = ToBeFilled.size();

	AssemblyLine = address;
}

bool LineManager::run(std::ostream& os) {
	static size_t cnt = 0;
	cout << "Line Manager Iteration: " << ++cnt << endl;

	if (!ToBeFilled.empty()) {
		*m_firstStation += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->runProcess(os);
	}

	for (size_t j = 0; j < AssemblyLine.size(); j++) {
		AssemblyLine[j]->moveOrder();

		CustomerOrder cusOrder;
		if (AssemblyLine[j]->getIfCompleted(cusOrder)) {
			Completed.push_back(std::move(cusOrder));
		}
	}

	if (Completed.size() == m_cntCustomerOrder) {
		return true;
	}
	else {
		return false;
	}
}

void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (size_t i = 0; i < Completed.size(); i++) {
		Completed[i].display(os);
	}
}

void LineManager::displayStations() const {
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->display(std::cout);
	}
}

void LineManager::displayStationsSorted() const {
	const Workstation* station = m_firstStation;
	do  {
		station->display(std::cout);
		station = station->getNextStation();
	} while (station != nullptr);
	
	 
}