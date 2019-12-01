// Name: Xingjian Yuan
// Seneca Student ID: 126105188
// Seneca email: xyuan22@myseneca.ca
// Date of completion: 2019-11-17
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"
char Utilities::m_delimiter = { '\n' };
void Utilities::setFieldWidth(size_t width) {
	m_widthField = width;
}
size_t Utilities::getFieldWidth() const {
	return m_widthField;
}
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	more = false;
	int d = str.find(m_delimiter, next_pos);
	if (d!=-1) {
		if (d - next_pos < 1) {
			throw std::string("Invalid token");
		}
		std::string token = str.substr(next_pos, d - next_pos);
		m_widthField = token.length() > m_widthField ? token.length() : m_widthField;
		more = true;
		next_pos = d + 1;
		return token;
	}
	else {
		std::string token = str.substr(next_pos);
		return token;
	}
}
void Utilities::setDelimiter(const char d) {
	m_delimiter = d;
}
const char Utilities::getDelimiter() const {
	return m_delimiter;
}
