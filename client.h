#include <string>
using namespace std;
class Client
{
private:
	string mClientFullName;
	string mClientLoginUsername;
	string mClientLoginPassword;
	long mClientBlance;
	long mClientAccountId;
public:
	Client() {
		mClientLoginPassword = "asd123";
	}
	
	void setClientFullName(string clientFullName) {
		mClientFullName = clientFullName;
	}
	void setClientLoginUsername(string clientFullName) {
		mClientLoginUsername = clientFullName[0];

		string::size_type pos = 0;
		string::size_type prev = 0;
		pos = clientFullName.find(" ", prev);
		prev = pos + 1;
		pos = clientFullName.find(" ", prev);
		mClientLoginUsername += clientFullName.substr(prev, pos - prev) ;
	}
	void setClientBlance() {
		cin >> mClientBlance;
		while (cin.fail()) {
			cout << "Cheak your entry is must be NUMBERS only";
			cin.clear();
			cin.ignore(256, '/n');
			cin >> mClientBlance;	
		}
		cout << mClientBlance;

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




};

