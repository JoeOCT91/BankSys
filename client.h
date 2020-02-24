#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Client : public LoginData {

private:
	string mClientFullName;
	//long mClientAccountID;
    long long mClientBlance;
	
public:
	Client() {
		mClientBlance = 0;
		mClientFullName = "";
	}
	
	void setClientFullName(string clientFullName) {
		mClientFullName = clientFullName;
	}

	void setClientBlance(long long clientBlance) {
		mClientBlance = clientBlance;
	}
 
	string  getClientFullName() {
		return mClientFullName;
	}

	string getClientBlance() {
		return to_string(mClientBlance);
	}

	void printClientInf() {
		cout << "Full client information:" << endl;
		cout << "Client name: " << mClientFullName << endl;
		cout << "Client Blance: " << mClientBlance << endl;
	}

};

