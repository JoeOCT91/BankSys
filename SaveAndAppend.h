#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "LoginData.h"
#include "Employee.h"
#include "client.h"

using namespace std;
class SaveAndAppend{
private:
	char SEP = ',';
	string USERSFILE = "users.txt";
	string CLIENTSFILE = "clients.txt";
	string EMPLOYEEFILE = "employee.txt";
	string bool_to_string(bool b);
	bool string_to_bool(string s);


public:
	void saveDataToEmployees(vector<Employee> employeesData);
	void saveDataToUsers(vector<LoginData> loginData);
	void saveDataToClients(vector<Client> clients);
	int append2users(LoginData& loginData);
	int append2Clients(Client& new_client);
	int append2employee(Employee employee);



};

