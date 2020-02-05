#pragma once
#include <iostream>
#include "core.h"
#include "SearchFor.h"
using namespace std;
core cc;


// Need to Fix change if to while () .... checkSelectionRange


void SearchFor::showSearchOptions() {
	cout << "Search by" << endl;
	cout << "1- username" << endl;
	cout << "2- client name" << endl;
	cout << "3- account ID" << endl;
	cout << "Enter your choice :";
}

void SearchFor::searchForClient(vector<Client>& clientsData) {

	system("cls");

	showSearchOptions();

	int selected_option = cc.checkSelectionRange(3);

	switch (selected_option)
	{
	case 1:
		system("cls");
		searchByUsername(clientsData);
		break;
	default:
	case 2:
		system("cls");
		searchByClientname(clientsData);

		break;
	case 3:
		system("cls");
		searchByUsername(clientsData);
		break;
	}
}

void SearchFor::searchByUsername(vector<Client>& clientsData) {
	string searshFor;
	cout << "Enter the client username you want to search for: ";
	cin.clear();
	getline(cin, searshFor);
	cout << searshFor;

	for (int i = 0; i < clientsData.size(); i++) {
		if (clientsData.at(i).getClientUsername() == searshFor) {
			Client currentClient = clientsData.at(i);
			currentClient.printClientInf();
			foundOptions(clientsData, currentClient, i);
			return;
		}
	}
	notFound(clientsData);

}

void SearchFor::foundOptions(vector<Client>& clientsData, Client currentClient, int clientInedx) {
	cout << "Your entry not found  " << endl;
	cout << "1- Edit client information" << endl;
	cout << "2- Make deposite" << endl;
	cout << "3- Make withdrawal" << endl;
	cout << "4- Make transfer" << endl;
	cout << "5- Exit" << endl;

	cout << "Choose you action :";
	core cc;
	int selected_option = cc.checkSelectionRange(5);
	switch (selected_option) {
	case 1:
		cc.editClientInformation(clientsData, currentClient, clientInedx);
		break;
	case 2:
		system("cls");
		cc.Deposite(clientsData, currentClient, clientInedx);
		break;
	case 3:
		system("cls");
		break;
	case 4:
		system("cls");
		break;
	case 5:
		exit(0);
		break;
	}
}

void SearchFor::notFound(vector<Client>& clientsData) {
	cout << "Your entry not found  " << endl;
	cout << "1- Try Again" << endl;
	cout << "2- Return to main menu" << endl;
	cout << "3- Exit" << endl;
	int selected_option = cc.checkSelectionRange(3);
	switch (selected_option) {
	case 1:
		searchForClient(clientsData);
		break;
	case 2:
		system("cls");
		break;
	case 3:
		exit(0);
		break;
	}
}

void SearchFor::searchByClientname(vector<Client> & clientsData) {
	string searchFor;
	cout << "Enter the client username you want to search for: ";
	cin.clear();
	getline(cin, searchFor);
	vector<int> foundClientsIndex;
	for(int i = 0; i < clientsData.size(); i++) {

		size_t found = clientsData.at(i).getClientFullName().find(searchFor);

		if (found != string::npos) {
			foundClientsIndex.push_back(i);
		}
	}
		
	if (foundClientsIndex.empty()) {
		notFound(clientsData);
	}

}


