#include "gui.h"

using namespace std;

void gui::clientOptions(LoginData& userLoginData, vector<LoginData>& loginData, size_t index)
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

	clientOptions(userLoginData, loginData, index);
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
    cout << "Enter your choice: ";
}




