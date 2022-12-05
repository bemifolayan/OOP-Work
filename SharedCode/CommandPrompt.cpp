#include "CommandPrompt.h"
#include "AbstractCommand.h"
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
	istream& is = cin;
	getline(is,s);
	return s;
}

int CommandPrompt::run() {
	string s;
	bool a = false;
	bool r = false;
	bool x = false;
	while (1) {
		s = prompt();
		int pos = s.find(' ');
		if (s == "q")
			return quit;
		else if (s == "help") {
			listCommands();
		}
		else {
			if (pos == -1) {
				for (auto i = m.begin(); i != m.end(); i++) {
					if (s == i->first) {
						a = true;
						if (i->second->execute("") != 0) {
							cout << "Command failed." << endl;
		
						}
					
					}
				}
				if (!a) {
					cout << "Command did not exist." << endl;
				
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
							i->second->displayInfo();
							r = true;
						
						}
					}
					if (!r) {
						cout << "Command does not exist." << endl;
						
					}
				}
				else {
					for (auto i = m.begin(); i != m.end(); i++) {
						if (i->first == a) {
							if (i->second->execute(s.substr(pos + 1)) != 0) {
								cout << "Command returned an error." << endl;
								
							}
							
							x = true;
						}
					}
					if (!x) {
						cout << "Command does not exist." << endl;
					
					}
				}
			}
		}
	}
	return Success;
}