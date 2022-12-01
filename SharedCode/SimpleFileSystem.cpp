// define methods of SimpleFileSystem class here
#include <iostream>
#include<map>
#include<set>
#include "SimpleFileSystem.h"
#include "ImageFile.h"
#include "TextFile.h"
using namespace std;

int SimpleFileSystem::addFile(string filename, AbstractFile* f) {
	for (auto iter = files.begin(); iter != files.end(); iter++) {
		if (iter->first == filename)
			return fileAlreadyExists;
	}
	if (f == nullptr) {
		return nullPointer;
	}
	files.insert(pair<string, AbstractFile*>(filename, f));
	return success;
}


int SimpleFileSystem::createFile(string s) {
	for (auto iter = files.begin(); iter != files.end(); iter++) {
		if (iter->first == s)
			return fileAlreadyExists;
	}
	int pos = s.find('.');
	if (s.substr(pos + 1) == "txt") {
		AbstractFile* t= new TextFile(s);
		files.insert(pair<string, AbstractFile*>(s, t));
		return success;
	}
	else if (s.substr(pos + 1) == "img") {
		AbstractFile* t = new ImageFile(s);
		files.insert(pair<string, AbstractFile*>(s, t));
		return success;
	}
	return incorrectFileType;
}

int SimpleFileSystem::deleteFile(string s) {
	for (auto iter = files.begin(); iter != files.end(); iter++) {
		if (iter->first == s) {
			for (auto i = openFiles.begin(); i != openFiles.end(); i++) {
				if (*i == iter->second) {
					return fileOpen;
				}
			}
			delete iter->second;
			files.erase(s);
			return success;
		}
	}
	return fileDNE;
}

AbstractFile* SimpleFileSystem::openFile(string s) {
	for (auto iter = files.begin(); iter != files.end(); iter++) {
		if (iter->first == s) {
			for (auto i = openFiles.begin(); i != openFiles.end(); i++) {
				if (*i == iter->second) {
					return nullptr;
				}
			}
			openFiles.insert(iter->second);
			return iter->second;
		}
	}
	return nullptr;
}

int SimpleFileSystem::closeFile(AbstractFile* f) {
	for (auto i = openFiles.begin(); i != openFiles.end(); i++) {
		if (*i == f) {
			openFiles.erase(f);
			return success;
		}
	}
	return fileNotOpen;
}