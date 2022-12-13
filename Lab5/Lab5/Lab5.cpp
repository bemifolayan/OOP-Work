// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\CommandPrompt.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\LSCommand.h"
#include "..\..\\SharedCode\RemoveCommand.h"
#include "..\..\\SharedCode\CatCommand.h"
#include "..\..\\SharedCode\DisplayCommand.h"
#include "..\..\\SharedCode\CopyCommand.h"
#include "..\..\\SharedCode\MacroCommand.h"
#include "..\..\\SharedCode\RenameParsingStrategy.h"

int main(int argc, char* argv[])
{
	CommandPrompt comprom;
	AbstractFileSystem* s = new SimpleFileSystem();
	AbstractFileFactory* f = new SimpleFileFactory();
	AbstractCommand* t = new TouchCommand(s, f);
	AbstractCommand* rm = new RemoveCommand(s);
	AbstractCommand* ls = new LSCommand(s);
	AbstractCommand* cat = new CatCommand(s);
	AbstractCommand* ds = new DisplayCommand(s);
	MacroCommand rn(s);
	AbstractCommand* cp = new CopyCommand(s);
	AbstractParsingStrategy* ps = new RenameParsingStrategy();
	rn.setParseStrategy(ps);
	rn.addCommand(cp);
	rn.addCommand(rm);
	AbstractCommand* rn1 = &rn;
	comprom.addCommand("touch", t);
	comprom.addCommand("rm", rm);
	comprom.addCommand("cat", cat);
	comprom.addCommand("ds", ds);
	comprom.addCommand("cp", cp);
	comprom.addCommand("rn", rn1);
	comprom.setFileSystem(s);
	comprom.setFileFactory(f);
	comprom.addCommand("ls", ls);
	comprom.run(); 
	return 0;
}


