#ifndef _SDDS_RECORDSET_H
#define _SDDS_RECORDSET_H
#include <string>
#include <fstream> 
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
	class RecordSet {
	std::string* str;
	size_t noOfRec;
	public:
		RecordSet();
		RecordSet(const string& file);
		RecordSet(const RecordSet& value);
		RecordSet& operator=(const RecordSet& value) ;
		~RecordSet();
		size_t size();
		std::string getRecord(size_t);
		RecordSet(RecordSet&& ) noexcept;
		RecordSet& operator=( RecordSet&& ) noexcept;
	};
}



#endif // !_SDDS_RECORDSET_H
