#include "EmployeeGUI.h"

void EmployeeGUI::cheackEmployee(LoginData userLoginData, vector<LoginData>& loginData, size_t index) {

	//All Employees data Stored in vector
	vector<Employee> employeesData = c.getEmployeesData();

	Employee currentEmploye = getEmployeeCurrentEmployee(employeesData, userLoginData);

	if (userLoginData.getIsFristLogin()) {
		system("cls");
		c.changeUserPassword(loginData, userLoginData, index);
		return;
	}

	if (currentEmploye.getEmployeePostion() == "manager") {
		bankDirectorOptions(employeesData);
	}
	else {
		g.Menu_employee();
	}
}

Employee EmployeeGUI::getEmployeeCurrentEmployee(vector<Employee>& employeesData, LoginData& userLoginData) {

	size_t employeeCount = employeesData.size();

	for (size_t t = 0; t < employeesData.size(); t++) {
		if (userLoginData.getID() == employeesData.at(t).getID()) {
			return employeesData.at(t);
		}
	}
}
void EmployeeGUI::bankDirectorOptions(vector<Employee>& employeesData) {
	system("cls");
	showBankDirectorOptions();
	int selected_option = c.checkSelectionRange(4);

	switch (selected_option)
	{
	case 1:
		system("cls");
		g.Menu_employee();
		break;
	case 2:
		system("cls");
		manageEmployees(employeesData);
		break;
	case 3:
		system("cls");
		return;
		break;
	case 4:
		exit(0);
		break;
	}
	bankDirectorOptions(employeesData);
}

void EmployeeGUI::showBankDirectorOptions() {
	cout << "Welcome to bank manger mangment system" << endl;
	cout << "1- Manage clients" << endl;
	cout << "2- Manage employee" << endl;
	cout << "3- Change user" << endl;
	cout << "4- Exit" << endl;
	cout << "Enter your choice: ";
}

void EmployeeGUI::manageEmployees(vector<Employee>& employeesData) {
	system("cls");
	showManageEmployee();
	int selected_option = c.checkSelectionRange(5);

	switch (selected_option)
	{
	case 1:
		system("cls");
		c.addNewEmployee(employeesData);
		break;
	case 2:
		searchFor.searchForEmployee(employeesData);
		break;
	case 3:
		searchFor.showAllEmployees(employeesData);
		return;
		break;
	case 4:
		break;
		break;
	case 5:
		exit(0);
		break;
	}
	manageEmployees(employeesData);
}

void EmployeeGUI::showManageEmployee() {
	cout << "Welcome" << endl;
	cout << "1- Add new Employee" << endl;
	cout << "2- Searsh for employee" << endl;
	cout << "3- Show all employees" << endl;
	cout << "4- Return to main menu" << endl;
	cout << "5- Exit" << endl;
	cout << "Enter your choice: ";
}
