#ifndef _SDDS_TIMEDEVENTS_H
#define _SDDS_TIMEDEVENTS_H
#include <chrono>
#include <string>
#include <iostream>


namespace sdds {
	constexpr int MAX_NO_OBJ = 7;
	class TimedEvents {		
		int numOfRec;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;
		struct {
			std::string eventName;
			std::string unitsOfTime;
			std::chrono::steady_clock::duration durOfEvent;
		} record[MAX_NO_OBJ];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char* eventName);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& value);
	};
	
}

#endif // !_SDDS_TIMEDEVENTS_H
