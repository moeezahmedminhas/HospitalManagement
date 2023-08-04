#pragma once
#include"personType.h"
class Doctor :public personType
{
	int DoctorRoomNo;
	string DoctorRole;
	static int DoctorsInRoom_1;//These are the total reserved beds in a room
	static int DoctorsInRoom_2;//We Will Assign this to the Doctor bed number + 1
	static int DoctorsInRoom_3;
	Doctor* next = NULL;
	Doctor* prev = NULL;
public:
	Doctor();
	void SetPersonData(string iid, string iname, string icnic, string igender, string ibloodgroup, string age);
	void insertDoctor(Doctor** doctorData, string iid, string iname, string iage, string icnic, string igender, string ibloodgroup, int iroomno, string irole, char option);
	void InputSingleDoctor(Doctor** doctorData, char option);
	bool DoctorIdUnique(Doctor* doctorData, string tempid);
	void SearchDoctor(Doctor** doctorData, char option, char choice);
	void ExportTotalDoctors(Doctor** doctorData);
	void ImportTotalDoctors(Doctor** doctorData);
	void ImportDoctorsData(Doctor** doctorData, char  option);
	void ExportDoctorsData(Doctor* doctorData, int data, char option);
	void DoctorAdmit(Doctor* doctorData, int data, char  option);
	void DoctorDischarged(Doctor** doctorData, string DoctorID, int data, char  option);
	void DisplayDoctorData(char option);
	void DisplayAllDoctors(Doctor* doctorData, char option);
	~Doctor();
};
