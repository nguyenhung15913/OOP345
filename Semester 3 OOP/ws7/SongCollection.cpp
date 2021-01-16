#include "SongCollection.h"
namespace sdds {
	SongCollection::SongCollection(const char* name) {
		if (name == nullptr || name[0] == '\0') {
			throw "error";
		}
		else {
			std::string temp = "";
			std::ifstream file(name);
			if (!file)
			{
				std::cerr << "ERROR: Cannot open file [" << name << "].\n";
				return;
			}
			while (file && file.peek() != EOF)
			{
				std::string tempYear;
				Song colTemp;
				getline(file, temp);
				colTemp.title = temp.substr(0, 25);
				temp.erase(0, 25);
				colTemp.artist = temp.substr(0, 25);
				temp.erase(0, 25);
				colTemp.album = temp.substr(0, 25);
				temp.erase(0, 25);
				tempYear = temp.substr(0, 5);
				auto pos = tempYear.find_first_not_of(' ');
				if (pos != 0) {
					colTemp.realeaseYear = 0;
				}
				else {
					colTemp.realeaseYear = stoi(tempYear);
				}
				temp.erase(0, 5);
				colTemp.lengthOfSong = stoul(temp.substr(0, 5));
				temp.erase(0, 5);
				colTemp.m_price = stod(temp);
				//Remove spaces
				auto pos1 = colTemp.title.find_first_not_of(' '); // Find spaces before the string
				auto pos2 = colTemp.title.find_last_not_of(' '); //Find spaces after the string
				colTemp.title = colTemp.title.substr(pos1, (pos2 - pos1) + 1);
				pos1 = colTemp.artist.find_first_not_of(' ');
				pos2 = colTemp.artist.find_last_not_of(' ');
				colTemp.artist = colTemp.artist.substr(pos1, (pos2 - pos1) + 1);
				pos1 = colTemp.album.find_first_not_of(' ');
				pos2 = colTemp.album.find_last_not_of(' ');
				colTemp.album = colTemp.album.substr(pos1, (pos2 - pos1) + 1);
				collection.push_back(colTemp);
			}
			file.close();
		}
	}

	void SongCollection::display(std::ostream& out) const {
		size_t sum = 0;
		int min = 0;
		int sec = 0;
		int hour = 0;
		for_each(collection.begin(), collection.end(), [&](const Song& theSong) {
			sum += theSong.lengthOfSong;
		});
		hour = sum / 3600;
		sum = sum % 3600;
		min = sum / 60;
		sec = sum % 60;
		for_each(collection.begin(), collection.end(), [&](const Song& theSong) {
			out << theSong << endl;
		});
		out << "----------------------------------------------------------------------------------------" << endl;
		out << "| " << right << setw(77) << "Total Listening Time: " << hour << ":" << min << ":" << sec << " |" << endl;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		int min = 0;
		int sec = 0;
		min = theSong.lengthOfSong / 60;
		sec = theSong.lengthOfSong % 60;
		if (theSong.realeaseYear != 0) {
			out << "| " << left << setw(20) << theSong.title << " | " << setw(15) << theSong.artist << " | " << setw(20) << theSong.album << " | " << right << setw(6) << theSong.realeaseYear << " | " << min << ":";
			((sec < 10) ? (cout << "0" << sec) : cout << sec);
			out<< " | " << theSong.m_price << " |";
		}
		else {
			out << "| " << left << setw(20) << theSong.title << " | " << setw(15) << theSong.artist << " | " << setw(20) << theSong.album << " | " << right << setw(6) << "" << " | " << min << ":" << sec << " | " << theSong.m_price << " |";
		}
		
		return out;
	}

	void SongCollection::sort(string name) {
		if (name == "title") {
			std::sort(collection.begin(), collection.end(), [](Song& theSong, Song& theSongb) {return theSong.title < theSongb.title; });
		} 
		if (name == "length") {
			std::sort(collection.begin(), collection.end(), [](Song& theSong, Song& theSongb) {return theSong.lengthOfSong < theSongb.lengthOfSong; });
		}
		if (name == "album") {
			std::sort(collection.begin(), collection.end(), [](Song& theSong, Song& theSongb) {return theSong.album < theSongb.album; });
		}	
	}

	void SongCollection::cleanAlbum() {
		for_each(collection.begin(), collection.end(), [](Song& theSong) {
			if (theSong.album == "[None]") {
				theSong.album = " ";
			}
		});
	}

	bool SongCollection::inCollection(const char* name) const {
		return any_of(collection.begin(), collection.end(), [=](const Song& song) {return song.artist == name ; });
	}

	std::list<Song> SongCollection::getSongsForArtist(const char* name) const {
		auto i = count_if(collection.begin(), collection.end(), [&name](const Song& theSong) {
			return theSong.artist == name;
			});
		
		list<Song> theSongs(i);

		copy_if(collection.begin(), collection.end(), theSongs.begin(), [&name](const Song& song) {
			return song.artist == name;
			});
			return theSongs;
	}
}