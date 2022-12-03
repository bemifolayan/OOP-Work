#pragma once
#include "AbstractFile.h"
#include<vector>
#include<iostream>

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
private:
	vector<char> contents;
	string name;
};
