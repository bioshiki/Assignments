// Name: Xingjian Yuan
// Seneca Student ID: 126105188
// Seneca email: xyuan22@myseneca.ca
// Date of completion: 2019-11-17
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Item.h"
size_t Item::m_widthField = { 1 };
Item::Item(const std::string& rec) {
	Utilities u;
	size_t pos = 0;
	bool more = true;
	m_name = u.extractToken(rec, pos, more);
	m_serialNumber = std::stoi(u.extractToken(rec, pos, more));
	m_quantity = std::stoi(u.extractToken(rec, pos, more));
	m_description = u.extractToken(rec, pos, more);
	m_widthField = u.getFieldWidth();
}
const std::string& Item::getName() const {
	return m_name;
}
const unsigned int Item::getSerialNumber() {
	return m_serialNumber++;
}
const unsigned int Item::getQuantity() {
	return m_quantity;
}
void Item::updateQuantity() {
	if (m_quantity >= 1) {
		m_quantity -= 1;
	}
	else {
		throw std::string("Quantity cannot be negative");
	}
}
void Item::display(std::ostream& os, bool full) const {
	if (full == false) {
		os << std::left << std::setw(m_widthField) << m_name << " [" << std::right << std::setw(6) << std::setfill('0')  << m_serialNumber << std::setfill(' ') << "]" << std::endl;
	}
	else {
		os << std::left << std::setw(m_widthField) << m_name << " [" << std::right << std::setw(6)  << std::setfill('0') << m_serialNumber << std::setfill(' ') << "] Quantity: "
			<< std::left << std::setw(m_widthField) << m_quantity << " Description: " << m_description << std::endl;
	}
}
