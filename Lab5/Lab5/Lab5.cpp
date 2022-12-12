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
	comprom.addCommand("touch", t);
	comprom.addCommand("rm", rm);
	comprom.addCommand("cat", cat);
	comprom.addCommand("ds", ds);
	comprom.setFileSystem(s);
	comprom.setFileFactory(f);
	//comprom.addCommand("ls", ls);
	comprom.run();
	return 0;
}


