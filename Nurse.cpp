#include"Nurse.h"
#include "Nurse.h"
Nurse::Nurse()
{
	nurseRole = "NULL";
	nurseRoomNo = 0;
	next = NULL;
	prev = NULL;
}
void Nurse::SetPersonData(string iid, string iname, string icnic, string igender, string ibloodgroup, string age)
{
	id = iid;
	name = iname;
	cnic = icnic;
	gender = igender;
	bloodgroup = ibloodgroup;
}
void Nurse::insertNurse(Nurse** nurseData, string iid, string iname, string iage, string icnic, string igender, string ibloodgroup, int iroomno, string irole, char option)
{
	Nurse* temp = new Nurse;
	temp->id = iid;
	temp->name = iname;
	temp->age = iage;
	temp->cnic = icnic;
	temp->gender = igender;
	temp->nurseRoomNo = iroomno;
	temp->bloodgroup = ibloodgroup;
	temp->nurseRole = irole;
	Nurse* traverse = *nurseData;
	if (traverse == NULL)
	{
		temp->next = temp->prev = NULL;
		*nurseData = temp;
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

void Nurse::InputSingleNurse(Nurse** nurseData, char option)
{

	Nurse* temp = new Nurse;
	string tempid;
	system("cls");
	cout << "\n\n_______________________________________________";
	cout << "\n\n             Entering Nurse Data";
	cout << "\n\n_______________________________________________\n";
	bool uni;
	int data = 0;
	do
	{
		uni = false;
		cin.ignore();
		cout << "\n\n  Enter ID Of Nurse  :  ";
		getline(cin, tempid);
		uni = NurseIdUnique(*nurseData, tempid);
		if (uni == false)
		{
			temp->id = tempid;
		}
	} while (uni);
	cin.ignore();
	cout << "\n\n  Enter Name Of Nurse   :  ";
	getline(cin, temp->name);
	cin.ignore();
	cout << "\n\n  Enter Age Of Nurse   :  ";
	getline(cin, temp->age);
	cin.ignore();
	cout << "\n\n  Enter CNIC Of Nurse  :  ";
	getline(cin, temp->cnic);
	cin.ignore();
	cout << "\n\n  Enter Gender Of Nurse   :  ";
	getline(cin, temp->gender);
	cin.ignore();
	cout << "\n\n  Enter Blood Group Of Nurse   :  ";
	getline(cin, temp->bloodgroup);
	cin.ignore();
	cout << "\n\n  Enter Role Of Nurse   :  ";
	getline(cin, temp->nurseRole);
	Nurse* traverse = *nurseData;
	if (traverse == NULL)
	{
		temp->next = temp->prev = NULL;
		*nurseData = temp;
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
	temp->NurseAdmit(*nurseData, data, option);

}

bool Nurse::NurseIdUnique(Nurse* nurseData, string nurseDataid)
{
	bool unique = false;
	Nurse* temp = nurseData;
	bool matched = false;
	while (temp != NULL)
	{
		if (temp->id == nurseDataid)
		{
			cout << "\n\n_______________________________________________";
			cout << "\n\n\n\t*Error! Matched Nurse Id Found! *";
			cout << "\n\n_______________________________________________";
			matched = true;
			break;
		}
		temp = temp->next;
	}
	return matched;
}

void Nurse::SearchNurse(Nurse** nurseData, char option, char choice)
{
	int data = 0;
	bool list = false;
	bool found = true;
	Nurse* temp = *nurseData;
	if (option == '1')
	{
		data = NursesInRoom_1;
	}
	else if (option == '2')
	{
		data = NursesInRoom_2;
	}
	else if (option == '3')
	{
		data = NursesInRoom_3;
	}
	cin.ignore();
	string nurseDataid;
	cout << "\n  Enter Nurse Id To Search Or  \"*\" To Display Nurses List :  ";
	getline(cin, nurseDataid);
	if (nurseDataid == "*")
	{
		list = true;
		temp->DisplayAllNurses(*nurseData, option);
	}
	else if (list == false)
	{
		while (temp != NULL)
		{
			if (nurseDataid == temp->id)
			{
				found = false;
				system("CLS");
				temp->DisplayNurseData(option);
				if (choice == '3')
				{
					cout << "\n\n_______________________________________________";
					cout << "\n\n\n\t*Modifying Nurse Record! *";
					cout << "\n\n_______________________________________________";
					cin.ignore();
					cout << "\n\n  Enter Role Of Nurse   :  ";
					getline(cin, temp->nurseRole);
				}
				else if (choice == '4')
				{
					cout << "\n\n_______________________________________________";
					cout << "\n\n\n\t*Deleting Nurse Record! *";
					cout << "\n\n_______________________________________________";
					temp->NurseDischarged(nurseData, nurseDataid, data, option);
				}
			}
			temp = temp->next;
		}

		if (found)
		{
			cout << "\n\n_______________________________________________";
			cout << "\n\n\n\t*Nurse Record Not Found! *";
			cout << "\n\n_______________________________________________";
		}
	}
}

void Nurse::ExportTotalNurses(Nurse** nurseData)
{
	Nurse* temp = *nurseData;
	fstream ExportReservedBeds;
	ExportReservedBeds.open("Total Nurses In All Rooms.txt", ios::out | ios::trunc);
	ExportReservedBeds.close();
	ExportReservedBeds.open("Total Nurses In All Rooms.txt", ios::out | ios::app);
	cin.ignore();
	ExportReservedBeds << temp->NursesInRoom_1 << endl << temp->NursesInRoom_2 << endl << temp->NursesInRoom_3;
	ExportReservedBeds.close();
}
void Nurse::ImportTotalNurses(Nurse** nurseData)
{
	Nurse* temp = *nurseData;
	fstream ImportReservedBeds;
	ImportReservedBeds.open("Total Nurses In All Rooms.txt", ios::in);
	ImportReservedBeds >> temp->NursesInRoom_1;
	ImportReservedBeds >> temp->NursesInRoom_2;
	ImportReservedBeds >> temp->NursesInRoom_3;
	ImportReservedBeds.close();
}
void Nurse::ImportNursesData(Nurse** nurseData, char option)
{
	fstream ImportNurse;
	string iid, iname, icnic, igender, ibloodgroup, iage, irole;
	int iroomno;
	Nurse* temp = new Nurse;
	if (option == '1')
	{
		ImportNurse.open("Nurses In Room 1.txt", ios::in);
		for (int i = 0; i < NursesInRoom_1; i++)
		{
			getline(ImportNurse, iage);
			getline(ImportNurse, iname);
			getline(ImportNurse, iid);
			getline(ImportNurse, icnic);
			getline(ImportNurse, igender);
			getline(ImportNurse, ibloodgroup);
			ImportNurse >> iroomno;
			ImportNurse.ignore();
			getline(ImportNurse, irole);
			insertNurse(nurseData, iid, iname, iage, icnic, igender, ibloodgroup, iroomno, irole, option);
		}
		ImportNurse.close();
	}

	if (option == '2')
	{
		ImportNurse.open("Nurses In Room 2.txt");
		for (int i = 0; i < NursesInRoom_2; i++)
		{
			getline(ImportNurse, iage);
			getline(ImportNurse, iname);
			getline(ImportNurse, iid);
			getline(ImportNurse, icnic);
			getline(ImportNurse, igender);
			getline(ImportNurse, ibloodgroup);
			ImportNurse >> iroomno;
			ImportNurse.ignore();
			getline(ImportNurse, irole);
			insertNurse(nurseData, iid, iname, iage, icnic, igender, ibloodgroup, iroomno, irole, option);
		}
		ImportNurse.close();
	}

	if (option == '3')
	{
		ImportNurse.open("Nurses In Room 3.txt");
		for (int i = 0; i < NursesInRoom_3; i++)
		{
			getline(ImportNurse, iage);
			getline(ImportNurse, iname);
			getline(ImportNurse, iid);
			getline(ImportNurse, icnic);
			getline(ImportNurse, igender);
			getline(ImportNurse, ibloodgroup);
			ImportNurse >> iroomno;
			ImportNurse.ignore();
			getline(ImportNurse, irole);
			insertNurse(nurseData, iid, iname, iage, icnic, igender, ibloodgroup, iroomno, irole, option);
		}
		ImportNurse.close();
	}
}

void Nurse::ExportNursesData(Nurse* temp, int data, char option)
{
	Nurse* nurseData = temp;
	fstream ExportNurse;
	if (option == '1')
	{
		ExportNurse.open("Nurses In Room 1.txt", ios::out | ios::trunc);
		ExportNurse.close();
		ExportNurse.open("Nurses In Room 1.txt", ios::out | ios::app);
		data = NursesInRoom_1;
	}
	else if (option == '2')
	{
		ExportNurse.open("Nurses In Room 2.txt", ios::out | ios::trunc);
		ExportNurse.close();
		ExportNurse.open("Nurses In Room 2.txt", ios::out | ios::app);
		data = NursesInRoom_2;
	}
	else if (option == '3')
	{
		ExportNurse.open("Nurses In Room 3.txt", ios::out | ios::trunc);
		ExportNurse.close();
		ExportNurse.open("Nurses In Room 3.txt", ios::out | ios::app);
		data = NursesInRoom_3;
	}
	cin.ignore();
	while (nurseData != NULL)
	{
		ExportNurse << nurseData->age << endl << nurseData->name << endl << nurseData->id << endl << nurseData->cnic << endl << nurseData->gender
			<< endl << nurseData->bloodgroup << endl << nurseData->nurseRoomNo << endl << nurseData->nurseRole << endl;
		nurseData = nurseData->next;
	}
	ExportNurse.close();
}

void Nurse::NurseAdmit(Nurse* nurseData, int data, char option)
{
	if (option == '1')
	{
		cout << "\n\n_______________________________________________";
		cout << "\n\n               Nurse Addedd ";
		cout << "\n\n_______________________________________________\n\n";
		NursesInRoom_1++;
		nurseData->ExportNursesData(nurseData, NursesInRoom_1, option);
		nurseData->ExportTotalNurses(&nurseData);
	}
	else if (option == '2')
	{
		cout << "\n\n_______________________________________________";
		cout << "\n\n               Nurse Addedd ";
		cout << "\n\n_______________________________________________\n\n";
		NursesInRoom_2++;
		nurseData->ExportNursesData(nurseData, NursesInRoom_2, option);
		nurseData->ExportTotalNurses(&nurseData);
	}
	else if (option == '3')
	{
		cout << "\n\n_______________________________________________";
		cout << "\n\n               Nurse Addedd ";
		cout << "\n\n_______________________________________________\n\n";
		NursesInRoom_3++;
		nurseData->ExportNursesData(nurseData, NursesInRoom_3, option);
		nurseData->ExportTotalNurses(&nurseData);
	}
}

void Nurse::NurseDischarged(Nurse** nurseData, string patientID, int data, char option)
{
	Nurse* p = new Nurse;
	Nurse* q = new Nurse;
	Nurse* temp = *nurseData;
	p = temp;
	q = temp->next;
	bool notFound = true;
	if (p->id == patientID)
	{
		*nurseData = q;
		notFound = false;
		cout << "\n\n_______________________________________________";
		cout << "\n\n               Nurse Deleted ";
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
			cout << "\n\n               Nurse Deleted ";
			cout << "\n\n_______________________________________________\n\n";
		}
		else
		{
			p->next = q->next;
			q->next->prev = p;
			cout << "\n\n_______________________________________________";
			cout << "\n\n               Nurse Deleted ";
			cout << "\n\n_______________________________________________\n\n";
			notFound = false;
		}
	}
	if (option == '1')
	{
		NursesInRoom_1--;
		temp->ExportNursesData(*nurseData, NursesInRoom_1, option);
	}
	else if (option == '2')
	{
		NursesInRoom_2--;
		temp->ExportNursesData(*nurseData, NursesInRoom_2, option);
	}
	else
	{
		NursesInRoom_3--;
		temp->ExportNursesData(*nurseData, NursesInRoom_3, option);
	}
	temp->ExportTotalNurses(nurseData);
}

void Nurse::DisplayNurseData(char option)
{
	cout << "\n\n\t_________________________________________________________________________";
	cout << "\n\n\t                          Displaying Nurse Data ";
	cout << "\n\n\t_________________________________________________________________________\n\n";
	cout << "\n\n\t  Name Of Nurse   :  " << name;
	cout << "\t\t  Id Of Nurse  :  " << id;
	cout << "\n\n\t  Cnic Of Nurse  :  " << cnic;
	cout << "\t\t  Gender Of Nurse   :  " << gender;
	cout << "\n\n\t  Blood Group Of Nurse   :  " << bloodgroup;
	cout << "\t\t  Room Number Of Nurse  :  " << nurseRoomNo;
	cout << "\n\n\t  Role Of Nurse  :  " << nurseRole;
	cout << "\n\n\t-------------------------------------------------------------------------\n\n";
	cout << "\n\n\t_________________________________________________________________________";
	cout << "\n\n\t-------------------------------------------------------------------------\n\n";
}

void Nurse::DisplayAllNurses(Nurse* nurseData, char option)
{
	Nurse* temp = nurseData;
	system("cls");
	int data = 0;
	cout << "\n\n\t_________________________________________________________________________________";
	cout << "\n\n\t                          Displaying List Of Nurses ";
	cout << "\n\n\t_________________________________________________________________________________";
	if (option == '1')
	{
		data = NursesInRoom_1;
	}
	else if (option == '2')
	{
		data = NursesInRoom_2;
	}
	else if (option == '3')
	{
		data = NursesInRoom_3;
	}
	while (temp != NULL)
	{
		temp->DisplayNurseData(option);
		temp = temp->next;
	}
}
Nurse::~Nurse()
{
	delete prev;
	delete next;
}
int Nurse::NursesInRoom_1 = 0;
int Nurse::NursesInRoom_2 = 0;
int Nurse::NursesInRoom_3 = 0;