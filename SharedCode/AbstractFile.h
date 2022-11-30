#pragma once
#include<vector>
#include<iostream>
using namespace std;
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
class AbstractFile {
public:
	virtual void read() = 0;
	virtual int write(vector<char> v) = 0;
	virtual int append(vector<char> c) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;
};

enum errs {
	success,
	failedToWrite,
	appendNotSupported,
	incorrectPixel,
	sizeMismatch
};
