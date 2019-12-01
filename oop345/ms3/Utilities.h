#pragma once
// Name: Xingjian Yuan
// Seneca Student ID: 126105188
// Seneca email: xyuan22@myseneca.ca
// Date of completion: 2019-11-17
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef OOP345_UTILITIES_H
#define OOP345_UTILITIES_H
#include <string>
class Utilities {
	size_t m_widthField = { 1 };
	static char m_delimiter;
public:
	void setFieldWidth(size_t width);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(const char);
	const char getDelimiter() const;
};

#endif