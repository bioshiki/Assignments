// Name: Xingjian Yuan
// Seneca Student ID: 126105188
// Seneca email: xyuan22@myseneca.ca
// Date of completion: 2019-11-12
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include "SongCollection.h"
namespace sdds {
	//remove leading and ending ' ' of a string
	std::string SongCollection::trim(std::string org) {
		size_t i;
		std::string temp;
		for (i = 0u; i < org.length() && org[i] == ' '; i++);
		temp = org.substr(i);
		for (i = temp.length() - 1; i > 0 && temp[i] == ' '; i--);
		temp = temp.substr(0, i + 1);
		return temp;
	}
	//create new Song object
	Song SongCollection::newSong(std::string src) {
		Song ns;
		ns.stitle = trim(src.substr(0, 25));
		ns.sartist = trim(src.substr(25, 25));
		ns.salbum = trim(src.substr(50, 25));
		try {
			ns.syear = std::stoi(src.substr(75, 5));
		}
		//if no year provided, set year to 0
		catch (...) { ns.syear = 0; }
		ns.slength = std::stoi(src.substr(80, 5));
		ns.m_price = std::stof(src.substr(85, 5));
		return ns;
	}
	//SongCollection constructor by providing name of the file
	SongCollection::SongCollection(std::string file) {
		std::ifstream f(file);
		std::string temp;
		if (!f) {
			throw "unable to read file";
		}
		else {
			while (!f.eof()) {
				std::getline(f, temp);
				sc.push_back(newSong(temp));
				temp = "";
			}
			f.close();
		}
	}
	//display contents of songs contained in the SongCollection along with the total play time of all songs.
	void SongCollection::display(std::ostream& out) const {
		int length = 0;
		std::for_each(sc.begin(), sc.end(), [&](const Song& s) {out << s << std::endl; length += s.slength; });
		out << "----------------------------------------------------------------------------------------" << std::endl;
		out << "|" << std::setw(78) << std::right << "Total Listening Time: "
			<< length / 3600 << ":" << length / 60 % 60 << ":" << std::setfill('0') << std::setw(2) << length % 60 << std::setfill(' ') << " |" << std::endl;
	}
	//overloaded operator<< for Song object
	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << "| " << std::setw(20) << std::left << theSong.stitle << " | "
			<< std::setw(15) << theSong.sartist << " | "
			<< std::setw(20) << theSong.salbum << " | "
			<< std::setw(6) << std::right;
		if (theSong.syear == 0)
			out << "";
		else
			out << theSong.syear;
		out << " | " << theSong.slength / 60 << ":" << std::setfill('0') << std::setw(2) << theSong.slength % 60 << std::setfill(' ') << " | "
			<< theSong.m_price << " |";
		return out;
	}
	//ascending sort SongCollection by certain field (has to be "title", "album" or "length")
	void SongCollection::sort(std::string field) {
		if (field == "title") {
			std::sort(sc.begin(), sc.end(), [](const Song& s1, const Song& s2) {return s1.stitle < s2.stitle; });
		}
		else if (field == "album") {
			std::sort(sc.begin(), sc.end(), [](const Song& s1, const Song& s2) {return s1.salbum < s2.salbum; });
		}
		else if (field == "length") {
			std::sort(sc.begin(), sc.end(), [](const Song& s1, const Song& s2) {return s1.slength < s2.slength; });
		}
	}
	//remove "[None]" token for contained Song objects if no album provied
	void SongCollection::cleanAlbum() {
		std::for_each(sc.begin(), sc.end(), [](Song& s) {if (s.salbum == "[None]")s.salbum = ""; });
	}
	//return true if any song's artist is provided artist 
	bool SongCollection::inCollection(std::string art) const {
		int n = std::count_if(sc.begin(), sc.end(), [=](const Song& s) {return s.sartist == art; });
		return n != 0;
	}
	//return list of songs which performed by provided artist
	std::list<Song> SongCollection::getSongsForArtist(std::string art) const {
		std::list<Song> songsByArt;
		std::for_each(sc.begin(), sc.end(), [&](const Song& s) {if (s.sartist == art)songsByArt.push_back(s); });
		return songsByArt;
	}
}