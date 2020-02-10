#pragma once
#include <string>
using namespace std;
class Employee{
private:
	string mFullName;
	string mEmployeePostion;
	int mEmployeeId;
	int mEmployeeDepartment;
public:

	Employee() {
		mFullName = "";
	}
	Employee(string fullName, string employeePostion, int employeeId) {
		mFullName = fullName;
		mEmployeePostion = employeePostion;
		mEmployeeId = employeeId;
	}
	string getEmployeeName() {
		return mFullName;
	}
	string getEmployeePostion() {
		return mEmployeePostion;
	}
	int getEmployeeId() {
		return mEmployeeId;
	}
	int getEmployeeDepartment() {
		return mEmployeeDepartment;
	}
	void setEmployeeName(string fullName) {
		mFullName = fullName;
	}
	void setEmployeePostion(string employeePostion) {
		mEmployeePostion = employeePostion;
	}
	void setEmployeeId(int employeeId) {
		mEmployeeId = employeeId;
	}
	void setEmployeeDepartment(int employeeDepartment) {
		mEmployeeDepartment = employeeDepartment;
	}
};

