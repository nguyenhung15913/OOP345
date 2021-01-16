
#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
unsigned int g_sysClock;

namespace sdds {
	Event::Event() :
		event_desc{ nullptr },
		time_start{ 0 } {};

	void Event::display() {
		int hour, minutes, second;
		second = time_start;
		hour = second / 3600;
		second = second % 3600;
		minutes = second / 60;
		second = second % 60;
		static int counter = 0;		
			counter++;
			if (event_desc != nullptr && event_desc[0] != '\0') {
				std::cout.width(3);
				std::cout  << counter << ". " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << second  << " -> " << event_desc << std::endl;
				std::cout << setw(0) << setfill(' ');
			}
			else {
				std::cout.width(3);
				std::cout << counter << ". " << "[ No Event ]" << std::endl;
			}
		
	}

	void Event::setDescription(const char* value) {
		

		if (value != nullptr && value[0] != '\0') {
			if (event_desc != nullptr) {
				delete[] event_desc;
			}
			event_desc = nullptr;
			event_desc = new char[strlen(value) + 1];
			strcpy(event_desc, value);
			time_start = g_sysClock;
		}
		else {
			delete[] event_desc;
			event_desc = nullptr;
			time_start = 0;

		}
	}

	Event::Event(const Event& value) {
		

		*this = value;
	}

	Event& Event::operator=(const Event& value) {
		if (value.event_desc != nullptr && value.event_desc[0] != '\0') {
			if (event_desc != nullptr) {
				delete[] event_desc;
			}
			event_desc = nullptr;
			event_desc = new char[strlen(value.event_desc) + 1];
			strcpy(event_desc, value.event_desc);
			time_start = value.time_start;
		}
		else {
			delete[] event_desc;
			event_desc = nullptr;
			time_start = 0;

		}
		return *this;
	}

	Event::~Event() {
		delete[] event_desc;
		time_start = 9;
	}

}