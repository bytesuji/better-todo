#include "todo.h"
#include <iostream>
#include <string>

using std::cout, std::cerr, std::cin, std::endl;
using std::string;

int main() {
	todo_list LIST;		
	string cmd;	

	cout << "TODO\n";
	cout << "-----\n";

	do {
		cout << "~> ";
	} while (cin >> cmd);

	return 0;
}
