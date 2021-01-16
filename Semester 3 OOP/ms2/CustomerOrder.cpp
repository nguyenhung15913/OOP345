#include "CustomerOrder.h"
#include <algorithm>
size_t CustomerOrder::m_widthField = 0;
CustomerOrder::CustomerOrder() {
	m_cntItem = 0;
	m_lstItem = nullptr;
};
CustomerOrder::CustomerOrder(std::string& record) {
	Utilities util;
	size_t pos = 0;
	bool more = false;

	if (record.empty()) {
		m_name = "";
		m_product = "";
		m_cntItem = 0;
		m_lstItem = nullptr;
	}
	else {
		m_name = util.extractToken(record, pos, more);
		if (more) {
			m_product = util.extractToken(record, pos, more);
		}

	std::string strItems = record.substr(pos, record.length() - pos);
		m_cntItem = (std::count(strItems.begin(), strItems.end(), util.getDelimiter())) + 1;
		m_lstItem = new Item * [m_cntItem];

		for(size_t i = 0; i < m_cntItem&& more; i++) {
			m_lstItem[i] = new Item(util.extractToken(record, pos, more));
		}

		if (m_widthField < util.getFieldWidth()) {
			m_widthField = util.getFieldWidth();
		}
	}
	
	
}

CustomerOrder::~CustomerOrder() {
	for (unsigned int i = 0; i < m_cntItem; i++) {
		delete m_lstItem[i];
	}
	delete[] m_lstItem;
}

CustomerOrder::CustomerOrder(const CustomerOrder&) {
	throw "ERROR: Copy is not allowed!";
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
	m_lstItem = nullptr;
	m_cntItem = 0;
	*this = std::move(src);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
	if (this != &src) {
		for (unsigned int i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
		m_name = src.m_name;
		m_product = src.m_product;
		m_lstItem = src.m_lstItem;
		m_cntItem = src.m_cntItem;
		src.m_cntItem = 0;
		src.m_lstItem = nullptr;
	}
	return *this;
}

bool CustomerOrder::isOrderFilled() const {
	bool status = true;

	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (!m_lstItem[i]->m_isFilled) {
			status = false;
		}
	}
	return status;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
	for(unsigned int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == itemName) {
			return m_lstItem[i]->m_isFilled;
		}
	}
	return true;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == station.getItemName()) {
			if (station.getQuantity() > 0) {
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				station.updateQuantity();
				os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
			else {
				os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
		}
		
	}
}

void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;
	for (unsigned int i = 0; i < m_cntItem; i++) {
		os << "[" << setw(6) << setfill('0') << right << m_lstItem[i]->m_serialNumber << "] " << setfill(' ') << setw(m_widthField) << left << m_lstItem[i]->m_itemName;
		
		if (m_lstItem[i]->m_isFilled) {
			os << " - FILLED" << std::endl;
		}
		else {
			os << " - MISSING" << std::endl;
		}
	}
}