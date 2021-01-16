#include "HeartMonitorStation.h"
namespace sdds {
	HeartMonitorStation::HeartMonitorStation() {
		m_maxNoOfbeatAvg = 50;
		m_insOfStation++;
	}

	HeartMonitorStation::HeartMonitorStation(const unsigned maxNoOfbeatAvg) {
		m_maxNoOfbeatAvg = maxNoOfbeatAvg;
		m_heartBeatAvg = new float[m_maxNoOfbeatAvg];
		m_insOfStation++;
	}

	HeartMonitorStation::HeartMonitorStation(const HeartMonitorStation& value) {
		*this = value;
	}

	HeartMonitorStation& HeartMonitorStation::operator=(const HeartMonitorStation& value) {
		if (this != &value) {
			delete[] m_heartBeatAvg;
			m_heartBeatAvg = new float[value.m_maxNoOfbeatAvg];
			for (unsigned i = 0u; i < value.m_maxNoOfbeatAvg; i++) {
				m_heartBeatAvg[i] = value.m_heartBeatAvg[i];
			}
			m_maxNoOfbeatAvg = value.m_maxNoOfbeatAvg;
			m_insOfStation = value.m_insOfStation;
		}
		return *this;
	}

	HeartMonitorStation::HeartMonitorStation(HeartMonitorStation&& value) noexcept {
		*this = std::move(value);
	}

	HeartMonitorStation& HeartMonitorStation::operator= (HeartMonitorStation&& value) noexcept {
		if (this != &value) {
			delete[] m_heartBeatAvg;
			m_heartBeatAvg = value.m_heartBeatAvg;
			value.m_heartBeatAvg = nullptr;
			m_maxNoOfbeatAvg = value.m_maxNoOfbeatAvg;
			value.m_maxNoOfbeatAvg = 0u;
			m_insOfStation = value.m_insOfStation;
			value.m_insOfStation = 0u;
		}
		return *this;
	}

	HeartMonitorStation::~HeartMonitorStation() {
		if (m_heartBeatAvg != nullptr) {
			delete[] m_heartBeatAvg;
			m_heartBeatAvg = nullptr;
		}
	}

	unsigned HeartMonitorStation::maxSize() {
		return m_maxNoOfbeatAvg;
	}

	unsigned HeartMonitorStation::numHeartStations() {
		return m_insOfStation;
	}
}