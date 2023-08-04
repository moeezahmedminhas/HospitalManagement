#include "Patient.h"
Patient::Patient()
{
	patientbedno = 0;
	totalbeds = 30;
	patientroomno = 0;
	admit_date = ctime(&now);
	discharge_date = ctime(&now);
	next = NULL;
	prev = NULL;
}
void Patient::SetPersonData(string iid, string iname, string icnic, string igender, string ibloodgroup,string age)
{
	id = iid;
	name = iname;
	cnic = icnic;
	gender = igender;
	bloodgroup = ibloodgroup;
}
void Patient::insertPatient(Patient** patientData,string iid, string iname, string iage, string icnic, string igender, string ibloodgroup, int ipatientbedno, int ipatientroomno, string iTestResult,char option)
{
	Patient* temp = new Patient;
	temp->id = iid;
	temp->name = iname;
	temp->age = iage;
	temp->cnic = icnic;
	temp->gender = igender;
	temp->bloodgroup = ibloodgroup;
	temp->patientbedno = ipatientbedno;
	temp->patientroomno = ipatientroomno;
	if (option == '1' || option == '2')
	{
		temp->TestResult = iTestResult;
	}
	else if (option == '3')
	{
		temp->diseasename = iTestResult;
	}
	Patient* traverse = *patientData;
	if (traverse == NULL)
	{
		temp->next = temp->prev = NULL;
		*patientData = temp;
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

void Patient::InputSinglePatient(Patient** patientdata, char option)
{
	if (ReservedBedsRoom_1 >= totalbeds && option == '1')
	{
		cout << "\n\n  Corona Ward Is Full Patient Cannot Be Admitted";
	}
	else if (ReservedBedsRoom_2 >= totalbeds && option == '2')
	{
		cout << "\n\n  Corona Critical Ward Is Full Patient Cannot Be Admitted";
	}
	else if (ReservedBedsRoom_3 >= totalbeds && option == '3')
	{
		cout << "\n\n  General Ward Is Full Patient Cannot Be Admitted";
	}
	else
	{
		Patient* temp = new Patient;
		string tempid;
		system("cls");
		cout << "\n\n_______________________________________________";
		cout << "\n\n             Entering Patient Data";
		cout << "\n\n_______________________________________________\n";
		bool uni;
		int data = 0;
		do
		{
			uni = false;
			cin.ignore();
			cout << "\n\n  Enter ID Of Patient  :  ";
			getline(cin, tempid);
			uni = PatientIdUnique(*patientdata, tempid);
			if (uni == false)
			{
				temp->id = tempid;
			}
		} while (uni);
		cin.ignore();
		cout << "\n\n  Enter Name Of Patient   :  ";
		getline(cin, temp->name);
		cin.ignore();
		cout << "\n\n  Enter Age Of Patient   :  ";
		getline(cin, temp->age);
		cin.ignore();
		cout << "\n\n  Enter CNIC Of Patient  :  ";
		getline(cin, temp->cnic);
		cin.ignore();
		cout << "\n\n  Enter Gender Of Patient   :  ";
		getline(cin, temp->gender);
		cin.ignore();
		cout << "\n\n  Enter Blood Group Of Patient   :  ";
		getline(cin, temp->bloodgroup);
		admit_date = ctime(&now);
		if (option == '1')
		{
			temp->Corona::inputTest();
			temp->patientbedno = ReservedBedsRoom_1 + 1;
			temp->patientroomno = 1;
		}
		else if (option == '2')
		{
			temp->Corona::inputTest();
			temp->patientbedno = ReservedBedsRoom_2 + 1;
			temp->patientroomno = 2;
		}
		else if (option == '3')
		{
			temp->GeneralWard::InputDisease();
			temp->patientbedno = ReservedBedsRoom_3 + 1;
			temp->patientroomno = 3;
		}
		Patient* traverse = *patientdata;
		if (traverse == NULL)
		{
			temp->next = temp->prev = NULL;
			*patientdata = temp;
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
		temp->PatientAdmit(*patientdata, data, option);
	}

}

bool Patient::PatientIdUnique(Patient* patientData, string patientDataid)
{
	bool unique = false;
	Patient* temp = patientData;
	bool matched = false;
	while (temp != NULL)
	{
		if (temp->id == patientDataid)
		{
			cout << "\n\n_______________________________________________";
			cout << "\n\n\n\t*Error! Matched Patient Id Found! *";
			cout << "\n\n_______________________________________________";
			matched = true;
			break;
		}
		temp = temp->next;
	}
	return matched;
}

void Patient::SearchPatient(Patient** patientdata, char option, char choice)
{
	int data = 0;
	bool list = false;
	bool found = true;
	Patient* temp = *patientdata;
	if (option == '1')
	{
		data = ReservedBedsRoom_1;
	}
	else if (option == '2')
	{
		data = ReservedBedsRoom_2;
	}
	else if (option == '3')
	{
		data = ReservedBedsRoom_3;
	}
	cin.ignore();
	string patientDataid;
	cout << "\n  Enter Patient Id To Search Or  \"*\" To Display Patients List :  ";
	getline(cin, patientDataid);
	if (patientDataid == "*")
	{
		list = true;
		temp->DisplayAllPatients(*patientdata, option);
	}
	else if (list == false)
	{
		while (temp != NULL)
		{
			if (patientDataid == temp->id)
			{
				found = false;
				system("CLS");
				temp->DisplayPatientData(option);
				if (option == '1' && choice == '3' || option == '2' && choice == '3')
				{
					cout << "\n\n_______________________________________________";
					cout << "\n\n\n\t*Modifying Patient Record! *";
					cout << "\n\n_______________________________________________";
					temp->Corona::inputTest();
					if (temp->ReturnResult() == "-ve" || temp->ReturnResult() == "Negative")
					{
						temp->PatientDischarged(patientdata, patientDataid, data, option);
					}
				}
				else if (option == '3'&&choice=='3')
				{
					temp->GeneralWard::InputDisease();
				}
				else if (choice == '4')
				{
					cout << "\n\n_______________________________________________";
					cout << "\n\n\n\t*Deleting Patient Record! *";
					cout << "\n\n_______________________________________________";
					temp->PatientDischarged(patientdata, patientDataid, data, option);
				}
			}
			temp = temp->next;
		}

		if (found)
		{
			cout << "\n\n_______________________________________________";
			cout << "\n\n\n\t*Patient Record Not Found! *";
			cout << "\n\n_______________________________________________";
		}
	}
}

void Patient::ExportTotalReservedBeds(Patient **patientdata)
{
	Patient* temp = *patientdata;
	fstream ExportReservedBeds;
	ExportReservedBeds.open("Total Reserved Beds In All Rooms.txt", ios::out | ios::trunc);
	ExportReservedBeds.close();
	ExportReservedBeds.open("Total Reserved Beds In All Rooms.txt", ios::out | ios::app);
	cin.ignore();
	ExportReservedBeds << temp->ReservedBedsRoom_1 << endl << temp->ReservedBedsRoom_2 << endl << temp->ReservedBedsRoom_3;
	ExportReservedBeds.close();
}
void Patient::ImportTotalReservedBeds(Patient **patientdata)
{
	Patient* temp = *patientdata;
	fstream ImportReservedBeds;
	ImportReservedBeds.open("Total Reserved Beds In All Rooms.txt", ios::in);
	ImportReservedBeds >> temp->ReservedBedsRoom_1;
	ImportReservedBeds >> temp->ReservedBedsRoom_2;
	ImportReservedBeds >> temp->ReservedBedsRoom_3;
	ImportReservedBeds.close();
}
void Patient::ImportPatientsData(Patient** patientdata, char option)
{
	fstream ImportPatient;
	string iid, iname, icnic, igender, ibloodgroup,iage,iTestResult;
	int ipatientbedno,ipatientroomno;
	Patient* temp = new Patient;
	if (option == '1')
	{
		ImportPatient.open("Patients In Room 1.txt", ios::in);
		for (int i = 0; i < ReservedBedsRoom_1; i++)
		{
			getline(ImportPatient, iage);
			getline(ImportPatient, iname);
			getline(ImportPatient, iid);
			getline(ImportPatient, icnic);
			getline(ImportPatient, igender);
			getline(ImportPatient, ibloodgroup);
			ImportPatient >> ipatientbedno;
			ImportPatient >> ipatientroomno;
			ImportPatient.ignore();
			getline(ImportPatient, iTestResult);
			insertPatient(patientdata, iid, iname, iage, icnic, igender, ibloodgroup, ipatientbedno, ipatientroomno, iTestResult, option);
		}
		ImportPatient.close();
	}

	if (option == '2')
	{
		ImportPatient.open("Patients In Room 2.txt");
		for (int i = 0; i < ReservedBedsRoom_2; i++)
		{
			getline(ImportPatient, iage);
			getline(ImportPatient, iname);
			getline(ImportPatient, iid);
			getline(ImportPatient, icnic);
			getline(ImportPatient, igender);
			getline(ImportPatient, ibloodgroup);
			ImportPatient >> ipatientbedno;
			ImportPatient >> ipatientroomno;
			ImportPatient.ignore();
			getline(ImportPatient, iTestResult);
			insertPatient(patientdata, iid, iname, iage, icnic, igender, ibloodgroup, ipatientbedno, ipatientroomno, iTestResult, option);
		}
		ImportPatient.close();
	}

	if (option == '3')
	{
		ImportPatient.open("Patients In Room 3.txt");
		for (int i = 0; i < ReservedBedsRoom_3; i++)
		{
			getline(ImportPatient, iage);
			getline(ImportPatient, iname);
			getline(ImportPatient, iid);
			getline(ImportPatient, icnic);
			getline(ImportPatient, igender);
			getline(ImportPatient, ibloodgroup);
			ImportPatient >> ipatientbedno;
			ImportPatient >> ipatientroomno;
			ImportPatient.ignore();
			getline(ImportPatient, iTestResult);
			insertPatient(patientdata, iid, iname, iage, icnic, igender, ibloodgroup, ipatientbedno, ipatientroomno, iTestResult, option);
		}
		ImportPatient.close();
	}
}

void Patient::ExportPatientsData(Patient *temp, int data, char option)
{
	Patient* patientdata = temp;
	fstream ExportPatient;
	if (option == '1')
	{
		ExportPatient.open("Patients In Room 1.txt", ios::out | ios::trunc);
		ExportPatient.close();
		ExportPatient.open("Patients In Room 1.txt", ios::out | ios::app);
		data = ReservedBedsRoom_1;
	}
	else if ( option == '2')
	{
		ExportPatient.open("Patients In Room 2.txt", ios::out | ios::trunc);
		ExportPatient.close();
		ExportPatient.open("Patients In Room 2.txt", ios::out | ios::app);
		data = ReservedBedsRoom_2;
	}
	else if (option == '3')
	{
		ExportPatient.open("Patients In Room 3.txt", ios::out | ios::trunc);
		ExportPatient.close();
		ExportPatient.open("Patients In Room 3.txt", ios::out | ios::app);
		data = ReservedBedsRoom_3;
	}
	cin.ignore();
	while(patientdata!=NULL)
	{
		ExportPatient << patientdata->age << endl << patientdata->name << endl << patientdata->id << endl << patientdata->cnic << endl << patientdata->gender
			<< endl << patientdata->bloodgroup << endl << patientdata->patientbedno
			<< endl << patientdata->patientroomno << endl << patientdata->TestResult << endl;
		patientdata = patientdata->next;
	}
	ExportPatient.close();
}

void Patient::PatientAdmit(Patient *patientdata, int data, char option)
{
	if (option == '1')
	{
		cout << "\n\n_______________________________________________";
		cout << "\n\n               Patient Admitted ";
		cout << "\n\n_______________________________________________\n\n";
		ReservedBedsRoom_1++;
		patientdata->ExportPatientsData(patientdata, ReservedBedsRoom_1, option);
		patientdata->ExportTotalReservedBeds(&patientdata);
	}
	else if (option == '2')
	{
		cout << "\n\n_______________________________________________";
		cout << "\n\n               Patient Admitted ";
		cout << "\n\n_______________________________________________\n\n";
		ReservedBedsRoom_2++;
		patientdata->ExportPatientsData(patientdata, ReservedBedsRoom_2, option);
		patientdata->ExportTotalReservedBeds(&patientdata);
	}
	else if (option == '3')
	{
		cout << "\n\n_______________________________________________";
		cout << "\n\n               Patient Admitted ";
		cout << "\n\n_______________________________________________\n\n";
		ReservedBedsRoom_3++;
		patientdata->ExportPatientsData(patientdata, ReservedBedsRoom_3, option);
		patientdata->ExportTotalReservedBeds(&patientdata);
	}
}

void Patient::PatientDischarged(Patient** patientData, string patientID,int data, char option)
{
	Patient* p = new Patient;
	Patient* q = new Patient;
	Patient* temp = *patientData;
	p = temp;
	q = temp->next;
	bool notFound = true;
	if (p->id == patientID)
	{
		*patientData = q;
		notFound = false;
		cout << "\n\n_______________________________________________";
		cout << "\n\n               Patient Discharged ";
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
			cout << "\n\n               Patient Discharged ";
			cout << "\n\n_______________________________________________\n\n";
		}
		else
		{
			p->next = q->next;
			q->next->prev = p;
			cout << "\n\n_______________________________________________";
			cout << "\n\n               Patient Discharged ";
			cout << "\n\n_______________________________________________\n\n";
			notFound = false;
		}
	}
	if (option == '1')
	{
		ReservedBedsRoom_1--;
		temp->ExportPatientsData(*patientData, ReservedBedsRoom_1, option);
	}
	else if (option == '2')
	{
		ReservedBedsRoom_2--;
		temp->ExportPatientsData(*patientData, ReservedBedsRoom_2, option);
	}
	else
	{
		ReservedBedsRoom_3--;
		temp->ExportPatientsData(*patientData, ReservedBedsRoom_3, option);
	}
	temp->ExportTotalReservedBeds(patientData);
}

void Patient::DisplayPatientData(char option)
{

	if (option == '1' || option == '2')
	{
		cout << "\n\n\t_________________________________________________________________________";
		cout << "\n\n\t                          Displaying Patient Data ";
		cout << "\n\n\t_________________________________________________________________________\n\n";
		cout << "\n\n\t  Name Of Patient   :  " << name;
		cout << "\t\t  Id Of Patient  :  " << id;
		cout << "\n\n\t  Cnic Of Patient  :  " << cnic;
		cout << "\t\t  Gender Of Patient   :  " << gender;
		cout << "\n\n\t  Blood Group Of Patient   :  " << bloodgroup;
		cout << "\n\n\t  Admit Date Of Patient  :  " << admit_date << endl;
		cout << "\n\t-------------------------------------------------------------------------";
		cout << "\n\t_________________________________________________________________________";
		cout << "\n\n\t  Patient's Room Number  :  " << patientroomno;
		cout << "\n\n\t  Patient's Bed Number   :  " << patientbedno;
		Corona::displayTest();
	}
	else if (option == '3')
	{
		cout << "\n\n\t_________________________________________________________________________";
		cout << "\n\n\t                          Displaying Patient Data ";
		cout << "\n\n\t_________________________________________________________________________\n\n";
		cout << "\n\n\t  Name Of Patient   :  " << name;
		cout << "\t\t  Id Of Patient  :  " << id;
		cout << "\n\n\t  Cnic Of Patient  :  " << cnic;
		cout << "\t\t  Gender Of Patient   :  " << gender;
		cout << "\n\n\t  Blood Group Of Patient   :  " << bloodgroup;
		cout << "\n\n\t  Admit Date Of Patient  :  " << admit_date << endl;
		cout << "\n\t-------------------------------------------------------------------------";
		cout << "\n\t_________________________________________________________________________";
		cout << "\n\n\t  Patient's Room Number  :  " << patientroomno;
		cout << "\n\n\t  Patient's Bed Number   :  " << patientbedno;
		GeneralWard::DisplayDisease();
	}
	cout << "\n\n\t_________________________________________________________________________";
	cout << "\n\n\t-------------------------------------------------------------------------\n\n";
}

void Patient::DisplayAllPatients(Patient* patientdata, char option)
{
	Patient* temp = patientdata;
	system("cls");
	int data=0;
	cout << "\n\n\t_________________________________________________________________________________";
	cout << "\n\n\t                          Displaying List Of Patients ";
	cout << "\n\n\t_________________________________________________________________________________";
	if(option=='1')
	{
		data = ReservedBedsRoom_1;
	}
	else if (option == '2')
	{
		data = ReservedBedsRoom_2;
	}
	else if (option == '3')
	{
		data = ReservedBedsRoom_3;
	}
	while(temp!=NULL)
	{
		temp->DisplayPatientData(option);
		temp = temp->next;
	}
}
Patient::~Patient()
{
	delete next;
	delete prev;
	delete admit_date;
	delete discharge_date;
}
int Patient::ReservedBedsRoom_1 = 0;
int Patient::ReservedBedsRoom_2 = 0;
int Patient::ReservedBedsRoom_3 = 0;