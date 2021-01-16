#ifndef _SDDS_SONGCOLLECTION_H
#define _SDDS_SONGCOLLECTION_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <list>
#include <numeric>
#include <functional>
using namespace std;
namespace sdds {
	struct Song {
		std::string artist;
		std::string title;
		double m_price;
		std::string album;
		size_t realeaseYear;
		size_t lengthOfSong;
	};

	class SongCollection {
		vector<Song> collection;
	public:
		SongCollection(const char*name);
		void display(std::ostream& out) const;
		void sort(string);
		void cleanAlbum();
		bool inCollection(const char*) const;
		std::list<Song> getSongsForArtist(const char*) const;
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !_SDDS_SONGCOLLECTION_H
