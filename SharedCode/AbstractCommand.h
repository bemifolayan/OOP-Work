#pragma once
#include <iostream>
using namespace std;
class AbstractCommand {
public:
	virtual int execute(string s) = 0;
	virtual void displayInfo() = 0;
	virtual ~AbstractCommand() = default;
};
