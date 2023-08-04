#include "QuarantineCenter.h"
#include"Room.h"
QuarantineCenter::QuarantineCenter()
{
	location = "Lahore";
	centerid = "1111";
	contactnumber = "04237484883";
}
void QuarantineCenter::inputcenterdata()
{
	cin.ignore();
	cout << "\n\n  Enter Location Of Center  :  ";
	getline(cin, location);
	cin.ignore();
	cout << "\n\n  Enter Center ID Number    :  ";
	getline(cin, centerid);
	cin.ignore();
	cout << "\n\n  Enter Help Line  Number   :  ";
	getline(cin, contactnumber);
}
void QuarantineCenter::exportcenterdata()
{
	fstream CenterData;
	CenterData.open("Center Data.txt", ios::trunc | ios::out);
	CenterData.close();
	CenterData.open("Center Data.txt", ios::out | ios::app);
	cin.ignore();
	CenterData << location << endl << centerid << endl << contactnumber << endl << adminpassword << endl << userpassword << endl;
	CenterData.close();
}
void QuarantineCenter::importcenterdata()
{
	fstream CenterData;
	CenterData.open("Center Data.txt", ios::in);
	while (!CenterData.eof())
	{
		getline(CenterData, location);
		getline(CenterData, centerid);
		getline(CenterData, contactnumber);
		getline(CenterData, adminpassword);
		getline(CenterData, userpassword);
	}
	CenterData.close();
}
bool QuarantineCenter::checkadminpass(string pass)
{
	if (pass == this->adminpassword)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool QuarantineCenter::checkuserpass(string pass)
{
	if (pass == this->userpassword)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void QuarantineCenter::setuserpass()
{
	string pass, confirmpass;
	bool wrong = true;
	do
	{
		cin.ignore();
		cout << "\n\n  Enter Your New User Password   :  ";
		getline(cin, pass);
		cin.ignore();
		cout << "\n\n  Please Confirm Your Password   :  ";
		getline(cin, confirmpass);
		if (pass == confirmpass)
		{
			userpassword = pass;
			wrong = false;
		}
		else
		{
			cout << "\n\n_______________________________________________";
			cout << "\n\n               Password Didn't Matched ";
			cout << "\n\n_______________________________________________\n\n";
		}
	} while (wrong);
}
void QuarantineCenter::setadminpass()
{
	string pass, confirmpass;
	bool wrong = true;
	do
	{
		cin.ignore();
		cout << "\n\n  Enter Your New Admin Password   :  ";
		getline(cin, pass);
		cin.ignore();
		cout << "\n\n  Please  Confirm Your Password   :  ";
		getline(cin, confirmpass);
		if (pass == confirmpass)
		{
			adminpassword = pass;
			wrong = false;
		}
		else
		{
			cout << "\n\n_______________________________________________";
			cout << "\n\n               Password Didn't Matched ";
			cout << "\n\n_______________________________________________\n\n";
		}
	} while (wrong);
}
void QuarantineCenter::CenterData()
{
	fstream CenterData;
	system("cls");
	CenterData.open("Center Data.txt", ios::in);
	if (!CenterData.is_open())
	{
		cout << "\n\n_______________________________________________";
		cout << "\n\n             Entering Center Data ";
		cout << "\n\n_______________________________________________\n\n";
		this->setadminpass();
		this->setuserpass();
		this->inputcenterdata();
		this->exportcenterdata();
	}
	else
	{
		this->importcenterdata();
	}
}
void QuarantineCenter::ImportAllFiles(char option)//Doctor indincates that this file is for doctor record and last integer indicates room number
{
	if (option == '1')
	{
		RoomData[0].ImportRoomFiles(RoomData,option);
	}
	else if (option == '2')
	{
		RoomData[1].ImportRoomFiles(RoomData,option);
	}
	else if (option == '3')
	{
		RoomData[2].ImportRoomFiles(RoomData,option);
	}
}
void QuarantineCenter::InputPatient(char option)
{
	if (option == '1')
	{
		RoomData[0].InputPatientData(RoomData, option);
	}
	else if (option == '2')
	{
		RoomData[1].InputPatientData(RoomData, option);
	}
	else if (option == '3')
	{
		RoomData[2].InputPatientData(RoomData, option);
	}
}


void QuarantineCenter::searchPatient(char option, char choice)
{
	if (option == '1')
	{
		RoomData[0].ModifyPatientData(RoomData, option, choice);
	}
	else if (option == '2')
	{
		RoomData[1].ModifyPatientData(RoomData, option, choice);
	}
	else if (option == '3')
	{
		RoomData[2].ModifyPatientData(RoomData, option, choice);
	}
}
void QuarantineCenter::InputDoctor(char option)
{
	if (option == '1')
	{
		RoomData[0].InputDoctorData(RoomData, option);
	}
	else if (option == '2')
	{
		RoomData[1].InputDoctorData(RoomData, option);
	}
	else if (option == '3')
	{
		RoomData[2].InputDoctorData(RoomData, option);
	}
}


void QuarantineCenter::searchDoctor(char option, char choice)
{
	if (option == '1')
	{
		RoomData[0].ModifyDoctorData(RoomData, option, choice);
	}
	else if (option == '2')
	{
		RoomData[1].ModifyDoctorData(RoomData, option, choice);
	}
	else if (option == '3')
	{
		RoomData[2].ModifyDoctorData(RoomData, option, choice);
	}
}

void QuarantineCenter::InputNurse(char option)
{
	if (option == '1')
	{
		RoomData[0].InputNurseData(RoomData, option);
	}
	else if (option == '2')
	{
		RoomData[1].InputNurseData(RoomData, option);
	}
	else if (option == '3')
	{
		RoomData[2].InputNurseData(RoomData, option);
	}
}


void QuarantineCenter::searchNurse(char option, char choice)
{
	if (option == '1')
	{
		RoomData[0].ModifyNurseData(RoomData, option, choice);
	}
	else if (option == '2')
	{
		RoomData[1].ModifyNurseData(RoomData, option, choice);
	}
	else if (option == '3')
	{
		RoomData[2].ModifyNurseData(RoomData, option, choice);
	}
}



void QuarantineCenter::displaycenterdata()
{
	cout << "\n\n  Location Of Center  :  " << location;
	cout << "\n\n  Center ID Number    :  " << centerid;
	cout << "\n\n  Help Line  Number   :  " << contactnumber;
	cout << "\n\n  Admin Pass  :  " << adminpassword;
	cout << "\n\n  User pass   :  " << userpassword;
}
string QuarantineCenter::adminpassword = "NULL";
string QuarantineCenter::location = "NULL";
string QuarantineCenter::centerid = "NULL";
string QuarantineCenter::contactnumber = "NULL";