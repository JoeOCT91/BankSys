#pragma once
#include "SearchFor.h"
using namespace std;

// Need to Fix change if to while () .... checkSelectionRange
void SearchFor::showSearchOptions() {
	cout << "Search by" << endl;
	cout << "1- username" << endl;
	cout << "2- client name" << endl;
	cout << "3- account ID" << endl;
	cout << "Enter your choice :";
}

void SearchFor::searchForClient(vector<Client>& clientsData) {

	system("cls");

	showSearchOptions();

	int selected_option = c.checkSelectionRange(3);

	switch (selected_option)
	{
	case 1:
		system("cls");
		searchByUsername(clientsData);
		break;
	default:
	case 2:
		system("cls");
		searchByClientname(clientsData);

		break;
	case 3:
		system("cls");
		searchByClientID(clientsData);
		break;
	}
}

void SearchFor::searchByUsername(vector<Client>& clientsData) {
	string searshFor;
	cout << "Enter the client username you want to search for: ";
	cin.clear();
	getline(cin, searshFor);
	cout << searshFor;

	for (int i = 0; i < clientsData.size(); i++) {
		if (clientsData.at(i).getLoginuser() == searshFor) {
			Client currentClient = clientsData.at(i);
			foundOptions(clientsData, currentClient, i);
			return;
		}
	}
	notFound(clientsData);

}

void SearchFor::foundOptions(vector<Client>& clientsData, Client currentClient, int clientIndex) {
	if (!clientsData.at(clientIndex).getIsActive()){
		enableUser(clientsData, clientIndex);
	}
	else {
		system("cls");
		c.printClientInfo(clientsData.at(clientIndex));
		cout << "\n1- Edit client information" << endl;
		cout << "2- Make deposite" << endl;
		cout << "3- Make withdrawal" << endl;
		cout << "4- Make transfer" << endl;
		cout << "5- Main menu" << endl;
		cout << "6- Exit" << endl;
		cout << "Choose your action: ";

		int selected_option = c.checkSelectionRange(6);
		switch (selected_option) {
		case 1:
			editClientInformation(clientsData, clientIndex);
			break;
		case 2:
			system("cls");
			c.Deposite(clientsData, currentClient, clientIndex);
			break;
		case 3:
			c.Withdrawal(clientsData, currentClient, clientIndex);
			system("cls");
			break;
		case 4:
			c.transferTo(clientsData, currentClient, clientIndex);
			system("cls");
			break;
		case 5:
			system("cls");
			return;
			break;
		case 6:
			exit(0);
			break;
		}
	}
}

void SearchFor::editClientInformation(vector<Client>& clientsData, size_t clientIndex) {
	cout << "1- Edit client name" << endl;
	cout << "2- Reset password" << endl;
	cout << "3- Disable client" << endl;
	cout << "4 -Return to main menu" << endl;
	cout << "5- exit" << endl;
	cout << "Your choice: ";

	int selected_option = c.checkSelectionRange(4);
	switch (selected_option)
	{
	case 1:
		c.editClientName(clientsData, clientIndex);
		break;
	case 2:
		c.resetPassword(clientsData.at(clientIndex).getID());
		break;
	case 3:
		disableUser(clientsData, clientIndex);
	case 4:
		return;
		break;
	case 5:
		exit(0);
		break;
	}
}

void SearchFor::notFound(vector<Client>& clientsData) {
	cout << "Your entry not found  " << endl;
	cout << "1- Try Again" << endl;
	cout << "2- Return to main menu" << endl;
	cout << "3- Exit" << endl;
	cout << "Choose your action :";

	cin.clear();
	int selected_option = c.checkSelectionRange(3);

	switch (selected_option) {
	case 1:
		searchForClient(clientsData);
		break;
	case 2:
		system("cls");
		return;
		break;
	case 3:
		exit(0);
		break;
	}
}

