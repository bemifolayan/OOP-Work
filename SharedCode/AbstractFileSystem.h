#pragma once
// declaration of the interface all file systems provide goes here
#include "AbstractFile.h"
#include<iostream>
#include<set>
using namespace std;

class AbstractFileSystem {
public:
	virtual int addFile(string filename, AbstractFile* f) = 0;
	virtual int deleteFile(string s) = 0;
	virtual AbstractFile* openFile(string s) = 0;
	virtual int closeFile(AbstractFile* f) = 0;
	virtual set<string> getFileNames() = 0;
};
