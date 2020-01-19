#pragma once
#include <string>
using namespace std;
class LoginData
{
private:
	string mLoginUser;
	string mLoginPassword;
	string mAccountType;
public:
	void setLoginUser(string loginUser) {
		mLoginUser = loginUser;
	}
	void setLoginPassword(string loginPassword) {
		mLoginPassword = loginPassword;
	}
	void setAccountType(string accountType) {
		mAccountType = accountType;
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
};

