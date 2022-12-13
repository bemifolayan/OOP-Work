#pragma once
#include <iostream>
class AbstractParsingStrategy;
using namespace std;
class AbstractCommand {
public:
	virtual int execute(string s) = 0;
	virtual void displayInfo() = 0;
	virtual ~AbstractCommand() = default;
	//virtual void addCommand(AbstractCommand* c) = 0;
	//virtual void setParseStrategy(AbstractParsingStrategy* o) = 0;
};
