// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there. 
//

#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include "WorkShop W3 Task 2.h"
#include "AnalyseDocument.h"
using namespace std;



int main()
{
	DocSummary doc1("input.txt");
	doc1.analyseDocument();
	doc1.printSummary();

	//getchar();
}