#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractParsingStrategy.h"
#include <vector>
#include"SimpleFileSystem.h"
using namespace std;

class MacroCommand : public AbstractCommand {
private:
	AbstractFileSystem* s;
	vector<AbstractCommand *> commands;
	AbstractParsingStrategy* p;
public:
	MacroCommand(AbstractFileSystem* f);
	void addCommand(AbstractCommand* c);
	void setParseStrategy(AbstractParsingStrategy* o);
	int execute(string s);
	void displayInfo();
};



