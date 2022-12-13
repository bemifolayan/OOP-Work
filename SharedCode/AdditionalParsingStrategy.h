#pragma once
#include "AbstractParsingStrategy.h"
#include<vector>
#include<iostream>
using namespace std;
class AdditionalParsingStrategy: public AbstractParsingStrategy {
public:
	vector<string> parse(string s);
};