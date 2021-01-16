#include "SpellChecker.h"
namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		int count = 0;
		if (!file) {
			throw "Bad file name!";
		}
		else {
			do
			{
				std::string temp = "";
				std::getline(file, temp);

				// if the previous operation failed, the "file" object is
				//   in error mode
				if (file)
				{
					std::string::size_type pos = temp.find(' ');
					
					m_badWords[count] = temp.substr(0, pos);
					temp.erase(0, pos + 1);
					auto pos1 = temp.find_first_not_of(' ');
					temp.erase(0, pos1);
					m_goodWords[count] = temp;
					++count;
				}
			} while (file);
			file.close();
		}
	}

	void SpellChecker::operator()(std::string& text) const {
		std::size_t found;
		std::size_t found2;
			for (int i = 0; i < 5; i++) {
				found = text.find(m_badWords[i]);
				if (found < text.length()) {
					text.replace(found, m_badWords[i].length(), m_goodWords[i]);
					found2 = text.find(m_badWords[i]);
					if (found2 < text.length()) {
						text.replace(found2, m_badWords[i].length(), m_goodWords[i]);
					}
				}
			}	
			
	}
}


