// definition of ImageFile class here
#include "ImageFile.h"
#include<vector>
#include<iostream>
#include "AbstractFileVisitor.h"

using namespace std;

ImageFile::ImageFile(string s) {
	name = s;
	size = 0;
}

void ImageFile::accept(AbstractFileVisitor* a) {
	a->visit_ImageFile(this);
}

unsigned int ImageFile::getSize() {
	unsigned int s = unsigned int(contents.size());
	return s;
}

string ImageFile::getName() {
	return name;
}

int ImageFile::write(vector<char> c) {
	size = c[c.size() - 1];
	int s = int(size) - 48;

	if (s * s != c.size() - 1)
		return sizeMismatch;

	for (unsigned int i = 0; i < c.size() - 1; i++) {
		if (c[i] == 'X' || c[i] == ' ')
			contents.push_back(c[i]);
		else {
			contents.clear();
			size = 0;
			return incorrectPixel;
		}
	}
	return Success;
}

AbstractFile* ImageFile::clone(string n) {
	string tempname = name;
	name = n + ".img";
	AbstractFile* temp = new ImageFile(*this);
	name = tempname;
	return temp;
}
int ImageFile::append(vector<char> c) {
	return appendNotSupported;
}

vector<char> ImageFile::read() {
	return contents;
}
