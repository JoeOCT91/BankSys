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
		mID = ID;
	}
	void SetIsFristLogin(bool isFristLogin) {
		mIsFristLogin = isFristLogin;
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
};

