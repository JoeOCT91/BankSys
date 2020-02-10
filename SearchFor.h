#pragma once
#include <iostream>
#include "core.h"
using namespace std;



class SearchFor
{
private:

public:
	void showSearchOptions();
	void searchForClient(vector<Client>& clientsData);
	void searchByUsername(vector<Client>& clientsData);
	void foundOptions(vector<Client>& clientsData, Client currentClient, int clientInedx);

	void notFound(vector<Client>& clientsData);
	void searchByClientname(vector<Client>& clientsData);
	void searchByClientnameResult(vector<Client>& clientsData, vector<int>& resultClientsIndex);

	void searchByClientID(vector<Client>& clientsData);

	void searchByClientID(vector<Client>& clientsData, vector<int>& resultClientsIndex);

	void showAllClients(vector<Client>& clientsData);



protected:
	core  c;
};

