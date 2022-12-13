#include "LSCommand.h"
#include <set>
#include<iostream>
#include<iomanip>
#include "MetadataDisplayVisitor.h"
using namespace std;
LSCommand::LSCommand(AbstractFileSystem* f) {
	s = f;
}


int LSCommand::execute(string a) {
	cout.setf(ios::left, ios::adjustfield);

	set<string> n = s->getFileNames();
	bool line = false;
	if (a == "") {
		for (auto i = n.begin(); i != n.end(); i++) {
			cout.width(20);
			cout << (*i + ' ');
			if (line) {
				cout << endl;
				line = false;
			}
			else
				line = true;
		}
		cout << endl;
		return Success;
	}
	else if (a == "-m") {
	
		for (auto i = n.begin(); i != n.end(); i++) {
			AbstractFile* temp = s->openFile(*i);
			s->closeFile(temp);
			AbstractFileVisitor* v = new MetadataDisplayVisitor();
			temp->accept(v);
		}
		cout << endl;
		return Success;
	}
	return commandFail;
}

void LSCommand::displayInfo() {
	cout << "LSCommand displays a list of all files in the file system, LS can be invoked with a command : ls or ls -m" << endl;
}