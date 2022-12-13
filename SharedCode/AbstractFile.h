#pragma once
#include<vector>
#include<iostream>
#include "AbstractParsingStrategy.h"
class AbstractFileVisitor;
using namespace std;
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
class AbstractFile {
public:
	virtual vector<char> read() = 0;
	virtual int write(vector<char> v) = 0;
	virtual int append(vector<char> c) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;
	virtual void accept(AbstractFileVisitor* a) = 0;
	virtual AbstractFile* clone(string n) = 0;
};

enum errs {
	Success,
	failedToWrite,
	appendNotSupported,
	incorrectPixel,
	sizeMismatch,
	fileAlreadyExists,
	nullPointer,
	incorrectFileType,
	fileNotOpen,
	fileOpen,
	fileDNE,
	wrongPassword, 
	failedToInsert,
	quit,
	fileNotCreated,
	fileNotAdded, 
	commandFail,
	commandDNE,
	commandErr

};
