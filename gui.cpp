#include "gui.h"

using namespace std;

int gui::login_now(vector<LoginData>& login_data)
{
    string username = "";
    string password = "";
    string accountType = "";
    size_t users_count = login_data.size();

    cout << "Please enter your username: ";
    cin >> username;

    for (int i = 0; i < users_count; i++) {
        if (username == login_data[i].getLoginuser()) {
            cout << "Please enter your password: ";
            cin >> password;
            while (password != login_data[i].getLoginPassword()) {
                cout << "INVALID PASSWORD RETRY" << endl;
                cout << "Enter your password Again: ";
                cin >> password;
            }
            accountType = login_data[i].getAccountType();
            return  c.string_to_int(accountType);
        }
    }
    cout << "This username you enterd not exist, TRY AGAIN";
    login_now(login_data);

    return -1;
}


void gui::show_client_options() {
    cout << "Welcome you can manage your account from here" << endl;
    cout << "0- exit" << endl;
    cout << "1- Account blance" << endl;
    cout << "2- Deposite" << endl;
    cout << "3- With" << endl;
    cout << "4- change user" << endl;
    cout << "Enter your choice :";
}

void gui::show_employee_options() {
    cout << "Welcome you can manage bank clients from here" << endl;
    cout << "1- Add new client" << endl;
    cout << "2- Edit existing account" << endl;
    cout << "3- Show all clients" << endl;
    cout << "3- change user" << endl;
    cout << "0- exit" << endl;
    cout << "Enter your choice :";
}
//This function to add a new client.
void gui::show_add_new_client() {
    //By default this client login password will be "asd123"
    Client new_client;
    LoginData loginData;
    string new_client_fullname;
    string new_client_full_info;
    cout << "Enter client full name: ";
    getline(cin, new_client_fullname);
    new_client.setClientFullName(new_client_fullname);

    new_client.setClientLoginUsername(c.set_login_username(new_client_fullname));
    // set ID for this new client ....
    if (c.text_is_empty()) {
        new_client.setClientAccountId(20000000); //if this client is the frist client in the bank
    }
    else {
        long clientId;
        clientId = c.get_last_Client_ID();
        clientId += 1;
        new_client.setClientAccountId(clientId);
    }
    
    cout << "Please enter account opening blance: ";
    long blance = c.wait_blance_input();



    new_client.setClientBlance(blance);
    new_client.printClientInf();
    

    new_client_full_info = new_client.getClientFullName() + "," + new_client.getClientBlance();

    c.append2Clients(CLIENTSFILE, new_client);
    c.append2users(USERSFILE, new_client);
    
    

}
void gui::show_manager_options() {
    cout << "Welcome you can manage your account from here" << endl;
    cout << "0- exit" << endl;
    cout << "1- Account blance" << endl;
    cout << "2- Deposite" << endl;
    cout << "3- With" << endl;
    cout << "4- change user" << endl;
    cout << "Enter your choice :";
}


void gui::Menu_manager()
{
    show_manager_options();
    int selected_option = c.wait_user_input();

    switch (selected_option)
    {
    case 0:
        exit(0);
        break;
    case 1:
        cout << "balance" << endl;
        break;
    case 2:
        cout << "deposit" << endl;
        break;
    case 3:
        cout << "with" << endl;
        break;
    case 4:
        Menu_login();
        break;
    default:
        break;
    }

    Menu_manager();
}

void gui::Menu_employee()
{
    show_employee_options();
    int selected_option = c.wait_user_input();

    system("cls");

    switch (selected_option)
    {
    case 0:
        exit(0);
        break;
    case 1:
        show_add_new_client();
        break;
    case 2:
        cout << "edit existing" << endl;
        break;
    case 3:
        Menu_login();
        break;
    default:
        break;
    }

    Menu_employee();
}

void gui::Menu_client()
{
    show_client_options();
    int selected_option = c.wait_user_input();

    switch (selected_option)
    {
    case 0:
        exit(0);
        break;
    case 1:
        cout << "balance" << endl;
        break;
    case 2:
        cout << "deposit" << endl;
        break;
    case 3:
        cout << "with" << endl;
        break;
    case 4:
        Menu_login();
        break;
    default:
        break;
    }

    Menu_client();
}
void gui::Menu_login()
{
    vector<LoginData> loginData = c.get_login_creditentials();

    int account_type = login_now(loginData);
    
    c.set_account_type(account_type);

    system("cls");

    int selected_option = -1;
    switch (c.get_account_type())
    {
    case 0:
        Menu_client();
        break;
    case 1:
        Menu_employee();
        break;
    case 2:
        Menu_manager();
        break;
    default:
        break;
    }
}