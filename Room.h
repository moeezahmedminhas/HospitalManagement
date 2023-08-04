#pragma once
#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"
class Room :public Patient,public Nurse,public Doctor
{
protected:
	int RoomNo = 0;
	int number_of_Beds = 30;
	Patient* patientData;
	Nurse* nurseData;
	Doctor* doctorData;
public:
	Room();
	void InputPatientData(Room room[], char option);//will take person data and assing bedno
	void ModifyPatientData(Room room[], char option, char choice);
	void InputNurseData(Room room[], char option);
	void ModifyNurseData(Room room[], char option, char choice);
	void InputDoctorData(Room room[], char option);
	void ModifyDoctorData(Room room[], char option, char choice);
	void ImportRoomFiles(Room RoomData[], char option);
	~Room();
};
