// definition of ImageFile class here
#include "ImageFile.h"
#inclue<vector>
#includ<iostream>
using namespace std;

ImageFile::ImageFile(string s) {
	name = s;
	size = 0;
}

int ImageFile::getSize() {
	return contents.size();
}

string ImageFile::getName() {
	return name;
}

int ImageFile::write(vector<char> c) {
	size = c[c.size() - 1];
	int s = size - 48;

	if (s * s != c.size() - 1)
		return sizeMismatch;

	for (int i = 0; i < contents.size(); i++) {
		if(c[i] == 'X' || c[i] == ' ')
			contents[i] = c[i];
		else {
			contents = new vector<char>();
			size = 0;
			return incorrectPixel;
		}
	}
}

int ImageFile::append(vector<char> c) {
	return appendNotSupported;
}

void ImageFile::read() {
	int s = size - 48;
	for (int y = 0; y < s; y++) {
		for (int x = 0; x < s; x++) {
			cout << contents[y * s + x] << " ";
		}
		cout << endl;
	}
}