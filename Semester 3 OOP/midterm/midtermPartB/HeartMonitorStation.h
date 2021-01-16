#ifndef _SDDS_HEARTMONITORSTATION_H
#define _SDDS_HEARTMONITORSTATION_H
#include <iostream>
namespace sdds {
	class HeartMonitorStation {
		float* m_heartBeatAvg = nullptr;
		unsigned m_maxNoOfbeatAvg = 0u;
		unsigned m_insOfStation = 0u;
	public:
		HeartMonitorStation();
		HeartMonitorStation(const unsigned maxNoOfbeatAvg);
		HeartMonitorStation(const HeartMonitorStation& value);
		HeartMonitorStation& operator=(const HeartMonitorStation& value);
		HeartMonitorStation(HeartMonitorStation&& value) noexcept;
		HeartMonitorStation& operator= (HeartMonitorStation&& value) noexcept;
		~HeartMonitorStation();
		unsigned numHeartStations();
		unsigned maxSize();
	};
	
}

#endif // !_SDDS_HEARTMONITORSTATION_H

