#pragma once
#include<vector>
#include<iostream>
using namespace std;
class AbstractParsingStrategy {
public:
	virtual vector<string> parse(string s) = 0;
};
