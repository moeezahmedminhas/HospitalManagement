#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<fstream>
using namespace std;
class GeneralWard
{
protected:
	string diseasename;
public:
	GeneralWard();
	void InputDisease();
	void DisplayDisease();
};