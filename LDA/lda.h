#ifndef LDA_H
#define LDA_H
#include <vector>
#include <map>

typedef std::map<int, int*>::iterator It;

class Lda{
	
private:
	//number of topics
	int K;

	//number of documents
	int M;

	//hyperparameter alpha (value found on other implementations)
	double alpha;

	//hyperparameter beta (value found on other implementations)
	double beta;

	//array of the sentences to do lda on
	char** documents;

	//word topic assignments in each document
	int** assignment;

	//matrix N corresponding to the no times topic k found in document d
	int** N;

	//matrix v corresponding to the number of times that a word w(d,n) is found in topic k
	std::map<int,int*> v;

	//counts the number of words in a document
	int countWords(const char* filename);

public:
	//constructor
	Lda(int noDocuments, char* inputDocuments[], int noTopics);

	//destructor
	~Lda();

	//outputs the documents
	void outputDocuments();

	//repeats the algorithm for the given number of iterations
	void algorithm(int noRepetitions);

	//calculates the probability of a token being assigned a topic given the rest of the documents
	double calculateStatistic(int topic, int word, int document);

	void outputTopicWordAssignment(std::ostream& out);

	void outputWordsInEachTopic(std::ostream& out);


};

#endif