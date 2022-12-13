//  Define the TextFile class here
#include "TextFile.h"
#include <iostream>
#include "AbstractFile.h"
#include "AbstractFileVisitor.h"

using namespace std;
TextFile::TextFile(string s) {
	name = s;
}

unsigned int TextFile::getSize() {
	unsigned int s = contents.size();
	return s;
}

AbstractFile* TextFile:: clone(string n) {
	string tempname = name;
	name = n + ".txt";
	AbstractFile* temp = new TextFile(*this);
	name = tempname;
	return temp;
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
	return Success;
}

vector<char> TextFile::read() {
	return contents;
}

void TextFile::accept(AbstractFileVisitor* a) {
	a->visit_TextFile(this);
}


