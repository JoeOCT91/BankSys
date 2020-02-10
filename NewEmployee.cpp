#include "NewEmployee.h"


void NewEmployee::addNewEmployee() {
	string employeeFullName;
	string employeePostion;
	string employeeTittle;

	Employee newEmployee;

	employeeFullName = getEmployeeFullName();

}

string NewEmployee::getEmployeeFullName() {
	string employeeFullName;
	//cheack string not contain digits



	return employeeFullName;
}


void cheackStringNotContainADigit() {
	string employeeFullName;
	string ErrorMessage;

	cin.clear();
	getline(cin, employeeFullName);
	while (cin.fail() || employeeFullName.find_first_of("0123456789")) {
		cin.clear();
		getline(cin, employeeFullName);

	}
	//return string 
	// 

}

//set department
//set postion
//set start date
//set ID