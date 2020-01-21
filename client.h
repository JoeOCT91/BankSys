#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Client {

private:
	string mClientFullName;
	string mClientLoginUsername;
	long mClientAccountID;
    long long mClientBlance;
	bool mFristLogin;
	

public:
	Client() {
		mClientAccountID = 0;
		mClientBlance = 0;
		mFristLogin = true;
	}
	
	void setClientFullName(string clientFullName) {
		mClientFullName = clientFullName;
	}

	void setClientLoginUsername(string clientLoginUsername) {
		mClientLoginUsername = clientLoginUsername;
	}

	void setClientAccountId(long clientAccountID) {

		mClientAccountID = clientAccountID;
	}
	void setClientBlance(long long clientBlance) {
		mClientBlance = clientBlance;
	}
	void setFristLogin(bool fristLogin) {
		mFristLogin = fristLogin;
	}
 
	string  getClientFullName() {
		return mClientFullName;
	}
	string getClientUsername() {
		return mClientLoginUsername;
	}
	string getClientBlance() {
		return to_string(mClientBlance);
	}
	string getClientId() {
		return to_string(mClientAccountID);
	}
	bool isFristLogin() {
		return mFristLogin;
	}

	void printClientInf() {

		cout << "Full client information:" << endl;
		cout << "Client name: " << mClientFullName << endl;
		cout << "Account ID: " << mClientAccountID << endl;
		cout << "Client login username: " << mClientLoginUsername << endl;
		if (mFristLogin) {
			cout << "Client login password: asd123 \"Default password must change at frist login\" " << endl;
		}
		else {
			cout << "Client login password : This client password is private" << endl;
		}
		cout << "Client Blance: " << mClientBlance << endl;


	}

};

