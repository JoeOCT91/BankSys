#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "client.h"
#include "core.h"


class gui
{
public:
	void Menu_client();
	void Menu_manager();
	void Menu_employee();
	void Menu_login();
	int login_now(vector<LoginData>& login_data);

private:
	void show_client_options();
	void show_employee_options();
	void show_manager_options();
	core c;
};

