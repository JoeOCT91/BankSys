#include "Department.h"


//add new department
//parssing departments
//assigin manager
//assigin group manager


void Department::addNewDepartment() {
	Department newDepartment;
	string departmentName;

	cin.clear();
	getline(cin, departmentName);


}


int Department::appendToDepartments(Department newDepartment)
{
	string fileName = "departments.txt";
	ofstream myfile(fileName, ios::app);
	if (myfile.is_open())
	{
		myfile << endl;
		myfile.close();
		return 0;
	}
	else
	{
		cout << "Unable to open file";
		return 1;
	}

	return 0;
}