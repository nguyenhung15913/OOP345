#include "Restaurant.h"
namespace sdds {
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
		res = nullptr;
		this->sizeOfRes = cnt;
		if (reservations != nullptr) {
			res = new Reservation[cnt + 1];
			for (size_t i = 0; i < cnt; i++) {
				res[i] = *reservations[i];
			}
		}
	}

	size_t Restaurant::size() const {
		return sizeOfRes;
	}

	Restaurant::Restaurant(const Restaurant& res) {
		if (this != &res) {
			this ->res = nullptr;
			delete[] this->res;
			this->res = nullptr;
			*this = res;
		}
	}

	Restaurant& Restaurant::operator=(const Restaurant& res) {
		if (this != &res) {
			delete[] this->res;
			this->res = new Reservation[res.sizeOfRes + 1];
			this->res= res.res;
			this->sizeOfRes = res.sizeOfRes;

		}
		return *this;
	}

	Restaurant& Restaurant::operator=(Restaurant&& src) noexcept {
		if (this != &src)  {
			res = nullptr;
			delete[] res;
			res = src.res;
			src.res = nullptr;
			sizeOfRes = src.sizeOfRes;
			src.sizeOfRes = 0;
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& src) noexcept {
		*this = std::move(src);
	}

	/*Restaurant::~Restaurant() {
		if (res != nullptr) {
			delete[] res;
			res = nullptr;
		}
	}*/

	std::ostream& operator<<(std::ostream& os, const Restaurant& value) {
		if (value.sizeOfRes <= 0) {
			os << "--------------------------" << endl;
			os << "Fancy Restaurant" << endl;
			os << "--------------------------" << endl;
			os << "The object is empty!" << endl;
			os << "--------------------------" << endl;
		}
		else {
			os << "--------------------------" << endl;
			os << "Fancy Restaurant" << endl;
			os << "--------------------------" << endl;
			for (size_t i = 0; i < value.sizeOfRes; i++) {
				os << value.res[i];
			}
			os << "--------------------------" << endl;
		}
		return os;
	}
}