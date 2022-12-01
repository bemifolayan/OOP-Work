//  Define the TextFile class here
#include "TextFile.h"
#include <iostream>
#include "AbstractFile.h"
using namespace std;
TextFile::TextFile(string s) {
	name = s;

}

unsigned int TextFile::getSize() {
	unsigned int s = contents.size();
	return s;
}

string TextFile::getName() {
	return name;
}

int TextFile::write(vector<char> c) {

	contents = c;
	return 0;
}

int TextFile::append(vector<char> c) {
	for (unsigned int i = 0; i < c.size(); i++) {
		contents.push_back(c[i]);
	}
	return 0;
}

void TextFile::read() {
	for (unsigned int i = 0; i < contents.size(); i++) {
		cout << contents[i];
	}
	cout<<endl;
}



