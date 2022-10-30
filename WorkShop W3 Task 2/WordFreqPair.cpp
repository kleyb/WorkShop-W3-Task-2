#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include "WordFreqPair.h";

using namespace std;



WordCountPair::WordCountPair() {
	word;
	Count = 0;
}
WordCountPair::WordCountPair(string word,int count) {
	this->word = word;
	Count = count;
}

void WordCountPair::setWord(string word)
{
	this->word = word;
}
void WordCountPair::setCount(int count)
{
	Count = count;
}
int WordCountPair::getCount()
{
	return Count;
}
string WordCountPair::getWord() {
	return word;
}
