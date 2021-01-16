#ifndef _SDDS_PAIRSUMMABLE_H
#define _SDDS_PAIRSUMMABLE_H
#include "Pair.h"

namespace sdds {
	template<typename K, typename V>
	class PairSummable : public Pair<K, V> {
		static V initial;
		static size_t minField;
	public:
		PairSummable() {};

		PairSummable(const K& key, const V& value = initial) : Pair<K, V>(key, value) {
			if (key.size() > minField) {
				minField = key.size() + 1;
			}
		};

		PairSummable& operator+=(const PairSummable& item) {
			if (this->key() == item.key() && this != &item) {
				*this = PairSummable(item.key(),  item.value());
			}
			return *this;
		}
		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(minField);
			os << Pair<K, V>::key() << ": " << Pair<K, V>::value() << std::endl;
			os.unsetf(std::ios::left);		
		}


	};


	template <typename K, typename V>
	size_t PairSummable<K, V>::minField = 0;

	template <>
	std::string PairSummable<std::string, std::string>::initial = "";

	template <>
	int PairSummable<std::string, int>::initial = 0;

	template <>
	PairSummable< std::string, std::string >& PairSummable<std::string, std::string>::operator+=(const PairSummable& item) {
		std::string temp;
		if (this->value() != "") {
			temp = this->value() + ", " + item.value();
		}
		else
		{
			temp = item.value();
		}
		*this = PairSummable(this->key(), temp);
		return *this;
	}


}


#endif // !_SDDS_PAIRSUMMABLE_H
