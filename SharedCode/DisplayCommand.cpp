#include "DisplayCommand.h"
#include <set>
#include<iostream>
#include<iomanip>
#include "BasicDisplayVisitor.h"
using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* f) {
	s = f;
}


int DisplayCommand::execute(string a) {
	int pos = a.find(' ');
	set<string> names = s->getFileNames();
	if (pos == -1) {
		for (auto i = names.begin(); i != names.end(); i++) {
			if (*i == a) {
				AbstractFile* file = s->openFile(*i);
				AbstractFileVisitor* v = new BasicDisplayVisitor();
				file->accept(v);
				s->closeFile(file);
				return Success;
			}
		}
		return commandFail;
	}
	else {
		
		for (auto i = names.begin(); i != names.end(); i++) {
		
			if (*i == a.substr(0,pos)){
	
				AbstractFile* file = s->openFile(*i);
				vector<char> cont = file->read();
				for (unsigned int i = 0; i < cont.size(); i++) {
					cout << cont[i];
				}
				cout << endl;
				s->closeFile(file);
				return Success;
			}
		}
		return commandFail;
	}
}

void DisplayCommand::displayInfo(){
	cout << "Display Command opens a file and displays its content. Display command can be invoked with ds <filename> [-d]" << endl;
}
