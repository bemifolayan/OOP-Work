#include "CommandPrompt.h"
#include "AbstractCommand.h"
#include "LSCommand.h"
#include "CatCommand.h"
#include "DisplayCommand.h"
#include "RemoveCommand.h"
#include "MacroCommand.h"
#include "CopyCommand.h"
#include "RenameParsingStrategy.h"
#include <map>
#include <iostream>
#include<sstream>
using namespace std;

CommandPrompt::CommandPrompt() {
	AbstractFileSystem* fileSystem = nullptr;
	AbstractFileFactory* fileFactory = nullptr;
}

void CommandPrompt::setFileSystem(AbstractFileSystem* a) {
	fileSystem = a;
}
void CommandPrompt::setFileFactory(AbstractFileFactory* b) {
	fileFactory = b;
}
int CommandPrompt::addCommand(std::string s, AbstractCommand* c) {
	
	if ((m.insert({ s,c })).second == true)
		return Success;
	else
		return failedToInsert;
}

void CommandPrompt::listCommands() {
	for (auto i = m.begin(); i != m.end(); i++) {
		cout << i->first <<" ";
	}
	cout << endl;
}

std::string CommandPrompt::prompt() {
	string s;
	cout << "Please input a valid command, q to quit, help, help<command name>" << endl;
	cout << "$   ";
	//istream& is = cin;
	getline(cin,s);
	return s;
}

int CommandPrompt::run() {
	string s;
	
	while (1) {
		bool found = false;
		s = prompt();
		if (s == "q")
			return quit;
		else if (s == "help") {
			listCommands();
			found = true;
		}
		int pos = s.find(' ');
		if (pos == -1) {
			for (auto i = m.begin(); i != m.end(); i++) {
				if (i->first == s) {
					found = true;
					if (i->second->execute("") != 0)
						cout << "The command failed" << endl;
				}
			}

		}
		else {
			istringstream str(s);
			string a;
			string b;
			str >> a;
			if (a == "help") {
				str >> b;
				for (auto i = m.begin(); i != m.end(); i++) {
					if (i->first == b) {
						found = true;
						i->second->displayInfo();
					}
				}
			}
			else {
				for (auto i = m.begin(); i != m.end(); i++) {
					if (i->first == a) {
						found = true;
						if (i->second->execute(s.substr(pos + 1)) != 0)
							cout << "the command failed" << endl;
					}
				}
			}
		
		}
		if (found == false) {
			cout << "The command was not found" << endl;
		}
	}
}