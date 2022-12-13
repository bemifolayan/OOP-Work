#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
class TouchCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
public:
	TouchCommand(AbstractFileSystem* s, AbstractFileFactory* f);
	int execute(string s);
	void displayInfo();

};