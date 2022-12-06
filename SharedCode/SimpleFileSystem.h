#pragma once
// declaration of SimpleFileSystem class goes here
#include "AbstractFileSystem.h"
#include <iostream>
#include<map>
#include<set>

using namespace std;

class SimpleFileSystem : public AbstractFileSystem {
private:
	map<string, AbstractFile*> files;
	set<AbstractFile*> openFiles;
public:
	int addFile(string filename, AbstractFile* f);
	int createFile(string s) ;
	int deleteFile(string s);
	AbstractFile* openFile(string s);
	int closeFile(AbstractFile* f) ;
	set<string> getFileNames();
};
