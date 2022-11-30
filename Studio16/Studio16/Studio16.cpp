// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char* argv[])
{
	AbstractFile *t = new TextFile("me");

	vector<char> d;
	d.push_back('l');
	d.push_back('o');
	t->write(d);
	int result = t->append(d);
	t->read();
	cout << t->getName() << " " << t->getSize() << endl;
	return 0;
}


