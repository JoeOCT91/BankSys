#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Department{
private:
	string mDepartmentName;
	bool mIsHasManager;
	bool mIsHasGroupManager;
	int mDepartmentCode;
	int mManagerID;
	int mGroupManagerID;

public:
	void setDepartmentName(string departmentName) {
		mDepartmentName = departmentName;
	}
	void setIsHasManager(bool isHasManager) {
		mIsHasManager = isHasManager;
	}
	void setIsHasGroupManager(bool isHasGroupManager) {
		mIsHasGroupManager = isHasGroupManager;
	}
	void setManagerID(int managerID) {
		mManagerID = managerID;
	}
	void setGroupManagerID(int groupManagerID) {
		mGroupManagerID = groupManagerID;
	}
	string getDepartmentName() {
		return mDepartmentName;
	}
	bool getIsHasManager() {
		return mIsHasManager;
	}
	bool getIsHasGroupManager() {
		return mIsHasGroupManager;
	}
	int getDepartmentCode() {
		return mDepartmentCode;
	}
	int getManagerID() {
		return mManagerID;
	}
	int getGroupManagerID() {
		return mGroupManagerID;
	}
	void addNewDepartment();
	int appendToDepartments(Department newDepartment);
};

