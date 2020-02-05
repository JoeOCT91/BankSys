#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "LoginData.h"
#include "client.h"


class SearchFor;

class core{

private:
	vector<string> read_a_file_to_vector_of_strings(string fileName);
	int get_input_to_digit(string& selection, int i);

	long long get_input_to_digit(string& selection, long l);

	int string_to_int(string& s);
	long long string_to_long(string& s);
	//void showSearchOptions();

	void printSearchResult(Client client);


	 
	int account_type = -1;
	char SEP = ',';
	string USERSFILE = "users.txt";
	string CLIENTSFILE = "clients.txt";


public:
	vector<LoginData> get_login_creditentials();
	int append2Clients(string& fname, Client& new_client);
	int append2users(string& file_name, LoginData& new_client);
	int checkSelectionRange(int to);
	int checkSelectionRange(int from, int to);
	long get_last_Client_ID();
	string get_last_line_in_text_file();
	bool text_is_empty();
	void set_account_type(int& t);
	int get_account_type();
	int userReturnOExit();
	void fullAccountInfo(Client& currentClient);
	string set_login_username(string& fullName);
	vector<Client> get_clients_data();
	int get_client_index(LoginData& userLoginData, vector<Client>& clientsData);
	void Withdrawal(vector<Client>& clientsData, Client& currentClient, int index);
	void changeUserPassword(vector<LoginData>& loginData, LoginData& userLoginData);

	void Deposite(vector<Client>& clientsData, Client& currentClient, int index);

	void transferTo(vector<Client>& clientsData, Client& currentClient, int index);

	long long checkBlance(Client& currentClient);

	long long checkId(vector<Client>& clientsData, int& index);

	void searchForClient(vector<Client>& clientsData);

	void read_text_file_then_replace_a_line(string fileName, string searchFor, string replaceThis, string replaceTo);
	void saveDataToClients(string fileName, vector<Client> clients);
	void saveDataToUsers(string fileName, vector<LoginData> loginData);
	int showAccountBlance(Client& currentclient);
	bool string_to_bool(string s);

	string bool_to_string(bool b);

	int wait_user_input();
	long long wait_user_input(string errorMessage);


	//void searchByusername(vector<Client>& clientsData);

	void foundOptions(vector<Client>& clientsData, Client currentClient, int clientInedx);





	void editClientInformation(vector<Client>& clientsData, Client& currentClient, int& clientIndex);



	void editClientInformation(vector<Client>& clientsData, Client& currentClient);
protected:

	SearchFor* search;
	
	
};

