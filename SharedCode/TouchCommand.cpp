#include "TouchCommand.h"
#include "PasswordProxy.h"

TouchCommand::TouchCommand(AbstractFileSystem* s, AbstractFileFactory* f) {
	fileSystem = s;
	fileFactory = f;
}

int TouchCommand::execute(string s) {
	AbstractFile* z = fileFactory->createFile(s);
	int pos = s.find(' ');
	bool tree = false;
	if (z != nullptr) {
		if (pos != -1) {
			if (s.substr(pos + 1) == "-p") {
				tree = true;
				string d;
				cout << "What is the password?" << endl;
				cin >> d;
				AbstractFile* p = new PasswordProxy(z, d);
				z = p;
				s = s.substr(0, pos);
			}
		}
		if (fileSystem->addFile(s, z) != 0) {
			delete z;
			return fileNotAdded;
		}
		else 
			return Success;
	}
	else
		return fileNotCreated;
}

void TouchCommand::displayInfo() {
	cout << "Touch creates a file, touch can be invoked with a command: touch<filename>" << endl;
}