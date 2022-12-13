#include "CopyCommand.h"
#include <set>
#include<iostream>
#include<vector>
#include<iomanip>
#include "MetadataDisplayVisitor.h"
using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* f) {
	s = f;
}


int CopyCommand::execute(string a) {
	int pos = a.find(' ');
	string file1 = a.substr(0, pos);
	string newfile = a.substr(pos + 1);
	AbstractFile* file = s->openFile(file1);
	if (file == nullptr)
		return fileDNE;
	else {
		s->closeFile(file);
		AbstractFile* copy = file->clone(newfile);
		if(s->addFile(copy->getName(), copy) != 0) {
			s->deleteFile(newfile);
			return commandFail;
		}
		else {
			return Success;
		}
	}
	return fileDNE;
}

void CopyCommand::displayInfo() {
	cout << "Copy command copies a file that exists in a file system and adds the copy to the file system with a different name. Copy comand is invoked by cp <file_to_copy> <new_name_with_no_extension>" << endl;
}