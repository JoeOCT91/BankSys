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
		employeeOtions();
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
		employeeOtions();
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
	cout << "2- Manage employees" << endl;
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
		return;
		break;
	case 5:
		exit(0);
		break;
	}
	manageEmployees(employeesData);
}

void EmployeeGUI::showManageEmployee() {
	cout << "Mange bank employees" << endl;
	cout << "1- Add new Employee" << endl;
	cout << "2- Searsh for employee" << endl;
	cout << "3- Show all employees" << endl;
	cout << "4- Return to main menu" << endl;
	cout << "5- Exit" << endl;
	cout << "Enter your choice: ";
}

void EmployeeGUI::employeeOtions()
{
	system("cls");
	//All clients data stored in vector 
	vector<Client> clientsData = c.get_clients_data();

	showEmployeeOptions();
	int selected_option = c.wait_user_input();

	system("cls");

	switch (selected_option)
	{
	case 1:
		c.addNewClient();
		break;
	case 2:
		searchFor.searchForClient(clientsData);
		break;
	case 3:
		searchFor.showAllClients(clientsData);
		break;
	case 4:
		return;
		break;
	case 5:
		exit(0);
		break;
	}

	employeeOtions();
}
void EmployeeGUI::showEmployeeOptions() {
	cout << "Manage bank clients" << endl;
	cout << "1- Add new client" << endl;
	cout << "2- Searsh for client" << endl;
	cout << "3- Show all clients" << endl;
	cout << "4- change user" << endl;
	cout << "5- Exit" << endl;
	cout << "Enter your choice: ";
}
