#include "HashTable.h"
#include<vector>
#include<ctime>

using namespace std;

int main() {

vector<string>erros;
ofstream result("result.txt");
int words = 0;
double tempo;
clock_t t0, tf;

HashTable ht = HashTable();
ht.loadDictionary("dictionary.txt");


t0 = clock();

string word;
  ifstream text("text.txt");
  if (text.is_open()){
    
    while ( text>>word )
    {
			
      words++;
    	if(!ht.linearSearch(&word[0]))
			  erros.push_back(word);

    }
    text.close();
  }

tf = clock();

tempo = ( (double) (tf - t0) ) / (CLOCKS_PER_SEC/1000);

result<<"Número total de palavras do texto:"<<words<<"\n";
result<<"Tempo total da verificação:"<< tempo <<"ms"<<"\n";
result<<"Número de palavras que falharam no spell check:"<< erros.size() << "\n";
result<<"Lista de palavras que falharam no spell check:\n";
result<<"Num. Ocorrencia - Palavra\n";
result<<"-------------------------------------------------------------------------------\n";

for(int i = 0; i < erros.size();i++)
    result<< i+1<<" - "<<erros[i]<<"\n";
	  

	return 0;
}
