#include "Node.h"
#include <stdlib.h>

Node::Node(){
	this->Next = NULL;
}

Node::~Node(){
	delete(this->Next);
	delete(this->word);
}
