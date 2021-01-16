 #ifndef _SDDS_COLLECTION_H
#define _SDDS_COLLECTION_H
#include <iostream>
#include <string>
using namespace std;
namespace sdds {
	template<typename T>
	class Collection {
		std::string m_name;
		T* m_item;
		size_t m_size;
		void (*observer)(const Collection<T>&, const T&) = nullptr;
	public:
		Collection(std::string name) :m_item{}, m_size(0) {
			m_name = name;
		}
		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		~Collection() {
			delete[] m_item;
		}

		const std::string& name() const {
			return m_name;
		}

		size_t size() const {
			return m_size;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			this->observer = observer;
		}

		Collection<T>& operator+=(const T& item) {
			for (auto i = 0u; i < m_size; i++) {
				if (this->m_item[i].title() == item.title()) {
					return *this;
				}
			}
			T* tmp = nullptr;
			tmp = new T[m_size + 1];
			for (auto i = 0u; i < m_size; i++) {
				tmp[i] = this->m_item[i];		
			}
			tmp[m_size] = item;
			delete[] m_item;
			m_item = tmp;
			++m_size;
			if (this->observer != nullptr) {
				observer(*this, m_item[m_size - 1]);
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			if (idx >= m_size) {
				std::string msg = "Bad index [";
				msg += std::to_string(idx);
				msg += "]. Collection has [";
				msg += std::to_string(m_size);
				msg += "] items.";
				throw std::out_of_range(msg);
			}
			return this->m_item[idx];
		}
		T* operator[](std::string title) const {
			bool ok = false;
			T* temp = nullptr;
			for (size_t i = 0; i < m_size; i++) {
				if (m_item[i].title() == title) {
					ok = true;
					temp =  &m_item[i];
				}
			}
			if (ok == false) {
				return nullptr;
			}
			else {
				return temp;
			}
		}
	};

	template<typename T>
	ostream& operator<<(ostream& os, const Collection<T>& value) {
		for (size_t i = 0; i < value.size(); i++) {
			os << value[i];
		}
		return os;
	}
}
#endif // !_SDDS_COLLECTION_H
