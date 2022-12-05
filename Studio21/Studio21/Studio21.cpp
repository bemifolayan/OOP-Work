// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<vector>
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\BasicDisplayVisitor.h"
#include "..\..\\SharedCode\MetadataDisplayVisitor.h"
#include "..\..\\SharedCode\PasswordProxy.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\CommandPrompt.h"
#include "..\..\\SharedCode\TouchCommand.h"
using namespace std;
int main(int argc, char* argv[])
{
	AbstractFileSystem* s = new SimpleFileSystem();
	AbstractFileFactory* f = new SimpleFileFactory();
	AbstractCommand* com = new TouchCommand(s, f);
	CommandPrompt comprom;
	comprom.setFileSystem(s);
	comprom.setFileFactory(f);
	comprom.addCommand("command1", com);
	comprom.run();
	
    AbstractFile* g = s->openFile("regan.txt");
	cout<< g->getName() << endl;
	return 0;
}

