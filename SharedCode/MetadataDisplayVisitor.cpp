// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"
#include<iomanip>

void MetadataDisplayVisitor::visit_TextFile(TextFile* t){
	cout.width(21);
	cout << t->getName();
	cout.width(6);
	cout << "text";
	cout.width(5);
	cout << t->getSize() << endl;
	
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* t) {
	cout.width(21);
	cout << t->getName();
	cout.width(6);
	cout << "image";
	cout.width(5);
	cout << t->getSize() << endl;

}
