#ifndef _SDDS_PAIR_H
#define _SDDS_PAIR_H
#include <iostream>
using namespace std;
namespace sdds {
	template<typename K, typename V>
	class Pair {
		K m_key;
		V m_value;
	public: 
		Pair() {
			m_key = {};
			m_value = {};
		}
		Pair(const K& key, const V& value) {
			m_key = key;
			m_value = value;
		}
		Pair& operator=(const Pair& value) {
			if (this != &value) {
				m_key = value.m_key;
				m_value = value.m_value;
			}
			return *this;
		}
		const K& key() const {
			return m_key;
		}
		const V& value() const {
			return m_value;
		}
		virtual void display(std::ostream& os) const {
			os << m_key << " : " << m_value << endl;
		}
	};

	template<typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
		pair.display(os);
		return os;
	}

	
}


#endif // !_SDDS_PAIR_H

