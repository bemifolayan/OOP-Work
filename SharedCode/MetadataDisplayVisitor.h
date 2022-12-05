#pragma once
// declaration of MetadataDisplayVisitor here
#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include<iostream>
using namespace std;
class MetadataDisplayVisitor : public AbstractFileVisitor {
public:	
	void visit_TextFile(TextFile* text);
	void visit_ImageFile(ImageFile* image);
};