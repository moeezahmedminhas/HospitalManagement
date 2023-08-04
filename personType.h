#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
using namespace std;
class personType
{
protected:
	string id, name, cnic, gender, bloodgroup,age;
public:
	personType();
	virtual void SetPersonData(string iid, string iname, string icnic, string igender, string ibloodgroup,string age)=0;
};

