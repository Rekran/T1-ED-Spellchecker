#include "LinkedList.h"
#include <math.h>
#include <iostream>
#include <string.h>
#include <fstream>
 using namespace std;
#define MAX 2050


class HashTable{
	private:
		LinkedList table[MAX];
	public:
		
		unsigned int hash(char *word);
		void loadDictionary(char *path);
		
		void insert(char *word);
		bool search(char *word);
		
		void print();
		HashTable();
		~HashTable();
};
