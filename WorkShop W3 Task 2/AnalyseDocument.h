#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include "WordFreqPair.h"

using namespace std;

class DocSummary
{
public:
	DocSummary(string docName); //Takes document name as input and initializes class variables
	void printSummary(); /*	Prints the number of sentences, the 
							number of words and each word with its 
							frequency (see format at the end of the 
							assignment) */
	void analyseDocument(); /*	Reads the document word by word and 
								calls addWord, removePunc, 
								updateSentenceCount functions in the correct 
								order to fill in the object properties*/

private:
	int numberOfWords; //is an integer that indicates the number of words in the document 
	int numberOfSentences; //is an integer that indicates the number of sentences in the document 
	string filename; //is a string that shows the name of the document
	vector<WordCountPair> wordList; //is a vector of WordFreqPair objects. Each entry of the vector holds 
									// a WordFreqPair object that keeps the wordand its count.
	void increaseSentenceCount(string word); /*	Takes a word as an input and increases 
												the variable numberOfSentences if the 
												given word contains a “.”, ”!” or “?” 
												symbol. */
	void addWord(string word); /*	Adds a given word into the wordList 
									vector if it does not exist in the vector. 
									Otherwise it increases the corresponding 
									count entry in vector. */
	void removePunc(string* word);
};
