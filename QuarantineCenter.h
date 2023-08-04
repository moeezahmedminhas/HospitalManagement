#pragma once
#include<iostream>
#include"Room.h"
#include<string>
#include<fstream>
using namespace std;
class QuarantineCenter:public Room
{
protected:

	static string location;
	static string centerid;
	static string contactnumber;
	Room RoomData[3];
	static string adminpassword;
	string userpassword;
public:
	QuarantineCenter();
	void CenterData();
	void inputcenterdata();
	void exportcenterdata();
	void importcenterdata();
	bool checkadminpass(string pass);
	bool checkuserpass(string pass);
	void setuserpass();
	void setadminpass();
	void displaycenterdata();
	void InputDoctor(char option);
	void searchDoctor(char option, char choice);
	void InputPatient(char option);
	void searchPatient(char option, char choice);
	void InputNurse(char option);
	void searchNurse(char option, char choice);
	void ImportAllFiles(char option);//Doctor indincates that this file is for doctor record and last integer indicates room number
};
