#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Client {

private:
	string mClientFullName;
	string mClientLoginUsername;
	string mClientLoginPassword;
	long mClientAccountID;
    long mClientBlance;
	int mClientId;
	bool mFristLogin;
	

public:
	Client() {
		//set defult password for any created client must change at frist login
		mClientLoginPassword = "asd123";
		mFristLogin = true;

	}
	
	void setClientFullName(string clientFullName) {
		mClientFullName = clientFullName;
	}

	// This function to set login username for new clients  .... Done and tested
	void setClientLoginUsername(string clientLoginUsername) {
		mClientLoginUsername = clientLoginUsername;
	}
	// This function to set Account ID .... Almost Done in testing progress
	void setClientAccountId(long clientAccountID) {

		mClientAccountID = clientAccountID;
	}
	void setClientBlance(long clientBlance) {
		mClientBlance = clientBlance;
	}
	void resetClientLoginPassword() {
		mClientLoginPassword = "asd123";
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
		cout << "Client login username: " << mClientLoginUsername << endl;
		if (mFristLogin) {
			cout << "Client login password: asd123 " << endl;

		}
		else {
			cout << "Client login password : This client password is private" << endl;
		}

	}




};

