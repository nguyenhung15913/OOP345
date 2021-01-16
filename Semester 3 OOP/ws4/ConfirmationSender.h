#ifndef _SDDS_CONFIRMATIONSENDER_H
#define  _SDDS_CONFIRMATIONSENDER_H
#include "Restaurant.h"
namespace sdds {
	class ConfirmationSender {
		const sdds::Reservation** sender;
		size_t size;
	public:
		size_t getSize() const;
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& value);
		ConfirmationSender& operator=(const ConfirmationSender& value);
		ConfirmationSender& operator=(ConfirmationSender&& value)noexcept;
		ConfirmationSender(ConfirmationSender&& value) noexcept;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& value);
	};

}

#endif // !_SDDS_CONFIRMATIONSENDER_H