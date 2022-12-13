#include "CatCommand.h"
#include <set>
#include<iostream>
#include<iomanip>
#include "MetadataDisplayVisitor.h"
#include "AbstractFileVisitor.h"
#include "BasicDisplayVisitor.h"
#include<string>
using namespace std;

CatCommand::CatCommand(AbstractFileSystem* f) {
	s = f;
}


int CatCommand::execute(string a) {
	
	int pos = a.find(' ');

	
	string line1;
	string line2;
	AbstractFileVisitor* f = new BasicDisplayVisitor();
	if (pos != -1) {

		if (a.substr(pos + 1) == "-a") {
		
			set<string> names = s->getFileNames();
			for (auto i = names.begin(); i != names.end(); i++) {
				if (*i == a.substr(0,pos)) {
					cout << *i << endl;
					AbstractFile* file = s->openFile(*i);
					s->closeFile(file);
					file->accept(f);
					cout << "Enter data you would like to append to the existing file. Enter :wq to save the file and exit, Enter :q to exit without saving" << endl;
					getline(cin, line1);
					getline(cin,line2);

					while (line2 != ":wq" && line2 != ":q") {
						line1 += "\n";
						line1 += line2;
						getline(cin, line2);
					}

					if (line2 == ":wq") {
						vector<char> c;
						for (unsigned int i = 0; i < line1.size(); i++) {
							c.push_back(line1[i]);
						}
						//c.push_back('\n');
						return file->append(c);
					}
					else if (line2 == ":q") {
						return Success;
					}
					
				}
			}
		}
	}
	else {
		set<string> names = s->getFileNames();
		for (auto i = names.begin(); i != names.end(); i++) {
			if (*i == a) {
				AbstractFile* file = s->openFile(*i);
				cout << "Enter data you would like to write to the existing file. Enter :wq to save the file and exit, Enter :q to exit without saving" << endl;
				getline(cin, line1);
				getline(cin, line2);

				while (line2 != ":wq" && line2 != ":q") {
					line1 += "\n";
					line1 += line2;
					getline(cin, line2);
				}

				if (line2 == ":wq") {
					vector<char> c;
					for (unsigned int i = 0; i < line1.size(); i++) {
						c.push_back(line1[i]);
					}
					//c.push_back('\n');
					int result = file->write(c);
					s->closeFile(file);
					return result;
				}
				else if (line2 == ":q") {
					s->closeFile(file);
					return Success;
				}
			}
		}
	}
	return failedToWrite;
}

void CatCommand::displayInfo() {
	cout << "Cat command writes to a file in the filesytem. Cat command can be invoked by calling cat <filename> [-a] " << endl;

}