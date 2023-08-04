#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;
#include "Corona.h"
Corona::Corona()
{
	this->CurrentTest = ctime(&now);
	PreviousTest = CurrentTest;
}
void Corona::inputTest()
{
	this->PreviousTest = CurrentTest;
	this->CurrentTest = ctime(&now);
	bool input = true;
	do
	{
		cin.ignore();
		input = false;
		cout << "\n\n  Enter Test Result  :  ";
		getline(cin, TestResult);
		if (TestResult == "+ve" || TestResult == "-ve" || TestResult == "Positive" || TestResult == "Negative")
		{
			input = false;
		}
		else
		{
			input = true;
		}
	} while (input);
}

string Corona::ReturnResult()
{
	return this->TestResult;
}

void Corona::displayTest()
{
	cout << "\n\n\t  Current Test Date  :  " << CurrentTest;
	cout << "\n\t  Previous Test Date  :  " << PreviousTest;
	cout << "\n\t  Test Result  :  " << TestResult;
}
