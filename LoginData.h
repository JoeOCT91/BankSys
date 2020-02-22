#pragma once
#include <string>
using namespace std;
class LoginData
{
private:
	string mID;
	string mLoginUser;
	string mLoginPassword;
	string mAccountType;
	bool mIsFristLogin;
	bool mStatus;
public:
	LoginData() {
		mLoginPassword = "asd123";
		mStatus = true; //true is active user
	}
	void setID(string ID) {
		mID = ID;
	}
	void setLoginUser(string loginUser) {
		mLoginUser = loginUser;
	}
	void setLoginPassword(string loginPassword) {
		mLoginPassword = loginPassword;
	}
	void setAccountType(string accountType) {
		mAccountType = accountType;
	}
	void setID(long long ID) {
		mID = to_string(ID);
	}
	void SetIsFristLogin(bool isFristLogin) {
		mIsFristLogin = isFristLogin;
	}
	void setIsActive(bool isActive) {
		mStatus = isActive;
	}
	string getLoginuser() {
		return mLoginUser;
	}
	string getLoginPassword() {
		return mLoginPassword;
	}
	string getAccountType() {
		return mAccountType;
	}
	string getID() {
		return mID;
	}
	bool getIsFristLogin() {
		return mIsFristLogin;
	}
	bool getIsActive() {
		return mStatus;
	}
};

