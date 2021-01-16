#include "ConfirmationSender.h"
namespace sdds {
	ConfirmationSender::ConfirmationSender() {
		size = 0;
		sender = nullptr;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool ok = false;
		const Reservation** senderTemp = nullptr ;
			for (size_t i = 0; i < size; i++) {
				if (sender[i] == &res) {
					ok = true;
				}
				else {
					ok = false;
				}
			}
			if (ok == false) {
				senderTemp = new const Reservation * [size + 1];
				for (size_t i = 0; i < size; i++) {
					senderTemp[i] = sender[i];
				}
				senderTemp[size] = &res;
				++size;
				delete[] sender;
				sender = senderTemp;
			}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
			for (size_t i = 0; i < size; i++) {
				if (sender[i] == &res) {
					sender[i] = nullptr;
					--size;
				}
			}
		return *this;
	}

	size_t ConfirmationSender::getSize() const {
		return size;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& value) {
		if (this != &value) {
			*this = value;
		}
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& value) {
		if (this != &value) {
			sender = nullptr;
			delete[] sender;
			sender = nullptr;
			size = value.size;
			sender = new const Reservation * [value.size + 1];
			for (size_t i = 0; i < size; i++) {
				sender[i] = value.sender[i];
			}
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& value)noexcept {
		if (this != &value) {
			sender = nullptr;
			delete[] sender;
			sender = value.sender;
			value.sender = nullptr;
			size = value.size;
			value.size = 0;
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& value)noexcept {
		*this = std::move(value);
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& value) {
		if(value.sender == nullptr) {
			os << "--------------------------" << endl;
			os << "Confirmations to Send" << endl;
			os << "--------------------------" << endl;
			os << "The object is empty!" << endl;
			os << "--------------------------" << endl;
		}
		else {
			os << "--------------------------" << endl;
			os << "Confirmations to Send" << endl;
			os << "--------------------------" << endl;
			for (size_t i = 0; i < value.getSize(); i++) {
				if (value.sender[i] != nullptr) {
					os << *value.sender[i];
				}
				
			}
			os << "--------------------------" << endl;
		}
		return os;
	}
}
