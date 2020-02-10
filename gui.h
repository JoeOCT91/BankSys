#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "core.h"
#include "SearchFor.h"

class gui
{
public:
	void Menu_client(LoginData& userLoginData, vector<LoginData>& loginData);
	void Menu_manager();
	void show_Edit_Employee();
	void menu_Edit_Employee();
	void Menu_employee();
	void Menu_login();
	LoginData login_now(vector<LoginData>& login_data);
	size_t checkUsername(vector<LoginData>& login_data);
	void checkPassword(LoginData userLoginData);
	void show_add_new_client();

private:
	void show_client_options(Client& currentClient);
	void show_employee_options();
	void show_manager_options();
	string CLIENTSFILE = "clients.txt";
	string USERSFILE = "users.txt";

	core c;
	SearchFor searchFor;
};

