#include <iostream>
#include <string>
#include <algorithm>
#include "todo.h"
#include "serial.h"

using std::cout; 
using std::cerr;
using std::cin;
using std::getline;
using std::endl;
using std::string;
using std::transform;

void to_lower(string& str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}

template <class T>
void check_input(const char* msg, T& data) {
	while (true) {
		cout << msg;
		cin >> data;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
        }
		else
			break;
    }
}

int main() {
	todo_list LIST;
	try {LIST = serial::load<todo_list>(".tasks.lance");}
	catch (boost::archive::archive_exception e) {
		serial::dump(LIST, ".tasks.lance");
    }

	string cmd = "DEFAULT_STRING_STATE";

	cout << "TODO" << endl;
	cout << "-----" << endl;
	cout << " > ";

	while (getline(cin, cmd)) {
		if (cmd.empty()) {
			cout << " > ";
			continue;
        }		

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
			  cmd == "DEFAULT_STRING_STATE")) { cerr << "Not a command." << endl; cout << " > "; continue; }

		if (cmd == "add" || cmd == "a") {
			string name;
			string desc;
			unsigned prior;
			
			cout << "Task name: ";
			getline(cin, name);
			cout << "Description: ";
			getline(cin, desc);
			check_input("Priority: ", prior);

			LIST.add(name, desc, prior);
			cin.ignore();
        }	

		else if (cmd == "del" || cmd == "delete" || cmd == "d") {
			unsigned num;
			check_input("Which task? ", num);
			LIST.del(num);
			cin.ignore();
        }

		else if (cmd == "pri" || cmd == "prioritize" || cmd == "p") {
			unsigned num;
			unsigned p;
			check_input("Which task? ", num);
			check_input("Set priority to what? ", p);

			LIST.prioritize(num, p);
			cin.ignore();
        }

		else if (cmd == "show" || cmd == "s") {
			LIST.show();
        }

		else if (cmd == "showtask" || cmd == "st") {
			unsigned num;
			check_input("Which task? ", num);

			LIST.showtask(num);
			cin.ignore();
        }

		else if (cmd == "quit" || cmd == "q") {
			break;
        }

		else {
			cout << "Command not yet implemented." << endl;
        }

		serial::dump(LIST, ".tasks.lance");
		cout << " > ";
	} 

	return 0;
}
