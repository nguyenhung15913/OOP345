#ifndef _SDDS_EVENT_H
#define _SDDS_EVENT_H

extern unsigned int g_sysClock ;

namespace sdds {
	
	class Event {
		char* event_desc;
		unsigned int time_start;
	public:
		Event();
		Event(const Event& value);
		Event& operator=(const Event& value);
		void display();
		void setDescription(const char* value);
		~Event();
	};
}


#endif // !_EVENT_H

