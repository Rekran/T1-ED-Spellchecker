#include "Header.h"
#include <iostream>

class LinkedList{
	private:
		Header header;
	public:
		LinkedList();
		~LinkedList();
		void prepend(char *word);
		void print();
		int getSize();
		Node* getHead();
		
};
