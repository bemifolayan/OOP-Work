#include "RenameParsingStrategy.h"
#include <iostream>
#include <vector>
#include<string>
using namespace std;

vector<string> RenameParsingStrategy::parse(string s) {
	vector<string> v;
	int pos = s.find(' ');
	string existingFile = s.substr(0, pos);
	v.push_back(s);
	v.push_back(existingFile);
	return v;
}