// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char* argv[])
{
	AbstractFile* f = new ImageFile("nudes");
	vector<char> v;
	v.push_back('X');
	v.push_back('X');
	v.push_back(' ');
	v.push_back('X');
	v.push_back('2');
	f->write(v);
	//f.read();
	//cout<<f.getSize()<<endl;
	//cout<<f.getName()<<endl;
	//cout<<f.append(v)<<endl;

	SimpleFileSystem s;
	AbstractFile* nudesf = new TextFile("sexts");
	s.addFile("nudes", f);
	s.addFile("not nudes", nudesf);
	s.createFile("file");
	cout << s.deleteFile("files") << endl;
	s.deleteFile("file");
	s.openFile("nudes");
	return 0;
}

