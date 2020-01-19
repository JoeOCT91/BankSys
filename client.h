#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Client {

private:
	string mClientFullName;
	string mClientLoginUsername;
	long mClientAccountID;
    long mClientBlance;
	int mClientId;
	bool mFristLogin;
	

public:
	Client() {
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
	void setClientBlance(long clientBlance) {
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
		cout << "Client login username: " << mClientLoginUsername << endl;
		if (mFristLogin) {
			cout << "Client login password: asd123 " << endl;

		}
		else {
			cout << "Client login password : This client password is private" << endl;
		}

	}

};

