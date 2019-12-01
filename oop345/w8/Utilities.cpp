// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// Name: Xingjian Yuan
// Seneca Student ID: 126105188
// Seneca email: xyuan22@myseneca.ca
// Date of completion: 2019-11-11
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (int i = 0; i < desc.size(); i++) {
			for (int j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					Product* p = new Product(desc[i].desc, price[j].price);
					p->validate();
					priceList += (p);
					delete p;
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (int i = 0; i < desc.size(); i++) {
			for (int j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					std::shared_ptr<Product> p(new Product(desc[i].desc, price[j].price));
					p->validate();
					priceList += (p);
				}
			}
		}
		return priceList;
	}
}