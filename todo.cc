#include <iostream>
#include <string>
#include <algorithm>
#include "lists.h"
#include "command.h"
#include "serial.h"

using std::cout; 
using std::cerr;
using std::cin;
using std::getline;
using std::endl;
using std::string;

int main() {
	list_collection LIST;
	try {LIST = serial::load<list_collection>(TASK_PATH.c_str());}
	catch (boost::archive::archive_exception e) {
		serial::dump(LIST, TASK_PATH.c_str());
    }

	string cmd = "DEFAULT_STRING_STATE";
	unsigned current_cat = 0;
	unsigned current_level = 0;

	cout << "TODO" << endl;
	cout << "-----" << endl;
	cout << " > ";

	while (getline(cin, cmd)) {
		if (cmd.empty()) {
			cout << " > ";
			continue;
        }		

		if (current_level == 0)
			handle_toplevel_arg(cmd, LIST, current_cat, current_level);
		else if (current_level == 1)
			handle_lowlevel_arg(cmd, LIST, current_cat, current_level);
		else {
			serial::dump(LIST, TASK_PATH.c_str());
			cout << "State corrupted!\n";
			exit(-1);
		}
	}

	return 0;
}
