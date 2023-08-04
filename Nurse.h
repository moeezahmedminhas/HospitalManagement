#pragma once
#include"personType.h"
class Nurse :public personType
{
	int nurseRoomNo;
	string nurseRole;
	static int NursesInRoom_1;//These are the total Nurse in a room
	static int NursesInRoom_2;//We Will Assign this to the Nurse + 1
	static int NursesInRoom_3;
	Nurse* next = NULL;
	Nurse* prev = NULL;
public:
	Nurse();
	void SetPersonData(string iid, string iname, string icnic, string igender, string ibloodgroup, string age);
	void insertNurse(Nurse** nurseData, string iid, string iname, string iage, string icnic, string igender, string ibloodgroup, int iroomno, string irole, char option);
	void InputSingleNurse(Nurse** Nursedata, char option);
	bool NurseIdUnique(Nurse* nurseData, string tempid);
	void SearchNurse(Nurse** nurseData, char option, char choice);
	void ExportTotalNurses(Nurse** nurseData);
	void ImportTotalNurses(Nurse** nurseData);
	void ImportNursesData(Nurse** nurseData, char  option);
	void ExportNursesData(Nurse* nurseData, int data, char option);
	void NurseAdmit(Nurse* nurseData, int data, char  option);
	void NurseDischarged(Nurse** nurseData, string NurseID, int data, char  option);
	void DisplayNurseData(char option);
	void DisplayAllNurses(Nurse* nurseData, char option);
	~Nurse();
};
