#pragma once
#include "AbstractFile.h"
#include<vector>
#include<iostream>
#include "AbstractFileVisitor.h"
using namespace std;
// TextFile declaration goes here
class TextFile : public AbstractFile {
public:
	TextFile(string s);
	unsigned int getSize();
	string getName();
	int write(vector<char> c);
	int append(vector<char> g);
	vector<char> read();
	void accept(AbstractFileVisitor* a);
private:
	vector<char> contents;
	string name;
};
