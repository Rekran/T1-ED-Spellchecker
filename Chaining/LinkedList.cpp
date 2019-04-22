#include "LinkedList.h"

LinkedList::LinkedList(){	
}
LinkedList::~LinkedList(){

	Node * aux = this->getHead();

		delete(aux);
	
}

int LinkedList::getSize(){
	
	return this->header.size;
}

Node* LinkedList::getHead(){
	
	return this->header.head;
}


void LinkedList::print(){
	
	std::cout<<getSize();
		

}

void LinkedList::prepend(char *word){
	if(header.head == NULL){
		Node *N1 = new Node();
		N1->word = word;
		
		this->header.head = N1;
		this->header.tail = N1;
		
		this->header.size += 1;	
			
	}else{
		
		Node *N1 = new Node();
		N1->word = word;
		
		N1->Next = header.head;
		this->header.head = N1;
		
		this->header.size += 1;	
	}

};



