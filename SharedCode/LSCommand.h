#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include"SimpleFileSystem.h"
class LSCommand : public AbstractCommand {
private:
	AbstractFileSystem* s;
public:
	LSCommand(AbstractFileSystem* f);
	int execute(string s);
	void displayInfo();
};
