// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\CommandPrompt.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\LSCommand.h"
#include "..\..\\SharedCode\RemoveCommand.h"
int main(int argc, char* argv[])
{
	CommandPrompt comprom;
	AbstractFileSystem* s = new SimpleFileSystem();
	AbstractFileFactory* f = new SimpleFileFactory();
	AbstractCommand* t = new TouchCommand(s, f);
	AbstractCommand* rm = new RemoveCommand(s);
	comprom.addCommand("touch", t);
	comprom.setFileSystem(s);
	comprom.setFileFactory(f);
	AbstractCommand* ls = new LSCommand(s);
	//comprom.addCommand("ls", ls);
	comprom.run();
	return 0;
}


