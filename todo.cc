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
using std::transform;

int main() {
	list_collection LIST;
	try {LIST = serial::load<todo_list>("/home/albert/.tasks.lance");}
	catch (boost::archive::archive_exception e) {
		serial::dump(LIST, "/home/albert/.tasks.lance");
    }

	string cmd = "DEFAULT_STRING_STATE";
	unsigned current_cat = 0;
	unsigned current_level = 0;

	cout << "TODO" << endl;
	cout << "-----" << endl;
	cout << " " << current_level << "> ";

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
			serial::dump(LIST, "/home/albert/.tasks.lance")
			cout << "State corrupted!\n"
			exit(-1);
        }
	}

	return 0;
}
