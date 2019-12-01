#pragma once
#ifndef OOP345_TASK_H
#define OOP345_TASK_H
#include "CustomerOrder.h"
#include <deque>
class Task :public Item {
	std::deque<CustomerOrder>m_orders;
	Task* m_pNextTask;
public:
	Task(std::string t) :Item(t) { m_pNextTask = nullptr; };
	Task(const Task&) = delete;
	Task(Task&&) = delete;
	Task& operator=(const Task&) = delete;
	Task& operator=(Task&&) = delete;
	void runProcess(std::ostream&);
	bool moveTask();
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&);
	void validate(std::ostream&);
	Task& operator+=(CustomerOrder&&);
};

#endif