#pragma once
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
	
public:
	Client() {
		mClientAccountID = 0;
		mClientBlance = 0;
		mClientFullName = "";
		mClientLoginUsername = "";
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

	void printClientInf() {
		cout << "Full client information:" << endl;
		cout << "Client name: " << mClientFullName << endl;
		cout << "Account ID: " << mClientAccountID << endl;
		cout << "Client Blance: " << mClientBlance << endl;
		cout << "Client login username: " << mClientLoginUsername << endl;
	}

};

