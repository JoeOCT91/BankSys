#include "gui.h"

using namespace std;

void gui::show_manager_options() {
    cout << "Welcome you can manage mange bank system form here\nYou loged in as admin" << endl;
    cout << "1- clients Options" << endl;
    cout << "2- Employee options" << endl;
    cout << "3- change user" << endl;
    cout << "4- Exit" << endl;
    cout << "Enter your choice :";
}

void gui::Menu_manager()
{
	system("cls");
    show_manager_options();
    int selected_option = c.checkSelectionRange(4);

    switch (selected_option)
    {
    case 1:
		system("cls");
		Menu_employee();
        break;
    case 2:
		system("cls");
        cout << "deposit" << endl;
        break;
    case 3:
		system("cls");
        break;
    case 4:
		system("cls");
		exit(0);
        break;

    }

    Menu_manager();
}

void gui::show_Edit_Employee() {
	cout << "Welcome you can manage mange bank system form here\nYou loged in as admin" << endl;
	cout << "1- Add new employee" << endl;
	cout << "2- Search for employee" << endl;
	cout << "3- Show all employee" << endl;
	cout << "4- Main Menu" << endl;
	cout << "5- Exit";
	cout << "Enter your choice :";
}

void gui::menu_Edit_Employee()
{
	system("cls");
	show_Edit_Employee();
	int selected_option = c.checkSelectionRange(4);

	switch (selected_option)
	{
	case 1:
		system("cls");
		Menu_employee();
		break;
	case 2:
		system("cls");
		cout << "deposit" << endl;
		break;
	case 3:
		system("cls");
		break;
	case 4:
		system("cls");
		exit(0);
		break;

	}

	Menu_manager();
}

void gui::Menu_employee()
{
	system("cls");
	//All clients data stored in vector 
	vector<Client> clientsData = c.get_clients_data();

    show_employee_options();
    int selected_option = c.wait_user_input();

    system("cls");

    switch (selected_option)
    {
    case 1:
        c.addNewClient();
        break;
    case 2:
		searchFor.searchForClient(clientsData);
        break;
    case 3:
		searchFor.showAllClients(clientsData);
        break;
	case 4:
		return;
		break;
	case 5:
		exit(0);
		break;
    }

    Menu_employee();
}
void gui::show_employee_options() {
	cout << "Welcome you can manage bank clients from here" << endl;
	cout << "1- Add new client" << endl;
	cout << "2- Searsh for client" << endl;
	cout << "3- Show all clients" << endl;
	cout << "4- change user" << endl;
	cout << "5- Exit" << endl;
	cout << "Enter your choice :";
}

// CLIENT SECTION #############################

void gui::Menu_client(LoginData& userLoginData, vector<LoginData>& loginData, size_t index)
{   //All clients data stored in vector 
    vector<Client> clientsData = c.get_clients_data();
    // this varibale hold current client index in clientsdata, will use it to edit data 
    int thisClientIndexInClientsData = c.get_client_index(userLoginData, clientsData);
    //Current client data any change will store in this object and push it to the vector in the same index 
    Client currentClient = clientsData.at(thisClientIndexInClientsData);
    //most cheak if it the frist login by this user......
    if (userLoginData.getIsFristLogin()) {
		c.changeUserPassword(loginData, userLoginData, index);
	}

    system("cls");
    show_client_options(currentClient);
	int selected_option = c.checkSelectionRange(7);

    switch (selected_option)
    {
	case 1:
        system("cls");
		c.fullAccountInfo(currentClient);
        break;
    case 2:
        system("cls");
        c.showAccountBlance(currentClient);
        break;
	case 3:
		system("cls");
		c.Deposite(clientsData, currentClient, thisClientIndexInClientsData);
		break;
    case 4:
         system("cls");
         c.Withdrawal(clientsData, currentClient, thisClientIndexInClientsData);
        break;
    case 5:
        system("cls");
        c.transferTo(clientsData, currentClient, thisClientIndexInClientsData);
        break;
	case 6:
		system("cls");
		c.changeUserPassword(loginData, userLoginData, index);
		break;
	case 7:
		system("cls");
		exit(0);
		break;
    }

    Menu_client(userLoginData, loginData, index);
}

void gui::show_client_options(Client& currentClient) {
    cout << "Welcome " << currentClient.getClientFullName() << " you can manage your account from here" << endl;
    cout << "1- Full account information" << endl;
    cout << "2- Account blance" << endl;
	cout << "3- Deposite" << endl;
    cout << "4- Withdrawal" << endl;
    cout << "5- Transfer" << endl;
    cout << "6- Change password" << endl;
	cout << "7- Exit" << endl;
    cout << "Enter your choice :";
}




