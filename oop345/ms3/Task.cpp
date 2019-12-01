#include "Task.h"
void Task::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {
		if (!(m_orders.back().getOrderFillState())) {
			m_orders.back().fillItem(*this, os);
		}
	}
}
bool Task::moveTask() {
	if (m_orders.empty())
		return false;
	else {
		if (m_orders.back().getItemFillState(this->getName())) {
			if (m_pNextTask == nullptr)
				return false;
			m_pNextTask->m_orders.push_front(std::move(m_orders.back()));
			m_orders.pop_back();
		}
		return true;
	}
}
void Task::setNextTask(Task& t) {
	m_pNextTask = &t;
}
bool Task::getCompleted(CustomerOrder& obj) {
	if (m_orders.empty()) {
		return false;
	}
	else {
		obj = std::move(m_orders.back());
		m_orders.pop_back();
		return true;
	}
}
void Task::validate(std::ostream& os) {
	os << this->getName() << " --> ";
	if (m_pNextTask)
		os << m_pNextTask->getName();
	else
		os << "END OF LINE";
	os << std::endl;
}
Task& Task::operator+=(CustomerOrder&& obj) {
	m_orders.push_front(std::move(obj));
	return *this;
}
