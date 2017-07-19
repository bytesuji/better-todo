#include <iostream>
#include <string>
#include <algorithm>
#include "todo.h"
#include "serial.h"

using std::cout, std::cerr, std::cin, std::endl;
using std::string;
using std::transform;

void to_lower(string& str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}

int main() {
	todo_list LIST;		
	string cmd = "DEFAULT_STRING_STATE";
	int arg;

	cout << "TODO\n";
	cout << "-----\n";
	cout << " > ";

	while (cin >> cmd) {
		to_lower(cmd);
		if (!(cmd == "add" || 
			  cmd == "del" ||
			  cmd == "pri" || 
			  cmd == "delete" ||
			  cmd == "show" || 
			  cmd == "prioritize" || 
			  cmd == "DEFAULT_STRING_STATE")) { cerr << "Not a command.\n"; cout << " > "; continue; }

		if (cmd == "add") {
			string name;
			string desc;
			unsigned prior;
			
			cout << "Task name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Description: ";
			getline(cin, desc);
			cout << "Priority: ";
			cin >> prior;

			LIST.add(name, desc, prior);
        }	

		else if (cmd == "del" || cmd == "delete") {
			unsigned num;
			cout << "Which task? ";
			cin >> num;
			LIST.del(num);
        }

		else if (cmd == "pri" || cmd == "prioritize") {
			unsigned num;
			unsigned p;
			cout << "Which task? ";
			cin >> num;
			cout << "Set priority to what? ";
			cin >> p;

			LIST.prioritize(num, p);
        }

		else if (cmd == "show") {
			unsigned num;
			cout << "Which task? ";
			cin >> num;
			LIST.show(num);
        }

		else {
			cout << "Command not yet implemented.\n";
        }

		serial::dump(LIST, ".tasks.lance");
		cout << " > ";
	} 

	return 0;
}
