#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include"SimpleFileSystem.h"
class RemoveCommand : public AbstractCommand {
private:
	AbstractFileSystem* s;
public:
	RemoveCommand(AbstractFileSystem* f);
	int execute(string s);
	void displayInfo();

};


