// Name: Hung Nguyen
// Seneca Student ID: 101984185
// Seneca email: hnguyen97@myseneca.ca
// Date of completion: 11/26/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _CUSTOMERORDER_H
#define _CUSTOMERORDER_H
#include "Utilities.h"
#include "Station.h"
struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder {
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	Item** m_lstItem;
	static size_t m_widthField;
public:
	CustomerOrder();
	CustomerOrder(std::string& record);
	CustomerOrder(const CustomerOrder&);
	CustomerOrder& operator=(const CustomerOrder&) = delete;
	CustomerOrder(CustomerOrder&&) noexcept;
	CustomerOrder& operator=(CustomerOrder&&) noexcept;
	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
	~CustomerOrder();
};



#endif // !_CUSTOMERORDER_H
