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
		if (clientsData.at(i).getClientUsername() == searshFor) {
			Client currentClient = clientsData.at(i);
			foundOptions(clientsData, currentClient, i);
			return;
		}
	}
	notFound(clientsData);

}

void SearchFor::foundOptions(vector<Client>& clientsData, Client currentClient, int clientInedx) {
	system("cls");
	cout << "Your entry was found  " << endl;
	currentClient.printClientInf();
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
		c.editClientInformation(clientsData, currentClient, clientInedx);
		break;
	case 2:
		system("cls");
		c.Deposite(clientsData, currentClient, clientInedx);
		break;
	case 3:
		c.Withdrawal(clientsData, currentClient, clientInedx);
		system("cls");
		break;
	case 4:
		c.transferTo(clientsData, currentClient, clientInedx);
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
		cout << "	Account ID: " << clientsData.at(resultClientsIndex[n]).getClientId() << endl << endl;
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
		if (clientID == stoll(clientsData.at(i).getClientId())) {
			Client currentClient = clientsData.at(i);
			foundOptions(clientsData, currentClient, i);
			return;
		}
	}
	cout << "INVALID INPUT, This ID not exist, Try again\n";
	searchByClientID(clientsData);
}

void SearchFor::showAllClients(vector<Client>& clientsData) {
	cout << c.stringAddPadding("Num", 5);
	cout << c.stringAddPadding("ID", 10);
	cout << c.stringAddPadding("Name", 30);
	cout << c.stringAddPadding("Blance", 15);

	cout << "All Clients :\n";
	for (int i = 0; i < clientsData.size(); i++) {
		cout << c.stringAddPadding(to_string(i + 1), 5);
		cout << c.stringAddPadding(clientsData.at(i).getClientId(), 10);
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
	cout << "4- Exit" << endl;
	cout << "Enter your choice: ";
}

void SearchFor::searchForEmployee(vector<Employee>& employeesData) {

	system("cls");

	showSearchForEmployee();

	int selected_option = c.checkSelectionRange(4);

	switch (selected_option)
	{
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
		exit(0);
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
			employeeFoundOptions(employeesData, currentEmployee, i);
			return;
		}
	}
	cout << "INVALID INPUT, This ID not exist, Try again\n";
	searchByEmployeeID(employeesData);
}

void SearchFor::employeeFoundOptions(vector<Employee>& employeesData, Employee currentEmployee, size_t index) {
		system("cls");
		currentEmployee.printEmployeeInf();
		cout << "1- Edit employee information" << endl;
		cout << "4- Main menu" << endl;
		cout << "5- Exit" << endl;

		cin.clear();
		int selected_option = c.checkSelectionRange(5);

		switch (selected_option) {
		case 1:
			system("cls");
			c.editEmployeeInformation(employeesData, currentEmployee, index);
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
	cout << c.stringAddPadding("ID", 6);
	cout << c.stringAddPadding("Name", 35);
	cout << c.stringAddPadding("Postion", 15);
	cout << c.stringAddPadding("Salary", 7);
	cout << c.stringAddPadding("age", 5) << endl;
	

	for (int i = 0; i < employeesData.size(); i++) {
		cout << c.stringAddPadding(employeesData.at(i).getID(), 6);
		cout << c.stringAddPadding(employeesData.at(i).getEmployeeName(), 35);
		cout << c.stringAddPadding(employeesData.at(i).getEmployeePostion(), 15);
		cout << c.stringAddPadding(employeesData.at(i).getEmployeeSalary(), 7);
		cout << c.stringAddPadding(employeesData.at(i).getEmployeeAge(), 5) << endl;
	}
	cout << "Choose from above: ";
	size_t selected_option = c.checkSelectionRange(employeesData.size());
	size_t index = selected_option - 1;
	Employee currentEmployee = employeesData.at(index);
	employeeFoundOptions(employeesData, currentEmployee, index);

}