#pragma once
#include <vector>
#include "LoginData.h"
#include "Employee.h"
#include "core.h"
#include "gui.h"

class EmployeeGUI{
private:
	core c;
	gui g;
	int getEmployeeDepartment(vector<Employee>& employeesData, LoginData& userLoginData);

	void showBankDirectorOptions();

	void HREmployeeOtions();

	void showHREmployeeOtions();


public:
	void cheackEmployee(LoginData userLoginData);
	void bankDirectorGUI(vector<Employee>& employeesData);
};

