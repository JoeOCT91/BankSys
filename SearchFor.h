#pragma once
#include <iostream>
#include "SaveAndAppend.h"
#include "core.h"
using namespace std;



class SearchFor{
private:
	core  c;
	SaveAndAppend saveAndAppend;


	void editEmployeeInformation(vector<Employee>& employeesData, size_t index);
	void editEmployeeName(vector<Employee>& employeesData, size_t index);
	void employeeFoundOptions(vector<Employee>& employeesData, size_t index);
	void editEmployeePostion(vector<Employee>& employeesData, size_t index);
	void editEmployeeSalary(vector<Employee>& employeesData, size_t index);
	void disableProcesses(vector<Client>& clientsData, size_t index);
	void disableProcesses(vector<Employee>& employeesData, size_t index);
	void enableProcesses(vector<Client>& clientsData, size_t index);
	void enableProcesses(vector<Employee>& employeesData, size_t index);
	void employeeNotFound(vector<Employee>& employeesData);

	template<typename T>
	void disableUser(vector<T>& data, size_t index);
	template<typename T>
	void enableUser(vector<T>& data, size_t index);


public:
	void showSearchOptions();
	void searchForClient(vector<Client>& clientsData);
	void searchByUsername(vector<Client>& clientsData);
	void foundOptions(vector<Client>& clientsData, Client currentClient, int clientInedx);
	void editClientInformation(vector<Client>& clientsData, size_t clientIndex);
	void showAllEmployees(vector<Employee>& employeesData);


	void notFound(vector<Client>& clientsData);
	void searchByClientname(vector<Client>& clientsData);
	void searchByClientnameResult(vector<Client>& clientsData, vector<int>& resultClientsIndex);

	void searchByClientID(vector<Client>& clientsData);

	void showAllClients(vector<Client>& clientsData);

	void showSearchForEmployee();

	void searchForEmployee(vector<Employee>& employeesData);

	void searchByEmployeeID(vector<Employee>& employeesData);






	


};

