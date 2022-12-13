#include "PasswordProxy.h"
#include <iostream>
#include <string>
#include<vector>

PasswordProxy::PasswordProxy(AbstractFile* f, string s) {
	file = f;
	password = s;
}

PasswordProxy::~PasswordProxy() {
	delete file;
}

AbstractFile* PasswordProxy ::clone(string n) {
	PasswordProxy* temp = new PasswordProxy(*this);
	temp->file = this->file->clone(n);
	temp->password = this->password;
	return temp;
}

string PasswordProxy::passwordPrompt() {
	string s;
	cout << "Password: " << endl;
	getline(cin, s);
	return s;
}

bool PasswordProxy::matches(string s) {
	if (s == password) {
		return true;
	}
	return false;
}

vector<char> PasswordProxy::read() {
	string d = passwordPrompt();
	bool b = matches(d);
	vector<char> v;
	if (b) {
		return file->read();
	}
	else {
		return v;
	}
}


int PasswordProxy::write(vector<char> v) {
	string d = passwordPrompt();
	bool b = matches(d);
	if (b) {
		return file->write(v);
	}
	else {
		return wrongPassword;
	}
}


int PasswordProxy::append(vector<char> c) {
	string d = passwordPrompt();
	bool b = matches(d);
	if (b) {
		return file->append(c);
	}
	else {
		return wrongPassword;
	}
}

unsigned int PasswordProxy::getSize() {
	return file->getSize();
}

string PasswordProxy:: getName() {
	return file->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* a) {
	string d = passwordPrompt();
	bool b = matches(d);
	if (b) {
		 file->accept(a);
	}
}