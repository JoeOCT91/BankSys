#include "EmployeeGUI.h"

//wehave login object hold userloginID
//Need to cheak this loginId with employee loginsIDs


void EmployeeGUI::cheackEmployee(LoginData userLoginData) {

	vector<Employee> employeesData = c.getEmployeesData();
	int employeeDepartment = getEmployeeDepartment(employeesData, userLoginData);

	switch (employeeDepartment)
	{
	case 0:
		bankDirectorGUI(employeesData);
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;

	}

}
void EmployeeGUI::bankDirectorGUI(vector<Employee>& employeesData) {
	showBankDirectorOptions();
	int selected_option = c.checkSelectionRange(5);

	switch (selected_option)
	{
	case 1:
		g.Menu_employee();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		exit(0);
		break;
	}

	bankDirectorGUI(employeesData);
}


int EmployeeGUI::getEmployeeDepartment(vector<Employee>& employeesData, LoginData& userLoginData) {

	size_t employeeCount = employeesData.size();

	for (size_t t = 0; t < employeesData.size(); t++) {
		if (stol(userLoginData.getID()) == employeesData.at(t).getEmployeeId()) {
			return employeesData.at(t).getEmployeeDepartment();
		}
	}

}

void EmployeeGUI::showBankDirectorOptions() {
	cout << "Welcome" << endl;
	cout << "1- Manage clients" << endl;
	cout << "2- Manage employee" << endl;
	cout << "3- Change user" << endl;
	cout << "4- Exit" << endl;
	cout << "Enter your choice :";
}
void EmployeeGUI::HREmployeeOtions() {
	showHREmployeeOtions();
	int selected_option = c.checkSelectionRange(5);

	switch (selected_option)
	{
	case 1:
		g.Menu_employee();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		exit(0);
		break;
	}

	bankDirectorGUI(employeesData);


}
void EmployeeGUI::showHREmployeeOtions() {

	cout << "1- Add new employee";
	cout << "2- Show new employees requests";
	cout << "Your choice:  ";
}


//Department manger make request for new employee
//
