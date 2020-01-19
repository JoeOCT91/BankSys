#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "LoginData.h"
#include "client.h"
#include <fstream>


class core
{
private:
	vector<string> read_a_file_to_vector_of_strings(string fileName);
	int get_selection_to_int(string& selection);
	int account_type = -1;
	char SEP = ',';
	string USERSFILE = "users.txt";
	string CLIENTSFILE = "clients.txt";

public:
	vector<LoginData> get_login_creditentials();
	int append2Clients(string& fname, Client& new_client);
	int append2users(string& file_name, LoginData& new_client);
	long get_last_Client_ID();
	string get_last_line_in_text_file();
	bool text_is_empty();
	int string_to_int(string& s);
	long string_to_long(string& s);
	int wait_user_input();
	void set_account_type(int& t);
	int get_account_type();
	long wait_blance_input();
	long get_blance_to_long(string& selection);
	string set_login_username(string& fullName);
	vector<Client> get_clients_data();
	int get_client_index(LoginData& userLoginData, vector<Client>& clientsData);


};

