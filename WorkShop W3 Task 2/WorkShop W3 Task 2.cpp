// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there. 
//

#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include "WorkShop W3 Task 2.h"

using namespace std;

int numberOfWords{ 0 };
int numberOfSentences{ 0 };
map<string, int> frequency;
string word;


void printSummary() {
    std::cout << "Number of sentences: " << numberOfSentences << endl;
    std::cout << "Number of words: " << numberOfWords << endl;

    map<string, int>::iterator itr;
    for (itr = frequency.begin(); itr != frequency.end(); itr++)
    {
        std::cout << itr->first << " " << itr->second << "\n";
    }
}
void removePunc(std::string *newWord) {
    string noPuncWord = *newWord;
    string tempWord;
    
    for (int i = 0; i < noPuncWord.length(); i++)
    {
        if (!ispunct(int(noPuncWord[i])))
        {
            tempWord += noPuncWord[i];
        }
    }
    *newWord = tempWord;

}
void addWord(std::string word, vector<string> *wordList)
{
    string newWord;
    vector<string> pointWordList(* wordList);
    
    
    std::cout << "Please enter the word you would like to enter into the list:\n ";
    std::getline(cin, newWord);
    removePunc(&newWord);
    for (int i = 0; i < pointWordList.size(); i++)
    {
        if (newWord == pointWordList[i]) // Check if newWord is equal to the element at the list , if true adds one to the frequency at position 'newWord'
        {
            frequency.at(newWord)++;
            break;
        }
        else if (frequency.find(newWord) == frequency.end()) //tries to find newWord at frequency map and check if it is equal the last
        {
            frequency.insert(pair<string, int>(newWord, 1));
            //break;
        }
    }
    //*wordList.push_back(newWord);
    pointWordList.push_back(newWord);
    *wordList = (pointWordList);
    //numberOfWords++;
}

void analyseDocument() {

}


void updateSentenceCount(std::string& text, int* i)
{
    if (text[*i] == '.' || text[*i] == '!' || text[*i] == '?')
    {
        numberOfSentences++;
    }
}

int main()
{
    vector<string> wordList;

    string filename = "input.txt";

    ifstream file(filename);
    string text = "";

    while (getline(file, text)) {
        std::cout << text << endl;

        for (int i = 0; i < text.length(); i++)
        {
            word = word + text[i];

            if (int(text[i]) >= 32 && int(text[i] <= 64)) {
                //removePunc(&word);
                wordList.push_back(word);
                if (frequency.find(word) != frequency.end())
                {
                    frequency.at(word)++;
                }
                else
                {
                    frequency.insert(pair<string, int>(word, 1));
                }

                updateSentenceCount(text, &i);
                word.clear();
                
            }
        }
    }

    addWord(word, &wordList);
    numberOfWords = wordList.size();
    printSummary();
    
    file.close();

}
