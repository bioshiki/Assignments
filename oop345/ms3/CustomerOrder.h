#pragma once
// Name: Xingjian Yuan
// Seneca Student ID: 126105188
// Seneca email: xyuan22@myseneca.ca
// Date of completion: 2019-11-24
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef OOP345_CUSTOMERORDER_H
#define OOP345_CUSTOMERORDER_H
#include <string>
#include <iostream>
#include "Utilities.h"
#include "Item.h"
#include <vector>
#include <memory>
#include <iomanip>
struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};
class CustomerOrder {
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	ItemInfo** m_lstItem = nullptr;
	static size_t m_widthField;
public:
	CustomerOrder();
	CustomerOrder(const std::string& in);
	CustomerOrder(const CustomerOrder& ori) { throw 0; };
	CustomerOrder& operator=(const CustomerOrder& ori) = delete;
	CustomerOrder(CustomerOrder&& ori)noexcept;
	CustomerOrder& operator=(CustomerOrder&& ori);
	~CustomerOrder();
	bool getItemFillState(std::string) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream& os)const;
	void display(std::ostream&) const;
};
#endif