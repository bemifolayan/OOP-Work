// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"
#include "ImageFile.h"
#include "TextFile.h"
AbstractFile* SimpleFileFactory::createFile(string s) {
	int pos = s.find('.');
	if (s.substr(pos + 1) == "txt") {
		AbstractFile* t = new TextFile(s);
		return t;
	}
	else if (s.substr(pos + 1) == "img") {
		AbstractFile* t = new ImageFile(s);
		return t;
	}
	return nullptr;
}
