#include "MacroCommand.h"
#include <set>
#include<iostream>
#include<vector>
#include<iomanip>
#include "MetadataDisplayVisitor.h"
using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* f) {
	s = f;
	
}

void MacroCommand::addCommand(AbstractCommand* c) {
	commands.push_back(c);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* o) {
	p = o;
}

int MacroCommand::execute(string a) {
	vector<string> s = p->parse(a);
	for (unsigned int i = 0; i < commands.size(); i++) {
		if (commands[i]->execute(s[i]) != 0)
			return commandFail;
	}
	return Success;
}

void MacroCommand::displayInfo() {
	cout << "Macro Commands executes eac of the commands it is composed of in order. " << endl;
}