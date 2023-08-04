#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<fstream>
#include<ctime>
#include"QuarantineCenter.h"
using namespace std;
void main()
{
	QuarantineCenter* Object = new QuarantineCenter;
	char option, select, choice;
	string pass;
	bool wrong = true, adminverfy = false, userverify = false;
	Object->CenterData();
	Object->ImportAllFiles('1');
	Object->ImportAllFiles('2');
	Object->ImportAllFiles('3');
	do
	{
		system("cls");
		cout << "\n\n\n\t\t  Welcome To Quarantine Center Main Menu ";
		cout << "\n\n_________________________________________________________________________";
		cout << "\n\n\t\t1.  To Login as Admin";
		cout << "\n\n\t\t2.  To Login as  User ";
		cout << "\n\n__________________________________________________________________________\n\n\t\t";
		cin >> select;
		if (select == '1')
		{
			system("cls");
			do
			{
				wrong = false;
				cin.ignore();
				cout << "\n\n________________________________________________________________________________________";
				cout << "\n\n  Enter Your Password To Contiue As Administrator Or 'E' To Exit :  ";
				getline(cin, pass);
				if (pass == "E" || pass == "e")
				{
					wrong = false;
					break;
				}
				else if (Object->checkadminpass(pass))
				{
					wrong = false;
				}
				else
				{
					cout << "\n\n_______________________________________________";
					cout << "\n\n  Password Doesn't Matched Try Again..! ";
					cout << "\n\n_______________________________________________\n\n";
					wrong = true;
				}
			} while (wrong);
			if (Object->checkadminpass(pass))
			{
				do
				{
					wrong = false;
					system("cls");
					cout << "\n\n_________________________________________________________________________";
					cout << "\n\n\t\t1.  To  Access  Nurse's Database";
					cout << "\n\n\t\t2.  To  Access Docotr's Database";
					cout << "\n\n\t\t3.  To Edit Center General Info";
					cout << "\n\n\t\t4.  To  Change  Admin  Password";
					cout << "\n\n\t\t5.  To   Change  User  Password";
					cout << "\n\n\t\t6.  To   Exit To The Main  Menu";
					cout << "\n\n__________________________________________________________________________\n\n\t\t";
					cin >> choice;
					if (choice == '6')
					{
						pass = "Null";
						wrong = false;
						break;
					}
					else if (choice == '1')
					{
						do
						{
							system("CLS");
							cout << "\n\n_________________________________________________________________________";
							cout << "\n\n\t\t1.  For  Adding  A  Nurse Record";
							cout << "\n\n\t\t2.  For Searching A Nurse Record";
							cout << "\n\n\t\t3.  For Modifying A Nurse Record";
							cout << "\n\n\t\t4.  For Deleting  A Nurse Record";
							cout << "\n\n\t\t5.  To   Exit To The Main  Menu\n\n";
							cout << "\n\n__________________________________________________________________________\n\n\t\t";
							cin >> choice;
							if (choice == '5')
							{
								pass = "Null";
								wrong = false;
								break;
							}
							if (choice == '1')
							{
								system("CLS");
								cout << "\n\n_________________________________________________________________________";
								cout << "\n\n\t\t1.  For Corona Ward";
								cout << "\n\n\t\t2.  For Critical Corona";
								cout << "\n\n\t\t3.  For Generic Ward\n\n\t\t";
								cout << "\n\n__________________________________________________________________________\n\n\t\t";
								cin >> option;
								Object->InputNurse(option);
							}
							else if (choice == '2' || choice == '3' || choice == '4')
							{
								system("CLS");
								cout << "\n\n__________________________________________________________________________";
								cout << "\n\n\t\t1.  For Corona Ward";
								cout << "\n\n\t\t2.  For Critical Corona";
								cout << "\n\n\t\t3.  For Generic Ward\n\n\t\t";
								cout << "\n\n__________________________________________________________________________\n\n\t\t";
								cin >> option;
								Object->searchNurse(option, choice);
							}
							cout << "\n\n_________________________________________________________________________";
							cout << "\n\n\t\t1.  Press Y To Remain In Admin Data Base";
							cout << "\n\n\t\t2.  Press  E  To Return  To  Main  Menu ";
							cout << "\n\n__________________________________________________________________________\n\n\t\t";
							cin >> choice;
							if (choice == 'E' || choice == 'e')
							{
								break;
							}
						} while (choice == 'y' || choice == 'Y');
					}
					else if (choice == '2')
					{
						do
						{
							system("CLS");
							cout << "\n\n_________________________________________________________________________";
							cout << "\n\n\t\t1.  For  Adding  A  Doctor Record";
							cout << "\n\n\t\t2.  For Searching A Doctor Record";
							cout << "\n\n\t\t3.  For Modifying A Doctor Record";
							cout << "\n\n\t\t4.  For Deleting  A Doctor Record";
							cout << "\n\n\t\t5.  To   Exit To The Main  Menu\n\n";
							cout << "\n\n__________________________________________________________________________\n\n\t\t";
							cin >> choice;
							if (choice == '5')
							{
								pass = "Null";
								wrong = false;
								break;
							}
							if (choice == '1')
							{
								system("CLS");
								cout << "\n\n_________________________________________________________________________";
								cout << "\n\n\t\t1.  For Corona Ward";
								cout << "\n\n\t\t2.  For Critical Corona";
								cout << "\n\n\t\t3.  For Generic Ward\n\n\t\t";
								cout << "\n\n__________________________________________________________________________\n\n\t\t";
								cin >> option;
								Object->InputDoctor(option);
							}
							else if (choice == '2' || choice == '3' || choice == '4')
							{
								system("CLS");
								cout << "\n\n__________________________________________________________________________";
								cout << "\n\n\t\t1.  For Corona Ward";
								cout << "\n\n\t\t2.  For Critical Corona";
								cout << "\n\n\t\t3.  For Generic Ward\n\n\t\t";
								cout << "\n\n__________________________________________________________________________\n\n\t\t";
								cin >> option;
								Object->searchDoctor(option, choice);
							}
							cout << "\n\n_________________________________________________________________________";
							cout << "\n\n\t\t1.  Press Y To Remain In Admin Data Base";
							cout << "\n\n\t\t2.  Press  E  To Return  To  Main  Menu ";
							cout << "\n\n__________________________________________________________________________\n\n\t\t";
							cin >> choice;
							if (choice == 'E' || choice == 'e')
							{
								break;
							}
						} while (choice == 'y' || choice == 'Y');
					}
					else if (choice == '3')
					{
						system("cls");
						cout << "\n\n_________________________________________________________________________";
						Object->inputcenterdata();
						Object->exportcenterdata();
					}
					else if (choice == '4')
					{
						system("cls");
						cout << "\n\n_________________________________________________________________________";
						Object->setadminpass();
						Object->exportcenterdata();
					}
					else if (choice == '5')
					{
						system("cls");
						cout << "\n\n_________________________________________________________________________";
						Object->setuserpass();
						Object->exportcenterdata();
					}
					cin.ignore();
					cout << "\n\n_________________________________________________________________________";
					cout << "\n\n\n  Press Y To Return To Admin Menu 'E' to Exit :  ";
					cin >> choice;
					if (choice == 'E' || choice == 'e')
					{
						wrong = false;
						break;
					}
				} while (choice == 'y' || choice == 'Y' || wrong == true);
			}

		}
		if (select == '2')
		{
			system("cls");
			do
			{
				wrong = false;
				cin.ignore();
				cout << "\n\n________________________________________________________________________________________";
				cout << "\n\n  Enter Your Password To Contiue As User Or 'E' To Exit :  ";
				getline(cin, pass);
				if (pass == "E" || pass == "e")
				{
					pass = "Null";
					wrong = false;
					break;
				}
				else if (Object->checkuserpass(pass))
				{
					wrong = false;
				}
				else
				{
					cout << "\n\n_______________________________________________";
					cout << "\n\n  Password Doesn't Matched Try Again..! ";
					cout << "\n\n_______________________________________________\n\n";
					wrong = true;
				}
			} while (wrong);
			if (Object->checkuserpass(pass))
			{
				do
				{
					system("CLS");
					cout << "\n\n_________________________________________________________________________";
					cout << "\n\n\t\t1.  For Admitting A Patient Record";
					cout << "\n\n\t\t2.  For Searching A Patient Record";
					cout << "\n\n\t\t3.  For Modifying A Patient Record";
					cout << "\n\n\t\t4.  For Deleting  A Patient Record";
					cout << "\n\n\t\t5.  To   Exit To The Main  Menu\n\n";
					cout << "\n\n__________________________________________________________________________\n\n\t\t";
					cin >> choice;
					if (choice == '5')
					{
						pass = "Null";
						wrong = false;
						break;
					}
					if (choice == '1')
					{
						system("CLS");
						cout << "\n\n_________________________________________________________________________";
						cout << "\n\n\t\t1.  For Corona Patient";
						cout << "\n\n\t\t2.  For Critical Corona";
						cout << "\n\n\t\t3.  For Generic Patient\n\n\t\t";
						cout << "\n\n__________________________________________________________________________\n\n\t\t";
						cin >> option;
						Object->InputPatient(option);
					}
					else if (choice == '2' || choice == '3' || choice == '4')
					{
						system("CLS");
						cout << "\n\n__________________________________________________________________________";
						cout << "\n\n\t\t1.  For Corona Patient";
						cout << "\n\n\t\t2.  For Critical Corona";
						cout << "\n\n\t\t3.  For Generic Patient\n\n\t\t";
						cout << "\n\n__________________________________________________________________________\n\n\t\t";
						cin >> option;
						Object->searchPatient(option, choice);
					}
					cout << "\n\n_________________________________________________________________________";
					cout << "\n\n\t\t1.  Press Y To Remain In User Data Base";
					cout << "\n\n\t\t2.  Press  E  To Return  To  Main  Menu ";
					cout << "\n\n__________________________________________________________________________\n\n\t\t";
					cin >> choice;
					if (choice == 'E' || choice == 'e')
					{
						break;
					}
				} while (choice == 'y' || choice == 'Y');
			}
		}
		else
		{
			cout << "\n\n_______________________________________________";
			cout << "\n\n               Invalid Selection ";
			cout << "\n\n_______________________________________________\n\n";
		}
		cout << "\n\n  Press Y To Return To Main Login Menu 'E' to Exit :  ";
		cin >> select;
		if (select == 'E' || select == 'e')
		{
			break;
		}
	} while (select == 'y' || select == 'Y');
	delete Object;
}