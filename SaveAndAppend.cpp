#include "SaveAndAppend.h"

void SaveAndAppend::saveDataToEmployees(vector<Employee> employeesData) {

	ofstream myfile(EMPLOYEEFILE);
	string lineOfData;

	if (myfile.is_open())
	{
		for (int i = 0; i < employeesData.size(); i++)
		{
			lineOfData = employeesData.at(i).getID() + SEP;
			lineOfData += employeesData.at(i).getEmployeeName() + SEP;
			lineOfData += employeesData.at(i).getEmployeePostion() + SEP;
			lineOfData += employeesData.at(i).getEmployeeSalary() + SEP;
			lineOfData += employeesData.at(i).getEmployeeAge() + SEP;
			lineOfData += bool_to_string(employeesData.at(i).getIsActive());

			myfile << lineOfData << endl;
		}
		myfile.close();
	}
}

int SaveAndAppend::append2employee(Employee employee){

	string lineOfData;
	ofstream myfile(EMPLOYEEFILE, ios::app);
	if (myfile.is_open())
	{
		lineOfData = employee.getID() + SEP;
		lineOfData += employee.getEmployeeName() + SEP;
		lineOfData += employee.getEmployeePostion() + SEP;
		lineOfData += employee.getEmployeeSalary() + SEP;
		lineOfData += employee.getEmployeeAge() + SEP;
		lineOfData += bool_to_string(employee.getIsActive());

		myfile << lineOfData << endl;

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


bool SaveAndAppend::string_to_bool(string s) {
	bool r = false;
	if (s == "true") {
		r = true;
	}
	else if (s == "false") {
		r = false;
	}
	return r;
}

string SaveAndAppend::bool_to_string(bool b) {
	string r = "";
	if (b) {
		r = "true";
	}
	else if (!b) {
		r = "false";
	}
	return r;
}