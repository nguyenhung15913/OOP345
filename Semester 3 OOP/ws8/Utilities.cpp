// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (unsigned i = 0; i < desc.size(); i++)
		{
			for (unsigned k = 0; k < price.size(); k++)
			{
				if (desc[i].code == price[k].code)
				{
					Product* product = nullptr;
					product = new Product(desc[i].desc, price[k].price);
					product->validate();
					priceList += product;
					delete product;
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (unsigned i = 0; i < desc.size(); i++)
		{
			for (unsigned k = 0; k < price.size(); k++)
			{
				if (desc[i].code == price[k].code)
				{
					std::unique_ptr<Product> product( new Product(desc[i].desc, price[k].price));
					product->validate();
					priceList += product;
				}
			}
		}

		return priceList;
	}
}