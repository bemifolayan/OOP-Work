#pragma once
// declaration of BasicDisplayVisitor here
#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include"ImageFile.h"
class BasicDisplayVisitor : public AbstractFileVisitor{
public:
	void visit_TextFile(TextFile* t);
	void visit_ImageFile(ImageFile* t);
};
