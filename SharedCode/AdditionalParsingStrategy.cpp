#include "AdditionalParsingStrategy.h"
#include <iostream>
#include <vector>
#include<string>
using namespace std;

vector<string> AdditionalParsingStrategy::parse(string s) {
	vector<string> v;
	v.push_back(s);
	v.push_back(s);
	return v;
}