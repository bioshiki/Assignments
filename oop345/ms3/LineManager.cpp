#include "LineManager.h"
LineManager::LineManager(const std::string& fn, std::vector<Task*>& t, std::vector<CustomerOrder>& c) {
	std::ifstream f(fn);
	if (f.is_open()) {
		Utilities u;
		while (!f.eof()) {
			size_t pos = 0;
			bool more = true;
			std::string temp;
			std::getline(f, temp);
			std::string t1 = u.extractToken(temp, pos, more);
			std::string t2 = u.extractToken(temp, pos, more);
			auto it1 = std::find_if(t.begin(), t.end(), [&](Task* t) {return t->getName() == t1; });
			if (pos != 0) {
				auto it2 = std::find_if(t.begin(), t.end(), [&](Task* t) {return t->getName() == t2; });
				(*it1)->setNextTask(*(*it2));
			}
			AssemblyLine.push_back(*it1);
		}
		f.close();
		for_each(c.begin(), c.end(), [&](CustomerOrder& a) {ToBeFilled.push_front(std::move(a)); });
		m_cntCustomerOrder = ToBeFilled.size();
	}
}
bool LineManager::run(std::ostream& os) {
	if (!ToBeFilled.empty()) {
		*(AssemblyLine.front()) += std::move(ToBeFilled.back());
		ToBeFilled.pop_back();
	}
	for_each(AssemblyLine.begin(), AssemblyLine.end(), [&](Task* a) {
		do {
			a->runProcess(os);
		} while (a->moveTask());
	});
	CustomerOrder temp;
	while (AssemblyLine.back()->getCompleted(temp)) {
		Completed.push_back(std::move(temp));
	}
	if (ToBeFilled.empty())
		return true;
	else
		return false;
}
void LineManager::displayCompleted(std::ostream& os) const {
	for_each(Completed.begin(), Completed.end(), [&](const CustomerOrder& a) {
		a.display(os);
	});
}
void LineManager::validateTasks() const {
	for_each(AssemblyLine.begin(), AssemblyLine.end(), [&](Task* a) {
		a->validate(std::cout);
	});

}
