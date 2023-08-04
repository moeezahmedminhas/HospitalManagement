#include "personType.h"
personType::personType()
{
	id = "Null";
	name = "Null";
	cnic = "Null";
	gender = "Null";
	bloodgroup = "Null";
}
void personType::SetPersonData(string iid, string iname, string icnic, string igender, string ibloodgroup, string age)
{
	id = iid;
	name = iname;
	cnic = icnic;
	gender = igender;
	bloodgroup = ibloodgroup;
}
