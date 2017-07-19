#ifndef TODO_H
#define TODO_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::vector;
using std::cout, std::cin, std::endl;

struct todo_item {
	string name;
	string description;
	unsigned priority;	
};

class todo_list {
private:
	vector<todo_item> main_list;

public:
	void add(string task, string description = "DEFAULT_DESC", unsigned prior = 3) {
		if (description == "DEFAULT_DESC")
			description = task; // make description same as task name if none specified

		main_list.push_back(todo_item {
			task,
			description,
			prior
        });
    }	

	void del(unsigned n) {
		cout << "Are you sure you want to delete task #" << n << "? ";
		char resp;
		cin >> resp;
		if (resp != 'y')
			return;	

		main_list.erase(main_list.begin() + n);
    }

	void prioritize(unsigned n, unsigned prior = 0) {
		// defaults to highest priority
		main_list.at(n).priority = prior;
    }
};

// TODO 
// add color based on priority
// overload output for item, list

#endif // TODO_H
