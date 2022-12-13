#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include"SimpleFileSystem.h"

class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* s;
public:
	CopyCommand(AbstractFileSystem* f);
	int execute(string s);
	void displayInfo();
	
};
