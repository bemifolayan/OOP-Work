#pragma once
#include<iostream>
#include<vector>
#include "AbstractFile.h"
#include "AbstractFileVisitor.h"
using namespace std;
// Image file class declaration here
class ImageFile:public AbstractFile {
private:
	string name;
	vector<char> contents;
	char size;

public:
	ImageFile(string s);
	vector<char> read();
	int write(vector<char> c);
	int append(vector<char> c);
	unsigned int getSize();
	string getName();
	void accept(AbstractFileVisitor* a);
};