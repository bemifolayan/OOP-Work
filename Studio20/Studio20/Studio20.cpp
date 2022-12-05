// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<vector>
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\BasicDisplayVisitor.h"
#include "..\..\\SharedCode\MetadataDisplayVisitor.h"
#include "..\..\\SharedCode\PasswordProxy.h"

using namespace std;
int main(int argc, char* argv[])
{
	AbstractFile* t = new TextFile("receipts");
	PasswordProxy p(t, "whispers");
	vector<char> v = { 'T', 'R', 'U' };
	p.write(v);
	p.read();
	AbstractFileVisitor* r = new BasicDisplayVisitor();
	AbstractFileVisitor* s = new MetadataDisplayVisitor();

	p.accept(r);
	p.accept(s);

	return 0;
}

