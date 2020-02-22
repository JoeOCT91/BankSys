#pragma once
#include <iostream>
#include <string>

using namespace std;

class Employee : public LoginData{

private:
	string mFullName;
	string mEmployeePostion;
	int mAge;
	int mSalary;

public:

	Employee() {
		mFullName = "";
		mEmployeePostion = "officer";
	}
	Employee(string fullName, string employeePostion, int employeeId) {
		mFullName = fullName;
		mEmployeePostion = employeePostion;

	}

	string getEmployeeName() {
		return mFullName;
	}

	string getEmployeePostion() {
		return mEmployeePostion;
	}


	string getEmployeeAge() {
		return to_string(mAge);
	}

	string getEmployeeSalary() {
		return to_string(mSalary);
	}

	void setEmployeeName(string fullName) {
		mFullName = fullName;
	}

	void setEmployeePostion(string employeePostion) {
		mEmployeePostion = employeePostion;
	}

	void setEmployeeSalary(int salary) {
		mSalary = salary;
	}

	void setEmployeeAge(string age) {
		mAge = stoi(age);
	}
	void printEmployeeInf() {

		cout << "Employee Full information:" << endl;
		cout << "Employee name: " << mFullName << endl;
		cout << "Employee postion: " << mEmployeePostion << endl;
		cout << "Employee salary: " << mSalary << endl;
		cout << "Employee age: " << mAge << endl;
	}
};

