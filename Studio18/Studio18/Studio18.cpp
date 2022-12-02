// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include <iostream>
#include<vector>

using namespace std;

int main(int argc, char* argv[])
{
	AbstractFileSystem* bemi = new SimpleFileSystem();
	AbstractFileFactory* regan = new SimpleFileFactory();
	AbstractFile* poop = regan->createFile("poop.txt");
	AbstractFile* pee = regan->createFile("pee.img");
	bemi->addFile("poop.txt", poop);
	bemi->addFile("pee.img", pee);
	vector<char> v;
	v.push_back('T');
	v.push_back('A');
	poop->write(v);
	poop->read();
	bemi->openFile("pee.img");

	return 0;
}
