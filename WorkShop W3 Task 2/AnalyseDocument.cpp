#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include"AnalyseDocument.h";
using namespace std;

DocSummary::DocSummary(string docName)
{
	filename = docName;
}

void DocSummary::printSummary()
{
	cout << "Number of words: " << numberOfWords << "\n";
	cout << "Number of sentences: " << numberOfSentences << "\n";
	for (int i = 0; i < wordList.size(); i++) {
		cout << wordList[i].getWord() << " " << wordList[i].getCount() << "\n";
	}
}

void DocSummary::increaseSentenceCount(string word) {
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == '.' || word[i] == '!' || word[i] == '?')
		{
			numberOfSentences++;
		}
	}	
}

void DocSummary::removePunc(string* word) {
	string noPuncWord = *word;
	string tempWord;

	for (int i = 0; i < noPuncWord.length(); i++)
	{
		if (!ispunct(int(noPuncWord[i])))
		{
			tempWord += noPuncWord[i];
		}
	}
	*word = tempWord;
}

void DocSummary::addWord(string word) {
	
		for(auto& value: wordList)
		{
			if (value.getWord() == word) 
			{
				value.setCount(1);
				return;
			}
		}

		WordCountPair newOne(word, 1);
		wordList.push_back(newOne);
		return;
		
}

void DocSummary::analyseDocument() {
	ifstream file(filename);
	string text;
	string textword;
	
	
	while (file) {
		file >> textword;
		
		if (!textword.empty()) {
			numberOfWords++;
			increaseSentenceCount(textword);
			removePunc(&textword);
			addWord(textword);
		}
		
		textword.clear();
	}
	file.close();
}
