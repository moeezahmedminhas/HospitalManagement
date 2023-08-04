#include "GeneralWard.h"

void GeneralWard::InputDisease()
{
	cout << "\n\n  Enter The Disease Name / Symptoms  :  ";
	cin >> diseasename;
}

void GeneralWard::DisplayDisease()
{
	cout << "\n\n\t  Disease And Symptoms  :  " << diseasename;
}

GeneralWard::GeneralWard()
{
	diseasename = "NULL";
}
