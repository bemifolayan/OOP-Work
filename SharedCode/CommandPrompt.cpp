#include "CommandPrompt.h"
#include "AbstractCommand.h"
#include "LSCommand.h"
#include "CatCommand.h"
#include "DisplayCommand.h"
#include "RemoveCommand.h"
#include "CopyCommand.h"
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
	AbstractCommand* n = new LSCommand(fileSystem);
	AbstractCommand* g = new RemoveCommand(fileSystem);
	AbstractCommand* cat = new CatCommand(fileSystem);
	AbstractCommand* ds = new DisplayCommand(fileSystem);
	AbstractCommand* cp = new CopyCommand(fileSystem);
	while (1) {
		s = prompt();
		int pos = s.find(' ');
		if (s == "q")
			return quit;
		else if (s == "ls") {
			n->execute("");
		}
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
				string c;
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
				else if (a == "ls") {
					str >> b;
					if (b == "-m") {
						n->execute(b);
					}
					else
						cout << "command does not exist" << endl;
				}
				else if (a == "rm") {
					str >> b;
					g->execute(b);
				}
				else if (a == "cat") {
					str >> b;
					s = s.substr(pos + 1);
					int pos2 = s.find(' ');
					if (pos2 == -1)
						cat->execute(b);
					else {
						str >> c;
						cat->execute(b + " " + c);
					}
				}
				else if (a == "ds") {
					str >> b;
					s = s.substr(pos + 1);
					int pos2 = s.find(' ');
					if (pos2 == -1)
						ds->execute(b);
					else {
						str >> c;
						ds->execute(b + " " + c);
					}
				}
				else if (a == "cp") {
					str >> b;
					s = s.substr(pos + 1);
					int pos2 = s.find(' ');
					if (pos2 != -1) {
						str >> c;
						cp->execute(b + " " + c);
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