#pragma once
#include <iostream>
#include "core.h"
using namespace std;



class SearchFor
{
private:
	void employeeFoundOptions(vector<Employee>& employeesData, Employee currentEmployee, size_t index);
	void employeeNotFound(vector<Employee>& employeesData);


public:
	void showSearchOptions();
	void searchForClient(vector<Client>& clientsData);
	void searchByUsername(vector<Client>& clientsData);
	void foundOptions(vector<Client>& clientsData, Client currentClient, int clientInedx);
	void showAllEmployees(vector<Employee>& employeesData);

	void notFound(vector<Client>& clientsData);
	void searchByClientname(vector<Client>& clientsData);
	void searchByClientnameResult(vector<Client>& clientsData, vector<int>& resultClientsIndex);

	void searchByClientID(vector<Client>& clientsData);

	void showAllClients(vector<Client>& clientsData);

	void showSearchForEmployee();

	void searchForEmployee(vector<Employee>& employeesData);

	void searchByEmployeeID(vector<Employee>& employeesData);





protected:
	core  c;
};

