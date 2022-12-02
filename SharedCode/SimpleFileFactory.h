#pragma once
#include "AbstractFileFactory.h"
#include<iostream>
// Studio 18 - simplefilefactory class declaration goes here
class SimpleFileFactory : public AbstractFileFactory {
public:
	AbstractFile* createFile(string s);

};
