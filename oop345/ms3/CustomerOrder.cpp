// Name: Xingjian Yuan
// Seneca Student ID: 126105188
// Seneca email: xyuan22@myseneca.ca
// Date of completion: 2019-11-24
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "CustomerOrder.h"
size_t CustomerOrder::m_widthField = { 1 };
CustomerOrder::CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = { 0 };
}
CustomerOrder::CustomerOrder(const std::string& in) {
	Utilities u;
	size_t pos = 0;
	bool more = true;
	std::vector<ItemInfo> temp;
	m_name = u.extractToken(in, pos, more);
	m_product = u.extractToken(in, pos, more);
	while (more) {
		temp.push_back(ItemInfo(u.extractToken(in, pos, more)));
	}
	m_cntItem = temp.size();
	//using raw pointers
	m_lstItem = new ItemInfo*[m_cntItem];
	for (int i = 0; i < m_cntItem; i++) {
		m_lstItem[i] = new ItemInfo(temp[i].m_itemName);
	}
	if (m_widthField < u.getFieldWidth())
		m_widthField = u.getFieldWidth();
}
CustomerOrder::CustomerOrder(CustomerOrder&& ori)noexcept {
	*this = std::move(ori);
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& ori) {
	if (this != &ori) {
		if (m_lstItem != nullptr) {
			for (int i = 0; i < m_cntItem; i++) {
				delete m_lstItem[i];
			}
			delete[]m_lstItem;
		}
		this->m_cntItem = ori.m_cntItem;
		this->m_lstItem = ori.m_lstItem;
		this->m_name = ori.m_name;
		this->m_product = ori.m_product;
		ori.m_cntItem = 0;
		ori.m_lstItem = nullptr;
		ori.m_name = "";
		ori.m_product = "";
	}
	return *this;
}
CustomerOrder::~CustomerOrder() {
	for (int i = 0; i < m_cntItem; i++) {
		delete m_lstItem[i];
	}
	delete[]m_lstItem;
}
bool CustomerOrder::getItemFillState(std::string str) const {
	for (int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == str) {
			return m_lstItem[i]->m_fillState;
		}
	}
	return true;
}
bool CustomerOrder::getOrderFillState() const {
	for (int i = 0; i < m_cntItem; i++) {
		if (!m_lstItem[i]->m_fillState)
			return false;
	}
	return true;
}
void CustomerOrder::fillItem(Item& item, std::ostream& os) const{
	for (int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == item.getName()) {
			if (item.getQuantity() == 0) {
				os << "Unable to fill " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
			}
			else {
				item.updateQuantity();
				m_lstItem[i]->m_serialNumber = item.getSerialNumber();
				m_lstItem[i]->m_fillState = true;
				os << "Filled " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
			}
		}
	}
}
void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;
	for (int i = 0; i < m_cntItem; i++) {
		os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << std::setfill(' ') << "] "
			<< std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - "
			<< (m_lstItem[i]->m_fillState ? "FILLED" : "MISSING") << std::endl;
	}
}
