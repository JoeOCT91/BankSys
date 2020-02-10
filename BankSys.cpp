#include <vector>
#include "gui.h"
#include "core.h"
#include "LoginData.h"
#include "EmployeeGUI.h"

using namespace std;

int main(){
    //need to creat splash windows !!!!!!!
	EmployeeGUI e;
	core c;
    gui g;


	

	vector<LoginData> loginData = c.get_login_creditentials();
	LoginData userLoginData = g.login_now(loginData);
	int account_type = stoi(userLoginData.getAccountType());

	c.set_account_type(account_type);

	system("cls");

	int selected_option = -1;
	switch (c.get_account_type())
	{
	case 0:
		g.Menu_client(userLoginData, loginData);
		break;
	case 1:
		e.cheackEmployee(userLoginData);
		break;

	}

}

