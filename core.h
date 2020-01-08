#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "LoginData.h"
#include <fstream>


class core
{
public:
	vector<LoginData> get_login_creditentials();
	int string_to_int(string& s);
	int wait_user_input();
	void set_account_type(int& t);
	int get_account_type();

private:
	vector<string> read_a_file_to_vector_of_strings(string fileName);
	int get_selection_to_int(string& selection);
	int account_type = -1;
	char SEP = ',';
	string USERSFILE = "users.txt";
};

