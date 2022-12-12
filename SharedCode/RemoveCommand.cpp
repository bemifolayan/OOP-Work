#include "RemoveCommand.h"
#include <set>
#include<iostream>
#include<iomanip>
#include "MetadataDisplayVisitor.h"
using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* f) {
	s = f;
}


int RemoveCommand::execute(string a) {
	return s->deleteFile(a);
}

void RemoveCommand::displayInfo() {
	cout << "Remove command removes a file from the file system. Remove command can be invoked by calling rm <filename> " << endl;
}