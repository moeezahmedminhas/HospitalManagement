#include "Room.h"
#include "Patient.h"
#include"Doctor.h"
#include"Nurse.h"
Room::Room()
{
	patientData = NULL;
	nurseData = NULL;
	doctorData = NULL;
}


void Room::InputPatientData(Room room[], char option)
{
	if (option == '1')
	{
		room[0].InputSinglePatient(&room[0].patientData, option);//Room_1
	}
	else if (option == '2')
	{
		room[0].InputSinglePatient(&room[1].patientData, option);//Room_1
	}
	else if (option == '3')
	{
		room[0].InputSinglePatient(&room[2].patientData, option);//Room_2
	}
}

void Room::ModifyPatientData(Room room[], char option, char choice)
{
	if (option == '1')
	{
		room[0].SearchPatient(&room[0].patientData, option, choice);//Room_0
	}
	else if (option == '2')
	{
		room[1].SearchPatient(&room[1].patientData, option, choice);//Room_1
	}
	else if (option == '3')
	{
		room[2].SearchPatient(&room[2].patientData, option, choice);//Room_2
	}
}


void Room::InputNurseData(Room room[], char option)
{
	if (option == '1')
	{
		room[0].InputSingleNurse(&room[0].nurseData, option);//Room_1
	}
	else if (option == '2')
	{
		room[1].InputSingleNurse(&room[1].nurseData, option);//Room_1
	}
	else if (option == '3')
	{
		room[2].InputSingleNurse(&room[2].nurseData, option);//Room_2
	}
}

void Room::ModifyNurseData(Room room[], char option, char choice)
{
	if (option == '1')
	{
		room[0].SearchNurse(&room[0].nurseData, option, choice);//Room_0
	}
	else if (option == '2')
	{
		room[1].SearchNurse(&room[1].nurseData, option, choice);//Room_1
	}
	else if (option == '3')
	{
		room[2].SearchNurse(&room[2].nurseData, option, choice);//Room_2
	}
}


void Room::InputDoctorData(Room room[], char option)
{
	if (option == '1')
	{
		room[0].InputSingleDoctor(&room[0].doctorData, option);//Room_1
	}
	else if (option == '2')
	{
		room[1].InputSingleDoctor(&room[1].doctorData, option);//Room_1
	}
	else if (option == '3')
	{
		room[2].InputSingleDoctor(&room[2].doctorData, option);//Room_2
	}
}

void Room::ModifyDoctorData(Room room[], char option, char choice)
{
	if (option == '1')
	{
		room[0].SearchDoctor(&room[0].doctorData, option, choice);//Room_0
	}
	else if (option == '2')
	{
		room[1].SearchDoctor(&room[1].doctorData, option, choice);//Room_1
	}
	else if (option == '3')
	{
		room[2].SearchDoctor(&room[2].doctorData, option, choice);//Room_2
	}
}
void Room::ImportRoomFiles(Room RoomData[],char option)
{
	doctorData->ImportTotalDoctors(&doctorData);
	nurseData->ImportTotalNurses(&nurseData);
	patientData->ImportTotalReservedBeds(&patientData);
	if (option == '1')
	{
		RoomData[0].patientData->ImportPatientsData(&RoomData[0].patientData, option);
		RoomData[0].nurseData->ImportNursesData(&RoomData[0].nurseData, option);
		RoomData[0].doctorData->ImportDoctorsData(&RoomData[0].doctorData, option);
	}
	else if (option == '2')
	{
		RoomData[1].patientData->ImportPatientsData(&RoomData[1].patientData, option);
		RoomData[1].nurseData->ImportNursesData(&RoomData[1].nurseData, option);
		RoomData[1].doctorData->ImportDoctorsData(&RoomData[1].doctorData, option);
	}
	else if (option == '3')
	{
		RoomData[2].patientData->ImportPatientsData(&RoomData[2].patientData, option);
		RoomData[2].nurseData->ImportNursesData(&RoomData[2].nurseData, option);
	}

}



Room::~Room() 
{
	delete patientData;
	delete nurseData;
	delete doctorData;
}