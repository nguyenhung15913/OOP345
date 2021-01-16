#define _CRT_SECURE_NO_WARNINGS
#include "TimedEvents.h"
#include <cstring>
#include <string>

namespace sdds {
	TimedEvents::TimedEvents() : numOfRec(0) {
		for (int i = 0; i < 7; i++)
		{
			record[i].eventName = "";
		}
	};

	void TimedEvents::startClock() {
		startTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		endTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* eventName) {
				this->record[numOfRec].eventName = eventName;
				this->record[numOfRec].unitsOfTime = "nanoseconds";
				this->record[numOfRec].durOfEvent = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				numOfRec++;
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& value) {
		os << "Execution Times:" << std::endl << "--------------------------" << std::endl;
		for (int i = 0; i < value.numOfRec; i++) {
			os << value.record[i].eventName << " " << value.record[i].durOfEvent.count() <<" "<< value.record[i].unitsOfTime << std::endl;
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}