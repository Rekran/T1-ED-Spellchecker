#include "Node.h"
#include <stdlib.h>


Node::Node(){
	
}

Node::~Node(){
	delete(this->word);
}
