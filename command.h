#ifndef COMMAND_H
#define COMMAND_H

#include "lists.h"
#include <cstdlib>

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

void handle_toplevel_arg(string cmd, todo_list LIST, unsigned& cc, unsigned& cl) {
	to_lower(cmd);
	if (!(cmd == "add" || 
		  cmd == "a" || 
		  cmd == "delete" ||
		  cmd == "del" ||
		  cmd == "d" ||
		  // cmd == "prioritize" || 
		  // cmd == "pri" || 
		  // cmd == "p" ||
		  cmd == "show" || 
		  cmd == "s" ||
		  // cmd == "showtask" || 
		  // cmd == "st" ||
		  cmd == "quit" || 
		  cmd == "q" ||
		  cmd == "help" ||
		  cmd == "h" || 
		  cmd == "DEFAULT_STRING_STATE")) { cerr << "Not a command." << endl; cout << " > "; return; }

	if (cmd == "add" || cmd == "a") { //FIXED
		string name;
		string desc;
		
		cout << "Category name: ";
		getline(cin, name);
		cout << "Description: ";
		getline(cin, desc);

		LIST.add(name, desc);
		cin.ignore();
	}	

	else if (cmd == "del" || cmd == "delete" || cmd == "d") { //FIXED
		unsigned num;
		check_input("Which task? ", num);
		LIST.del(num);
		cin.ignore();
	}

	else if (cmd == "show" || cmd == "s") {
		LIST.show();
	}

	else if (cmd == "h" || cmd == "help") {
		cout << "\nAvailable top-level commands:\n";
		cout << "-------------------\n";
		cout << "add, a\n";
		cout << "delete, del, d\n";
		cout << "show, s\n";
		cout << "quit, q\n";
		cout << "help, h\n\n";
	}

	else if (cmd == "quit" || cmd == "q") {
		exit
	}

	else {
		cout << "Command not yet implemented." << endl;
	}

	serial::dump(LIST, ".tasks.lance");
	cout << " " << cl << "> ";
}

void handle_lowlevel_arg(string cmd, todo_list LIST, unsigned& cc, unsigned& cl) {
	to_lower(cmd);
	if (!(cmd == "add" || 
		  cmd == "a" || 
		  cmd == "delete" ||
		  cmd == "del" ||
		  cmd == "d" ||
		  cmd == "prioritize" || 
		  cmd == "pri" || 
		  cmd == "p" ||
		  cmd == "show" || 
		  cmd == "s" ||
		  cmd == "showtask" || 
		  cmd == "st" ||
		  cmd == "quit" || 
		  cmd == "q" ||
		  cmd == "up" ||
		  cmd == "u" ||
		  cmd == "help" ||
		  cmd == "h" || 
		  cmd == "DEFAULT_STRING_STATE")) { cerr << "Not a command." << endl; cout << " > "; return; }

	if (cmd == "add" || cmd == "a") {
		string name;
		string desc;
		unsigned prior;
		
		cout << "Task name: ";
		getline(cin, name);
		cout << "Description: ";
		getline(cin, desc);
		check_input("Priority: ", prior);

		LIST.at(cc).add(name, desc, prior);
		cin.ignore();
	}	

	else if (cmd == "del" || cmd == "delete" || cmd == "d") {
		unsigned num;
		check_input("Which task? ", num);
		LIST.at(cc).del(num);
		cin.ignore();
	}

	else if (cmd == "pri" || cmd == "prioritize" || cmd == "p") {
		unsigned num;
		unsigned p;
		check_input("Which task? ", num);
		check_input("Set priority to what? ", p);

		LIST.at(cc).prioritize(num, p);
		cin.ignore();
	}

	else if (cmd == "show" || cmd == "s") {
		LIST.at(cc).show();
	}

	else if (cmd == "showtask" || cmd == "st") {
		unsigned num;
		check_input("Which task? ", num);

		LIST.at(cc).showtask(num);
		cin.ignore();
	}

	else if (cmd == "h" || cmd == "help") {
		cout << "\nAvailable commands:\n";
		cout << "-------------------\n";
		cout << "add, a\n";
		cout << "delete, del, d\n";
		cout << "prioritize, pri, p\n";
		cout << "show, s\n";
		cout << "showtask, st\n";
		cout << "quit, q\n";
		cout << "help, h\n\n";
	}

	else if (cmd == "quit" || cmd == "q") {
		exit(0);
	}

	else {
		cout << "Command not yet implemented." << endl;
	}

	serial::dump(LIST, ".tasks.lance");
	cout << " " << cl << "> ";
}

#endif // COMMAND_H
