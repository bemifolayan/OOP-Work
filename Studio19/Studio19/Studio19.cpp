// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\ImageFile.h"
#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char* argv[])
{
	AbstractFile* text = new TextFile("anything");
	vector<char> v;
	v = text->read();
	v.push_back('T');
	v.push_back('A');
	text->write(v);
	cout << text->read()[0] << endl;
	return 0;
}