void SearchFor::searchByClientname(vector<Client> & clientsData) {
	string searchFor;
	cout << "Enter the client username you want to search for: ";
	cin.clear();
	getline(cin, searchFor);
	vector<int> foundClientsIndex;
	for(int i = 0; i < clientsData.size(); i++) {
		string s = clientsData.at(i).getClientFullName();
		size_t found = s.find(searchFor);

		if (found != string::npos) {
			foundClientsIndex.push_back(i);
		}
	}
		
	if (foundClientsIndex.empty()) {
		notFound(clientsData);
	}
	searchByClientnameResult(clientsData, foundClientsIndex);
}
 
void SearchFor::searchByClientnameResult(vector<Client>& clientsData, vector<int>& resultClientsIndex) {

	for (int n = 0; n < resultClientsIndex.size(); n++) {
		cout << n + 1 << "- " << clientsData.at(resultClientsIndex[n]).getClientFullName() << endl;
		cout << "	Account ID: " << clientsData.at(resultClientsIndex[n]).getID() << endl << endl;
	}

	cout << "Choose from above: ";
	int selected_option = c.checkSelectionRange(resultClientsIndex.size());
	Client currentClient = clientsData.at(resultClientsIndex[selected_option-1]);
	foundOptions(clientsData, currentClient, resultClientsIndex[selected_option-1]);

}

void SearchFor::searchByClientID(vector<Client>& clientsData) {
	long long clientID;
	
	cout << "Enter client ID you want to search for: ";

	clientID = c.wait_user_input("INVALID INPUT, Try again\nEnter client ID you want to search for: ");
	if (clientID < 0 || clientID > 99999999) {
		cout << "INVALID INPUT, Try again\n";
		searchByClientID(clientsData);
	}
	for (int i = 0; i < clientsData.size(); i++) {
		if (clientID == stoll(clientsData.at(i).getID())) {
			Client currentClient = clientsData.at(i);
			foundOptions(clientsData, currentClient, i);
			return;
		}
	}
	cout << "INVALID INPUT, This ID not exist, Try again\n";
	searchByClientID(clientsData);
}

void SearchFor::showAllClients(vector<Client>& clientsData) {
	cout << "All Clients :\n";
	cout << c.stringAddPadding("Num", 5);
	cout << c.stringAddPadding("ID", 10);
	cout << c.stringAddPadding("Name", 30);
	cout << c.stringAddPadding("Blance", 15) << endl;

	
	for (int i = 0; i < clientsData.size(); i++) {
		cout << c.stringAddPadding(to_string(i + 1), 5);
		cout << c.stringAddPadding(clientsData.at(i).getID(), 10);
		cout << c.stringAddPadding(clientsData.at(i).getClientFullName(), 30);
		cout << c.stringAddPadding(clientsData.at(i).getClientBlance(), 15) << endl;
	}
	cout << "Choose from above: ";
	int selected_option = c.checkSelectionRange(clientsData.size());
	int index = selected_option - 1;
	Client currentClient = clientsData.at(index);
	foundOptions(clientsData, currentClient, index);

}

void SearchFor::showSearchForEmployee() {
	cout << "Search by" << endl;
	cout << "1- username" << endl;
	cout << "2- Employee name" << endl;
	cout << "3- Employee ID" << endl;
	cout << "4- Return" << endl;
	cout << "5- Exit" << endl;
	cout << "Enter your choice: ";
}

void SearchFor::searchForEmployee(vector<Employee>& employeesData) {

	system("cls");

	showSearchForEmployee();

	int selected_option = c.checkSelectionRange(5);

	switch (selected_option){
	case 1:
		system("cls");
		//searchByEmployeeUsername(employeesData);
		break;
	default:
	case 2:
		system("cls");
		//searchByEmployeename(clientsData);
		break;
	case 3:
		system("cls");
		searchByEmployeeID(employeesData);
		break;
	case 4:
		return;
		break;
	
	case 5:
		exit(0);
		break;
	}
}

