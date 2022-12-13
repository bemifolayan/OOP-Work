#pragma once
#include "AbstractFile.h"
class PasswordProxy : public AbstractFile {
private:
	AbstractFile* file;
	string password;
public:
	PasswordProxy(AbstractFile* f, string s);
	~PasswordProxy();
	vector<char> read();
	int write(vector<char> v);
	int append(vector<char> c);
	unsigned int getSize();
	AbstractFile* clone(string n);
	string getName();
	void accept(AbstractFileVisitor* a);

protected:
	string passwordPrompt();
	bool matches(string s);

};
