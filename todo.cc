#include <iostream>
#include <string>
#include <algorithm>
#include "todo.h"
#include "serial.h"

using std::cout; 
using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::transform;

void to_lower(string& str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}

int main() {
	todo_list LIST = serial::load<todo_list>(".tasks.lance");
	string cmd = "DEFAULT_STRING_STATE";

	cout << "TODO\n";
	cout << "-----\n";
	cout << " > ";

	while (cin >> cmd) {
		to_lower(cmd);
		if (!(cmd == "add" || 
			  cmd == "a" || 
			  cmd == "del" ||
			  cmd == "d" ||
			  cmd == "pri" || 
			  cmd == "p" ||
			  cmd == "delete" ||
			  cmd == "show" || 
			  cmd == "s" ||
			  cmd == "showtask" || 
			  cmd == "st" ||
			  cmd == "prioritize" || 
			  cmd == "quit" || 
			  cmd == "q" ||
			  cmd == "DEFAULT_STRING_STATE")) { cerr << "Not a command.\n"; cout << " > "; continue; }

		if (cmd == "add" || cmd == "a") {
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

		else if (cmd == "del" || cmd == "delete" || cmd == "d") {
			unsigned num;
			cout << "Which task? ";
			cin >> num;
			LIST.del(num);
        }

		else if (cmd == "pri" || cmd == "prioritize" || cmd == "p") {
			unsigned num;
			unsigned p;
			cout << "Which task? ";
			cin >> num;
			cout << "Set priority to what? ";
			cin >> p;

			LIST.prioritize(num, p);
        }

		else if (cmd == "show" || cmd == "s") {
			LIST.show();
        }

		else if (cmd == "showtask" || cmd == "st") {
			unsigned num;
			cout << "Which task? ";
			cin >> num;
			LIST.showtask(num);
        }

		else if (cmd == "quit") {
			break;
        }

		else {
			cout << "Command not yet implemented.\n";
        }

		serial::dump(LIST, ".tasks.lance");
		cout << " > ";
	} 

	return 0;
}
