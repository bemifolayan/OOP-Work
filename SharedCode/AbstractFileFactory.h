#pragma once
#include "AbstractFile.h"
#include<iostream>
using namespace std;
// studio 18 - file factory interface declared here

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string s) = 0;
};
