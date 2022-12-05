#include "TouchCommand.h"

TouchCommand::TouchCommand(AbstractFileSystem* s, AbstractFileFactory* f) {
	fileSystem = s;
	fileFactory = f;
}

int TouchCommand::execute(string s) {
	AbstractFile* z = fileFactory->createFile(s);
	if (z != nullptr) {
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