#include"Doctor.h"
#include "Doctor.h"
Doctor::Doctor()
{
	DoctorRole = "NULL";
	DoctorRoomNo = 0;
	next = NULL;
	prev = NULL;
}
void Doctor::SetPersonData(string iid, string iname, string icnic, string igender, string ibloodgroup, string age)
{
	id = iid;
	name = iname;
	cnic = icnic;
	gender = igender;
	bloodgroup = ibloodgroup;
}
void Doctor::insertDoctor(Doctor** doctorData, string iid, string iname, string iage, string icnic, string igender, string ibloodgroup, int iroomno, string irole, char option)
{
	Doctor* temp = new Doctor;
	temp->id = iid;
	temp->name = iname;
	temp->age = iage;
	temp->cnic = icnic;
	temp->gender = igender;
	temp->DoctorRoomNo = iroomno;
	temp->bloodgroup = ibloodgroup;
	temp->DoctorRole = irole;
	Doctor* traverse = *doctorData;
	if (traverse == NULL)
	{
		temp->next = temp->prev = NULL;
		*doctorData = temp;
	}
	else
	{
		while (traverse->next != NULL)
		{
			traverse = traverse->next;
		}
		traverse->next = temp;
		temp->prev = traverse;
		temp->next = NULL;
	}

}

void Doctor::InputSingleDoctor(Doctor** doctorData, char option)
{

	Doctor* temp = new Doctor;
	string tempid;
	system("cls");
	cout << "\n\n_______________________________________________";
	cout << "\n\n             Entering Doctor Data";
	cout << "\n\n_______________________________________________\n";
	bool uni;
	int data = 0;
	do
	{
		uni = false;
		cin.ignore();
		cout << "\n\n  Enter ID Of Doctor  :  ";
		getline(cin, tempid);
		uni = DoctorIdUnique(*doctorData, tempid);
		if (uni == false)
		{
			temp->id = tempid;
		}
	} while (uni);
	cin.ignore();
	cout << "\n\n  Enter Name Of Doctor   :  ";
	getline(cin, temp->name);
	cin.ignore();
	cout << "\n\n  Enter Age Of Doctor   :  ";
	getline(cin, temp->age);
	cin.ignore();
	cout << "\n\n  Enter CNIC Of Doctor  :  ";
	getline(cin, temp->cnic);
	cin.ignore();
	cout << "\n\n  Enter Gender Of Doctor   :  ";
	getline(cin, temp->gender);
	cin.ignore();
	cout << "\n\n  Enter Blood Group Of Doctor   :  ";
	getline(cin, temp->bloodgroup);
	cin.ignore();
	cout << "\n\n  Enter Specification Of Doctor   :  ";
	getline(cin, temp->DoctorRole);
	Doctor* traverse = *doctorData;
	if (traverse == NULL)
	{
		temp->next = temp->prev = NULL;
		*doctorData = temp;
	}
	else
	{
		while (traverse->next != NULL)
		{
			traverse = traverse->next;
		}
		traverse->next = temp;
		temp->prev = traverse;
		temp->next = NULL;
	}
	temp->DoctorAdmit(*doctorData, data, option);

}

bool Doctor::DoctorIdUnique(Doctor* doctorData, string doctorDataid)
{
	bool unique = false;
	Doctor* temp = doctorData;
	bool matched = false;
	while (temp != NULL)
	{
		if (temp->id == doctorDataid)
		{
			cout << "\n\n_______________________________________________";
			cout << "\n\n\n\t*Error! Matched Doctor Id Found! *";
			cout << "\n\n_______________________________________________";
			matched = true;
			break;
		}
		temp = temp->next;
	}
	return matched;
}

void Doctor::SearchDoctor(Doctor** doctorData, char option, char choice)
{
	int data = 0;
	bool list = false;
	bool found = true;
	Doctor* temp = *doctorData;
	if (option == '1')
	{
		data = DoctorsInRoom_1;
	}
	else if (option == '2')
	{
		data = DoctorsInRoom_2;
	}
	else if (option == '3')
	{
		data = DoctorsInRoom_3;
	}
	cin.ignore();
	string doctorDataid;
	cout << "\n  Enter Doctor Id To Search Or  \"*\" To Display Doctors List :  ";
	getline(cin, doctorDataid);
	if (doctorDataid == "*")
	{
		list = true;
		temp->DisplayAllDoctors(*doctorData, option);
	}
	else if (list == false)
	{
		while (temp != NULL)
		{
			if (doctorDataid == temp->id)
			{
				found = false;
				system("CLS");
				temp->DisplayDoctorData(option);
				if (choice == '3')
				{
					cout << "\n\n_______________________________________________";
					cout << "\n\n\n\t*Modifying Doctor Record! *";
					cout << "\n\n_______________________________________________";
					cin.ignore();
					cout << "\n\n  Enter Role Of Doctor   :  ";
					getline(cin, temp->DoctorRole);
				}
				else if (choice == '4')
				{
					cout << "\n\n_______________________________________________";
					cout << "\n\n\n\t*Deleting Doctor Record! *";
					cout << "\n\n_______________________________________________";
					temp->DoctorDischarged(doctorData, doctorDataid, data, option);
				}
			}
			temp = temp->next;
		}

		if (found)
		{
			cout << "\n\n_______________________________________________";
			cout << "\n\n\n\t*Doctor Record Not Found! *";
			cout << "\n\n_______________________________________________";
		}
	}
}

