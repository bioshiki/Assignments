#pragma once
// Name: Xingjian Yuan
// Seneca Student ID: 126105188
// Seneca email: xyuan22@myseneca.ca
// Date of completion: 2019-11-12
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef OOP345_SONGCOLLECTION_H
#define OOP345_SONGCOLLECTION_H
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <list>
namespace sdds {
	struct Song {
		std::string sartist;
		std::string stitle;
		std::string salbum;
		double m_price;
		int syear;
		int slength;
	};
	class SongCollection {
		std::vector<Song> sc;
		std::string trim(std::string org);
		Song newSong(std::string src);
	public:
		void sort(std::string field);
		SongCollection(std::string file);
		void display(std::ostream& out) const;
		void cleanAlbum();
		bool inCollection(std::string art) const;
		std::list<Song> getSongsForArtist(std::string art) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}

#endif