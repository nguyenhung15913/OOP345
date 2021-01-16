#ifndef _SDDS_RESTAURANT_H
#define _SDDS_RESTAURANT_H
#include "Reservation.h"

namespace sdds  {
	class Restaurant {
		Reservation* res;
		size_t sizeOfRes;
	public:
		Restaurant(Reservation* reservations[], size_t cnt);
		size_t size() const;
		Restaurant(const Restaurant& res);
		Restaurant& operator=(const Restaurant& res);
		Restaurant& operator=(Restaurant&& src)noexcept;
		Restaurant(Restaurant&& src) noexcept;
		/*~Restaurant();*/
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& value);
	};
}



#endif // !_SDDS_RESTAURANT_H
