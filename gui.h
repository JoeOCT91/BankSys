#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "core.h"
#include "SearchFor.h"

class gui
{

private:

	core c;
	SearchFor searchFor;
	string USERSFILE = "users.txt";
	string CLIENTSFILE = "clients.txt";
	void show_client_options(Client& currentClient);


public:

	void clientOptions(LoginData& userLoginData, vector<LoginData>& loginData, size_t index);
};

