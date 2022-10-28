#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>

using namespace std;

class WordCountPair
{
public:
	WordCountPair(); // Defaults constructor. Sets word to null string and count to zero.
	WordCountPair(string word, int count); /*Takes a word and its count as parameters 
											and initialize the word and count member 
											variables. Sets count to one if the second 
											parameter is not supplied.*/
	string getWord(); //Sets word variable with the input
	void setWord(); //Returns word 
	int setCount(); //Sets count variable with the input 
	int getCount(); //Set count variable with the input 

private:
	string word; //is a string that holds a word
	int Count; //is an integer that holds the number of occurrences of the word in the document

};

