#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>

class CommandPrompt {
private:
	map<string, AbstractCommand*> m;
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem* a);
	void setFileFactory(AbstractFileFactory* b);
	int addCommand(std::string s, AbstractCommand* c);
	int run();
protected:
	void listCommands();
	std::string prompt();
	
};