void SearchFor::searchByEmployeeID(vector<Employee>& employeesData) {
	int employeeId;

	cout << "Enter employee ID you want to search for: ";

	employeeId = c.wait_user_input("INVALID INPUT, Try again\nEnter employee ID you want to search for: ");
	if (employeeId < 0 || employeeId > 99999999) {
		cout << "INVALID INPUT, Try again\n";
		searchByEmployeeID(employeesData);
	}
	for (int i = 0; i < employeesData.size(); i++) {
		if (to_string(employeeId) == employeesData.at(i).getID()) {
			Employee currentEmployee = employeesData.at(i);
			employeeFoundOptions(employeesData, i);
			return;
		}
	}
	cout << "INVALID INPUT, This ID not exist, Try again\n";
	searchByEmployeeID(employeesData);
}

void SearchFor::employeeFoundOptions(vector<Employee>& employeesData, size_t index) {
		system("cls");

		if (!employeesData.at(index).getIsActive()) {
			c.accountReactive();
			enableUser(employeesData, index);
		}
		else {
			c.printEmployeeInfo(employeesData.at(index));
			cout << "1- Edit employee information" << endl;
			cout << "2- Main menu" << endl;
			cout << "3- Exit" << endl;
			cout << "Choose your action: ";

			cin.clear();
			int selected_option = c.checkSelectionRange(3);

			switch (selected_option) {
			case 1:
				system("cls");
				editEmployeeInformation(employeesData, index);
				break;
			case 2:
				system("cls");
				return;
				break;
			case 3:
				exit(0);
				break;
			}
		}
}

void SearchFor::employeeNotFound(vector<Employee>& employeesData) {
	cout << "Your entry not found  " << endl;
	cout << "1- Try Again" << endl;
	cout << "2- Return to main menu" << endl;
	cout << "3- Exit" << endl;
	cout << "Choose your action :";

	cin.clear();
	int selected_option = c.checkSelectionRange(3);

	switch (selected_option) {
	case 1:
		searchForEmployee(employeesData);
		break;
	case 2:
		system("cls");
		return;
		break;
	case 3:
		exit(0);
		break;
	}
}

void SearchFor::showAllEmployees(vector<Employee>& employeesData) {
	system("cls");
	cout << c.stringAddPadding("ID", 6);
	cout << c.stringAddPadding("Name", 35);
	cout << c.stringAddPadding("Postion", 15);
	cout << c.stringAddPadding("Salary", 8);
	cout << c.stringAddPadding("age", 6);
	cout << c.stringAddPadding("Employee status", 16) << endl;
	

	for (int i = 0; i < employeesData.size(); i++) {
		cout << c.stringAddPadding(employeesData.at(i).getID(), 6);
		cout << c.stringAddPadding(employeesData.at(i).getEmployeeName(), 35);
		cout << c.stringAddPadding(employeesData.at(i).getEmployeePostion(), 15);
		cout << c.stringAddPadding(employeesData.at(i).getEmployeeSalary(), 8);
		cout << c.stringAddPadding(employeesData.at(i).getEmployeeAge(), 6);
		cout << c.stringAddPadding(c.bool_to_string(employeesData.at(i).getIsActive()), 16) << endl;

	}
	cout << "Choose from above: ";
	size_t selected_option = c.checkSelectionRange(employeesData.size());
	size_t index = selected_option - 1;
	Employee currentEmployee = employeesData.at(index);
	employeeFoundOptions(employeesData, index);

}


void SearchFor::editEmployeeInformation(vector<Employee>& employeesData, size_t index) {
	system("cls");
	c.printEmployeeInfo(employeesData.at(index));

	cout << "1- Edit name" << endl;
	cout << "2- Edit postion" << endl;
	cout << "3- Edit salary" << endl;
	cout << "4- Reset password" << endl;
	cout << "5- Terminate" << endl;
	cout << "6- Return to main Menu" << endl;
	cout << "7- Main menu" << endl;
	cout << "Your choice: ";

	int selected_option = c.checkSelectionRange(7);
	switch (selected_option)
	{
	case 1:
		editEmployeeName(employeesData, index);
		break;
	case 2:
		editEmployeePostion(employeesData, index);
		break;
	case 3:
		editEmployeeSalary(employeesData, index);
		break;
	case 4:
		c.resetPassword(employeesData.at(index).getID());
		break;
	case 5:
		disableUser(employeesData, index);
		return;
		break;
	case 6:
		return;
		break;
	case 7:
		exit(0);
		break;
	}
	editEmployeeInformation(employeesData, index);
}

