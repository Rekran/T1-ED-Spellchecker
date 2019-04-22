#include "HashTable.h"


HashTable::HashTable(){
	for(int i = 0; i< MAX ; i++)
		this->table[i] = NULL;
};
HashTable::~HashTable(){
	for(int i = 0; i < MAX;i++){
	
		delete(this->table[i]);

	}
}


unsigned int HashTable::hash(char *word){
	

	int size = strlen(word);

	unsigned int value = 5381;//
	
	for(int i = 0;i< size;i++ ){
	
	value = value * 33  + word[i];
	
	}

	return value;
};



void HashTable::loadDictionary(char *path){
  string line;
  
  ifstream myfile(path);
  if (myfile.is_open()){

    while ( myfile>>line )
    {
    	int n = line.length() + 1;
		char *char_array = new char[n];	
		strcpy(char_array,&line[0]);
    	this->quadraticInsert(char_array);
    }
    myfile.close();
  }
	
};


void HashTable::quadraticInsert(char *word){
	int i = 0;
	unsigned int hash = this->hash(word);
	Node *N1 = new Node();
	N1->word = word;
	
	
	if( this->table[(hash + (i*i))%MAX] == NULL)
		this->table[(hash + (i*i))%MAX] = N1;
	else{
		
		while(this->table[(hash + (i*i))%MAX] != NULL){
			i++;
		}
		this->table[((hash + (i*i))%MAX)] = N1;
	}
};


bool HashTable::quadraticSearch(char *word){
	int i = 0;
	unsigned int hash = this->hash(word);

	if( this->table[(hash + (i*i))%MAX] == NULL){
		return false;
	}else{
		while(this->table[(hash + i*i)%MAX] != NULL){

			if(strcmp(word,this->table[(hash + i*i)%MAX]->word) == 0)
				return true;
			else{
				i++;
			}
		}
		return false;
	}
};

void HashTable::linearInsert(char *word){
	int i = 0;
	unsigned int hash = this->hash(word);
	Node *N1 = new Node();
	N1->word = word;
	
	
	if( this->table[(hash + i)%MAX] == NULL)
		this->table[(hash + i)%MAX] = N1;
	else{
		while(this->table[(hash + i)%MAX] != NULL){
			i++;
		}
		this->table[(hash + i)%MAX] = N1;
	}
};


bool HashTable::linearSearch(char *word){
	int i = 0;
	unsigned int hash = this->hash(word);

	if( this->table[(hash + i)%MAX] == NULL){
		return false;
		
	}else{
		while(this->table[(hash + i)%MAX] != NULL){

			if(strcmp(word,this->table[(hash + i)%MAX]->word) == 0)
				return true;
			else
				i++;
				
		}
		return false;
	}
};


void HashTable::print(){
	for(int i = 0;i < MAX ;i++){
		if(this->table[i] != NULL){
			cout<<"["<<i<<"]"<<this->table[i]->word<<endl;
			
		}
	}
};
