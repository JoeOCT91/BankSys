#pragma once
#include <vector>
#include "LoginData.h"
#include "Employee.h"
#include "core.h"
#include "gui.h"
#include "SearchFor.h"

class EmployeeGUI{
private:
	core c;
	gui g;
	SearchFor searchFor;

	Employee getEmployeeCurrentEmployee(vector<Employee>& employeesData, LoginData& userLoginData);
	void bankDirectorOptions(vector<Employee>& employeesData);
	void showBankDirectorOptions();
	void manageEmployees(vector<Employee>& employeesData);
	void showManageEmployee();

public:
	void cheackEmployee(LoginData userLoginData, vector<LoginData>& loginData, size_t index);

};

