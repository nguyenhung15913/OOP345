#ifndef _SDDS_SETSUMMABLE_H
#define _SDDS_SETSUMMABLE_H
#include "Set.h"
#include <cstring>

namespace sdds {
	template<typename T, int N>
	class SetSummable : public Set<T, N> {
		
	public:
		
		T accumulate(const std::string& filter) const {
			T sum(filter);
			for (size_t i = 0; i < this->size(); i++)
			{
				if((*this)[i].key() == filter)
				sum += (*this)[i];
			}
			return sum;
		}
	};
	
	
}

#endif // !_SDDS_SETSUMMABLE_H
