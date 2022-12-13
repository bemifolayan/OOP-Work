
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include"SimpleFileSystem.h"
class DisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* s;
public:
	DisplayCommand(AbstractFileSystem* f);
	int execute(string s);
	void displayInfo();

};



