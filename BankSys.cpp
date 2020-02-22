#include <vector>
#include "gui.h"
#include "core.h"
#include "LoginData.h"
#include "EmployeeGUI.h"

using namespace std;

EmployeeGUI e;
core c;
gui g;

void menu_login() {
	system("cls");
	size_t index = 0; 
	vector<LoginData> loginData = c.get_login_creditentials();

	LoginData userLoginData = c.login_now(loginData, index);

	int account_type = stoi(userLoginData.getAccountType());

	c.set_account_type(account_type);

	switch (c.get_account_type())
	{
	case 0:
		g.Menu_client(userLoginData, loginData, index);
		break;
	case 1:
		e.cheackEmployee(userLoginData, loginData, index);
		break;
	}
	menu_login();
}

int main(){
    //need to creat splash windows !!!!!!!

	menu_login();



}

