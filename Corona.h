#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;
class Corona
{
protected:
	char* CurrentTest;
	char* PreviousTest;
	string TestResult;
	time_t now = time(0);
public:
	Corona();
	void inputTest();
	string ReturnResult();
	void displayTest();
};
