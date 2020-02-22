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
protected:
	char SEP = ',';
	string USERSFILE = "users.txt";
	string CLIENTSFILE = "clients.txt";
	string EMPLOYEEFILE = "employee.txt";

private:

	string bool_to_string(bool b);
	bool string_to_bool(string s);


public:
	void saveDataToEmployees(vector<Employee> employeesData);

	int append2employee(Employee employee);


};

