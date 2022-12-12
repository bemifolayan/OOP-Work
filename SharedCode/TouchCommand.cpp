#include "TouchCommand.h"
#include "PasswordProxy.h"
#include <string>
TouchCommand::TouchCommand(AbstractFileSystem* s, AbstractFileFactory* f) {
	fileSystem = s;
	fileFactory = f;
}

int TouchCommand::execute(string s) {
	AbstractFile* z;
	int pos = s.find(' ');
	bool tree = false;
	if (pos == -1) {
		z = fileFactory->createFile(s);
		if (z == nullptr)
			return fileNotCreated;
	}
	else {
		z = fileFactory->createFile(s.substr(0, pos));
		if (z != nullptr) {
			if (s.substr(pos + 1) == "-p") {
				tree = true;
				string d;
				cout << "What is the password?" << endl;
				getline(cin, d);
				AbstractFile* p = new PasswordProxy(z, d);
				z = p;
				s = s.substr(0, pos);
			}
		}
		else {
			return fileNotCreated;
		}
	}
	if (fileSystem->addFile(s, z) != 0) {
		delete z;
		return fileNotAdded;
	}
	else
		return Success;
}

void TouchCommand::displayInfo() {
	cout << "Touch creates a file, touch can be invoked with a command: touch<filename>" << endl;
}