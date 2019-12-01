#pragma once
// Name: Xingjian Yuan
// Seneca Student ID: 126105188
// Seneca email: xyuan22@myseneca.ca
// Date of completion: 2019-11-17
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef OOP345_ITEM_H
#define OOP345_ITEM_H
#include <string>
#include <iostream>
#include "Utilities.h"
#include <iomanip>
class Item {
	std::string m_name;
	std::string m_description;
	size_t m_serialNumber;
	size_t m_quantity;
	static size_t m_widthField;
public:
	Item(const std::string& rec);
	const std::string& getName() const;
	const unsigned int getSerialNumber();
	const unsigned int getQuantity();
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};

#endif