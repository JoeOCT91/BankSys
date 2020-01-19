#pragma once
#include <string>
using namespace std;
class LoginData
{
private:
	string mLoginUser;
	string mLoginPassword;
	string mAccountType;
	bool mIsFristLogin;
public:
	LoginData() {
		mLoginPassword = "asd123";
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
	bool getIsFristLogin() {
		return mIsFristLogin;
	}
};

