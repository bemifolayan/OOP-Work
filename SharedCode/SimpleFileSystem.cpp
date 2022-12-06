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
	return Success;
}

set<string> SimpleFileSystem::getFileNames() {
	set<string> names;
	for (auto iter = files.begin(); iter != files.end(); iter++) {
		names.insert(iter->first);
	}
	return names;
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
			return Success;
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
			return Success;
		}
	}
	return fileNotOpen;
}
