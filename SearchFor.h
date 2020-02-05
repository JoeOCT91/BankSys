#pragma once
using namespace std;

class core;

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



protected:
	core* c;
};

