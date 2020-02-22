#pragma once
#include <string>
using namespace std;
class NewEmployeeRequest{
private:
	int mRequestID;
	int mEmployeeID;
	string mRequestDepartment;
	string mRequestPostion;
	string mRequestTittle;
	int mAgeRange[2];
	int msugestedSalary;
	bool mIsAprrovedByHRManager;
	bool mIsAprrovedByDepartmentManager;
	bool mIsAcceptedByHR;
	bool mIsAcceptedByDepartment;
	//i wanted to add dates ;
public:
	void setRequestID(int requestID) {
		mRequestID = requestID;
	}
	void setEmployeeID(int employeeID) {
		mEmployeeID = employeeID;
	}
	void setRequestDepartment(string requestDepartment) {
		mRequestDepartment = requestDepartment;
	}
	void setRequestPostion(string requestPostion) {
		mRequestPostion = requestPostion;
	}
	void setRequestTittle(string requestTittle) {
		mRequestTittle = requestTittle;
	}
	void setAgeRange(int ageRange[]) {
		mAgeRange[0] = ageRange[0];
		mAgeRange[1] = ageRange[2];
	}
	void setIsAprrovedByHRM(bool isAprroved) {
		mIsAprrovedByDepartmentManager = isAprroved;
	}
	void setIsAprrovedByDM(bool isAprroved) {
		mIsAprrovedByDepartmentManager = isAprroved;
	}
	void setIsAcceptedByHR(bool isAccepted) {
		mIsAcceptedByHR = isAccepted;
	}
	void setIsAcceptedByDM(bool isAccepted) {
		mIsAcceptedByDepartment = isAccepted;
	}
	int getRequestID() {
		return mRequestID;
	}
	int getEmployeeID() {
		return mEmployeeID;
	}
	string getRequestDepartment() {
		return mRequestDepartment;
	}
	string getRequestPostion() {
		return mRequestPostion;
	}
	string getRequestTittle() {
		return mRequestTittle;
	}
	int* getAgeRange() {
		return mAgeRange;
	}
	bool getIsAprrovedByHRM() {
		return mIsAprrovedByDepartmentManager;
	}
	bool getIsAprrovedByDM() {
		return mIsAprrovedByDepartmentManager;
	}
	bool getIsAcceptedByHR() {
		return mIsAcceptedByHR;
	}
	bool getIsAcceptedByDM() {
		return mIsAcceptedByDepartment;
	}
	
};

