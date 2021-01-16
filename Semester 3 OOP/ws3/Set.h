#ifndef _SDDS_SET_H
#define _SDDS_SET_H
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
	
	template<typename T, unsigned int N>
	class Set {
		T m_array[N];
		size_t m_size;
	public:
		Set() : m_array{}, m_size(0) {};

		size_t size() const {
			return m_size;
		}

		const T& operator[](size_t idx) const {
			return m_array[idx];
		}

		void operator+=(const T& item) {
			
			if (m_size < N ) {
				m_array[m_size] = item;
				++m_size;
			}
		}			
	};

}


#endif // !_SDDS_SET_H
