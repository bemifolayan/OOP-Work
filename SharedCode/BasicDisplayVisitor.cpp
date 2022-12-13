// definitions of basic display visitor here

#include"BasicDisplayVisitor.h"


void BasicDisplayVisitor::visit_TextFile(TextFile* t) {
	for (unsigned int i = 0; i < t->read().size(); i++) {
		cout << t->read()[i];
	}
	cout << endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* t) {

	int s = int(sqrt(t->getSize()));
	for (int y = 0; y < s; y++) {
		for (int x = 0; x < s; x++) {
			char c = t->read()[y*s + x];
			cout << c;
		}
		cout << endl;
	}
}


