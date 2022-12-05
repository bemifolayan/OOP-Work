// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"


void MetadataDisplayVisitor::visit_TextFile(TextFile* t){
	cout << t->getName() << endl;
	cout << t->getSize() << endl;
	cout << "text" << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* t) {
	cout << t->getName() << endl;
	cout << t->getSize() << endl;
	cout << "image" << endl;
}
