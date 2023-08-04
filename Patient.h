#pragma once
#include"personType.h"
#include"Corona.h"
#include"GeneralWard.h"
class Patient :public personType, public Corona, public GeneralWard
{
	int patientbedno;
	int patientroomno;
	int totalbeds = 30;
	static int ReservedBedsRoom_1;//These are the total reserved beds in a room
	static int ReservedBedsRoom_2;//We Will Assign this to the patient bed number + 1
	static int ReservedBedsRoom_3;
	char* admit_date;
	char* discharge_date;
	Patient* prev;
	Patient* next;
public:
	Patient();
	void SetPersonData(string iid, string iname, string icnic, string igender, string ibloodgroup,string age);
	void insertPatient(Patient** patientData, string iid, string iname, string iage, string icnic, string igender, string ibloodgroup, int ipatientbedno, int ipatientroomno, string iTestResult, char option);
	void InputSinglePatient(Patient** patientData, char option);
	bool PatientIdUnique(Patient *patientData, string tempid);
	void SearchPatient(Patient **patientdata, char option, char choice);
	void ImportTotalReservedBeds(Patient **patientdata);
	void ExportTotalReservedBeds(Patient** patientdata);
	void ImportPatientsData(Patient **patientdata, char  option);
	void ExportPatientsData(Patient* patientdata, int data, char option);
	void PatientAdmit(Patient* patientdata, int data, char  option);
	void PatientDischarged(Patient** patientdata, string patientID, int data,char  option);
	void DisplayPatientData(char option);
	void DisplayAllPatients(Patient *patientdata,char option);
	~Patient();
};