void Doctor::ExportTotalDoctors(Doctor** doctorData)
{
	Doctor* temp = *doctorData;
	fstream ExportReservedBeds;
	ExportReservedBeds.open("Total Doctors In All Rooms.txt", ios::out | ios::trunc);
	ExportReservedBeds.close();
	ExportReservedBeds.open("Total Doctors In All Rooms.txt", ios::out | ios::app);
	cin.ignore();
	ExportReservedBeds << temp->DoctorsInRoom_1 << endl << temp->DoctorsInRoom_2 << endl << temp->DoctorsInRoom_3;
	ExportReservedBeds.close();
}
void Doctor::ImportTotalDoctors(Doctor** doctorData)
{
	Doctor* temp = *doctorData;
	fstream ImportReservedBeds;
	ImportReservedBeds.open("Total Doctors In All Rooms.txt", ios::in);
	ImportReservedBeds >> temp->DoctorsInRoom_1;
	ImportReservedBeds >> temp->DoctorsInRoom_2;
	ImportReservedBeds >> temp->DoctorsInRoom_3;
	ImportReservedBeds.close();
}
void Doctor::ImportDoctorsData(Doctor** doctorData, char option)
{
	fstream ImportDoctor;
	string iid, iname, icnic, igender, ibloodgroup, iage, irole;
	int iroomno;
	Doctor* temp = new Doctor;
	if (option == '1')
	{
		ImportDoctor.open("Doctors In Room 1.txt", ios::in);
		for (int i = 0; i < DoctorsInRoom_1; i++)
		{
			getline(ImportDoctor, iage);
			getline(ImportDoctor, iname);
			getline(ImportDoctor, iid);
			getline(ImportDoctor, icnic);
			getline(ImportDoctor, igender);
			getline(ImportDoctor, ibloodgroup);
			ImportDoctor >> iroomno;
			ImportDoctor.ignore();
			getline(ImportDoctor, irole);
			insertDoctor(doctorData, iid, iname, iage, icnic, igender, ibloodgroup, iroomno, irole, option);
		}
		ImportDoctor.close();
	}

	if (option == '2')
	{
		ImportDoctor.open("Doctors In Room 2.txt");
		for (int i = 0; i < DoctorsInRoom_2; i++)
		{
			getline(ImportDoctor, iage);
			getline(ImportDoctor, iname);
			getline(ImportDoctor, iid);
			getline(ImportDoctor, icnic);
			getline(ImportDoctor, igender);
			getline(ImportDoctor, ibloodgroup);
			ImportDoctor >> iroomno;
			ImportDoctor.ignore();
			getline(ImportDoctor, irole);
			insertDoctor(doctorData, iid, iname, iage, icnic, igender, ibloodgroup, iroomno, irole, option);
		}
		ImportDoctor.close();
	}

	if (option == '3')
	{
		ImportDoctor.open("Doctors In Room 3.txt");
		for (int i = 0; i < DoctorsInRoom_3; i++)
		{
			getline(ImportDoctor, iage);
			getline(ImportDoctor, iname);
			getline(ImportDoctor, iid);
			getline(ImportDoctor, icnic);
			getline(ImportDoctor, igender);
			getline(ImportDoctor, ibloodgroup);
			ImportDoctor >> iroomno;
			ImportDoctor.ignore();
			getline(ImportDoctor, irole);
			insertDoctor(doctorData, iid, iname, iage, icnic, igender, ibloodgroup, iroomno, irole, option);
		}
		ImportDoctor.close();
	}
}

void Doctor::ExportDoctorsData(Doctor* temp, int data, char option)
{
	Doctor* doctorData = temp;
	fstream ExportDoctor;
	if (option == '1')
	{
		ExportDoctor.open("Doctors In Room 1.txt", ios::out | ios::trunc);
		ExportDoctor.close();
		ExportDoctor.open("Doctors In Room 1.txt", ios::out | ios::app);
		data = DoctorsInRoom_1;
	}
	else if (option == '2')
	{
		ExportDoctor.open("Doctors In Room 2.txt", ios::out | ios::trunc);
		ExportDoctor.close();
		ExportDoctor.open("Doctors In Room 2.txt", ios::out | ios::app);
		data = DoctorsInRoom_2;
	}
	else if (option == '3')
	{
		ExportDoctor.open("Doctors In Room 3.txt", ios::out | ios::trunc);
		ExportDoctor.close();
		ExportDoctor.open("Doctors In Room 3.txt", ios::out | ios::app);
		data = DoctorsInRoom_3;
	}
	cin.ignore();
	while (doctorData != NULL)
	{
		ExportDoctor << doctorData->age << endl << doctorData->name << endl << doctorData->id << endl << doctorData->cnic << endl << doctorData->gender
			<< endl << doctorData->bloodgroup << endl << doctorData->DoctorRoomNo << endl << doctorData->DoctorRole << endl;
		doctorData = doctorData->next;
	}
	ExportDoctor.close();
}