void SearchFor::editEmployeeName(vector<Employee>& employeesData, size_t index) {
	string s = c.getFullName();
	system("cls");
	employeesData.at(index).printEmployeeInf();
	if (c.areYouSure()) {
		employeesData.at(index).setEmployeeName(s);
		saveAndAppend.saveDataToEmployees(employeesData);
	}
}

void SearchFor::editEmployeePostion(vector<Employee>& employeesData, size_t index) {
	string  message = "Please enter employee new postion: ";
	string s = c.getString(message);
	system("cls");
	employeesData.at(index).printEmployeeInf();
	if (c.areYouSure()) {
		employeesData.at(index).setEmployeePostion(s);
		saveAndAppend.saveDataToEmployees(employeesData);
		
	}
}

void SearchFor::editEmployeeSalary(vector<Employee>& employeesData, size_t index) {
	system("cls");
	string  message = "INVALID INPUT\nenter employee new salary: ";
	cout << "Enter employee new salary: ";
	int salary = c.wait_user_input(message);
	system("cls");
	Employee temp = employeesData.at(index);
	temp.setEmployeeSalary(salary);
	c.printEmployeeInfo(temp);
	if (c.areYouSure()) {
		employeesData.at(index).setEmployeeSalary(salary);
		saveAndAppend.saveDataToEmployees(employeesData);
	}
}

template <typename T>
void SearchFor::disableUser(vector<T>& data, size_t index) {

	if (c.areYouSure()) {
		vector<LoginData> loginData = c.get_login_creditentials();
		for (size_t i = 0; i < loginData.size(); i++) {
			cout << data.at(index).getID() << endl;
			if (loginData.at(i).getID() == data.at(index).getID()) {
				loginData.at(i).setIsActive(false);
				saveAndAppend.saveDataToUsers(loginData);
				disableProcesses(data, index);

				return;
			}
		}
	}
}

void SearchFor::disableProcesses(vector<Employee>& employeesData, size_t index) {
	cout << "we are hereeeeee" << endl;

	employeesData.at(index).setEmployeeSalary(0);
	employeesData.at(index).setIsActive(false);

	saveAndAppend.saveDataToEmployees(employeesData);
	return;
}
void SearchFor::disableProcesses(vector<Client>& clientsData, size_t index) {
	cout << "we are here" << endl;
	clientsData.at(index).setClientBlance(0);
	clientsData.at(index).setIsActive(false);
	c.areYouSure();
	saveAndAppend.saveDataToClients(clientsData);

	return;
}

template <typename T>
void SearchFor::enableUser(vector<T>& data, size_t index) {
	cout << "This user is disable, reactiveing this user ";
	if (c.areYouSure()) {
		vector<LoginData> loginData = c.get_login_creditentials();
		for (size_t i = 0; i < loginData.size(); i++) {

			if (loginData.at(i).getID() == data.at(index).getID()) {

				loginData.at(i).setIsActive(true);
				saveAndAppend.saveDataToUsers(loginData);
				enableProcesses(data, index);

				return;
			}
		}
	}
}

void SearchFor::enableProcesses(vector<Employee>& employeesData, size_t index) {

	employeesData.at(index).setIsActive(true);
	editEmployeeSalary(employeesData, index);

	saveAndAppend.saveDataToEmployees(employeesData);
	return;
}

void SearchFor::enableProcesses(vector<Client>& clientsData, size_t index) {

	long long blance = c.getClientNewBlance();
	clientsData.at(index).setIsActive(true);
	clientsData.at(index).setClientBlance(blance);
	saveAndAppend.saveDataToClients(clientsData);

	return;
}