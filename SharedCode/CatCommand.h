#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include"SimpleFileSystem.h"
class CatCommand : public AbstractCommand {
private:
	AbstractFileSystem* s;
public:
	CatCommand(AbstractFileSystem* f);
	int execute(string s);
	void displayInfo();

};