void Doctor::DoctorAdmit(Doctor* doctorData, int data, char option)
{
	if (option == '1')
	{
		cout << "\n\n_______________________________________________";
		cout << "\n\n               Doctor Added ";
		cout << "\n\n_______________________________________________\n\n";
		DoctorsInRoom_1++;
		DoctorRoomNo = 1;
		doctorData->ExportDoctorsData(doctorData, DoctorsInRoom_1, option);
		doctorData->ExportTotalDoctors(&doctorData);
	}
	else if (option == '2')
	{
		cout << "\n\n_______________________________________________";
		cout << "\n\n               Doctor Added ";
		cout << "\n\n_______________________________________________\n\n";
		DoctorsInRoom_2++;
		DoctorRoomNo = 2;
		doctorData->ExportDoctorsData(doctorData, DoctorsInRoom_2, option);
		doctorData->ExportTotalDoctors(&doctorData);
	}
	else if (option == '3')
	{
		cout << "\n\n_______________________________________________";
		cout << "\n\n               Doctor Added ";
		cout << "\n\n_______________________________________________\n\n";
		DoctorsInRoom_3++;
		DoctorRoomNo = 3;
		doctorData->ExportDoctorsData(doctorData, DoctorsInRoom_3, option);
		doctorData->ExportTotalDoctors(&doctorData);
	}
}

void Doctor::DoctorDischarged(Doctor** doctorData, string patientID, int data, char option)
{
	Doctor* p = new Doctor;
	Doctor* q = new Doctor;
	Doctor* temp = *doctorData;
	p = temp;
	q = temp->next;
	bool notFound = true;
	if (p->id == patientID)
	{
		*doctorData = q;
		notFound = false;
		cout << "\n\n_______________________________________________";
		cout << "\n\n               Doctor Removed ";
		cout << "\n\n_______________________________________________\n\n";
	}
	else
	{
		while (q->id != patientID)
		{
			p = p->next;
			q = q->next;
		}
		if (q->next == NULL)
		{
			p->next = NULL;
			notFound = false;
			cout << "\n\n_______________________________________________";
			cout << "\n\n               Doctor Removed ";
			cout << "\n\n_______________________________________________\n\n";
		}
		else
		{
			p->next = q->next;
			q->next->prev = p;
			cout << "\n\n_______________________________________________";
			cout << "\n\n               Doctor Removed ";
			cout << "\n\n_______________________________________________\n\n";
			notFound = false;
		}
	}
	if (option == '1')
	{
		DoctorsInRoom_1--;
		temp->ExportDoctorsData(*doctorData, DoctorsInRoom_1, option);
	}
	else if (option == '2')
	{
		DoctorsInRoom_2--;
		temp->ExportDoctorsData(*doctorData, DoctorsInRoom_2, option);
	}
	else
	{
		DoctorsInRoom_3--;
		temp->ExportDoctorsData(*doctorData, DoctorsInRoom_3, option);
	}
	temp->ExportTotalDoctors(doctorData);
}

void Doctor::DisplayDoctorData(char option)
{
	cout << "\n\n\t_________________________________________________________________________";
	cout << "\n\n\t                          Displaying Doctor Data ";
	cout << "\n\n\t_________________________________________________________________________\n\n";
	cout << "\n\n\t  Name Of Doctor   :  " << name;
	cout << "\t\t  Id Of Doctor  :  " << id;
	cout << "\n\n\t  Cnic Of Doctor  :  " << cnic;
	cout << "\t\t  Gender Of Doctor   :  " << gender;
	cout << "\n\n\t  Blood Group Of Doctor   :  " << bloodgroup;
	cout << "\t\t  Room Number Of Doctor  :  " << DoctorRoomNo;
	cout << "\n\n\t  Specification Of Doctor  :  " << DoctorRole;
	cout << "\n\n\t-------------------------------------------------------------------------\n\n";
	cout << "\n\n\t_________________________________________________________________________";
	cout << "\n\n\t-------------------------------------------------------------------------\n\n";
}

void Doctor::DisplayAllDoctors(Doctor* doctorData, char option)
{
	Doctor* temp = doctorData;
	system("cls");
	int data = 0;
	cout << "\n\n\t_________________________________________________________________________________";
	cout << "\n\n\t                          Displaying List Of Doctors ";
	cout << "\n\n\t_________________________________________________________________________________";
	if (option == '1')
	{
		data = DoctorsInRoom_1;
	}
	else if (option == '2')
	{
		data = DoctorsInRoom_2;
	}
	else if (option == '3')
	{
		data = DoctorsInRoom_3;
	}
	while (temp != NULL)
	{
		temp->DisplayDoctorData(option);
		temp = temp->next;
	}
}
Doctor::~Doctor()
{
	delete prev;
	delete next;
}
int Doctor::DoctorsInRoom_1 = 0;
int Doctor::DoctorsInRoom_2 = 0;
int Doctor::DoctorsInRoom_3 = 0;
