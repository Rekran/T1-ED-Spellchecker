#include <math.h>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include"Node.h"

using namespace std;
#define MAX 380000


class HashTable{
	private:
		Node *table[MAX];
	public:
		
		unsigned int hash(char *word);
		void loadDictionary(char *path);
		
		void quadraticInsert(char *word);
		bool quadraticSearch(char *word);
		
		void linearInsert(char *word);
		bool linearSearch(char *word);
		
		void print();

		HashTable();
		~HashTable();
};
