#pragma once
#ifndef OOP345_LINEMANAGER_H
#define OOP345_LINEMANAGER_H
#include "Task.h"
#include <fstream>
#include <memory>
#include <algorithm>
class LineManager {
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;
public:
	LineManager(const std::string& fn, std::vector<Task*>& t, std::vector<CustomerOrder>& c);
	bool run(std::ostream& os);
	void displayCompleted(std::ostream& os) const;
	void validateTasks() const;
};
#endif