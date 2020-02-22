#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "LoginData.h"
#include "client.h"
#include "Employee.h"
#include "SaveAndAppend.h"


class core{
protected:
	char SEP = ',';
	string USERSFILE = "users.txt";
	string CLIENTSFILE = "clients.txt";
	string EMPLOYEEFILE = "employee.txt";
	SaveAndAppend saveAndAppend;
private:
	void editEmployee(vector<Employee>& employeesData, Employee currentEmployee, size_t index);








	vector<string> read_a_file_to_vector_of_strings(string fileName);
	bool text_is_empty(string filleName);
	string get_last_line_in_text_file(string& fileName);
	int get_input_to_digit(string& selection, int i);

	long long get_input_to_digit(string& selection, long l);

	int string_to_int(string& s);
	long long string_to_long(string& s);

	int account_type = -1;




public:
	LoginData login_now(vector<LoginData>& login_data, size_t& t);

	size_t checkUsername(vector<LoginData>& login_data);

	void checkPassword(LoginData userLoginData);

	long get_last_ID(string fileName);
	vector<LoginData> get_login_creditentials();
	int append2Clients(string& fname, Client& new_client);
	int append2users(string& file_name, LoginData& new_client);
	int checkSelectionRange(int to);
	vector<Employee> getEmployeesData();
	void addNewClient();
	string getFullName();
	string getString(string message);
	string cheackStringNotHasNumbers();
	void addNewEmployee(vector<Employee>& employeesData);
	int append2employee(Employee employee);
	void editEmployeeInformation(vector<Employee>& employeesData, Employee currentEmployee, size_t index);
	void editEmployeeInformation(vector<Employee> employeesData, Employee currentEmployee, size_t index);
	string stringAddPadding(string s, rsize_t count);
	void set_account_type(int& t);
	int get_account_type();
	int userReturnOExit();
	void fullAccountInfo(Client& currentClient);
	string set_login_username(string& fullName);
	vector<Client> get_clients_data();
	int get_client_index(LoginData& userLoginData, vector<Client>& clientsData);
	void Withdrawal(vector<Client>& clientsData, Client& currentClient, int index);

	void Deposite(vector<Client>& clientsData, Client& currentClient, int index);

	void transferTo(vector<Client>& clientsData, Client& currentClient, int index);

	void changeUserPassword(vector<LoginData>& loginData, LoginData& userLoginData, size_t index);

	long long checkBlance(Client& currentClient);

	long long checkId(vector<Client>& clientsData, int& index);


	void saveDataToClients(string fileName, vector<Client> clients);
	void saveDataToUsers(string fileName, vector<LoginData> loginData);
	int showAccountBlance(Client& currentclient);
	bool string_to_bool(string s);

	string bool_to_string(bool b);

	int wait_user_input();
	long long wait_user_input(string errorMessage);
	void editClientInformation(vector<Client>& clientsData, Client& currentClient, int& clientIndex);

	void editClientName(vector<Client>& clientsData, Client& currentClient, int& clientIndex);

	void resetPassword(string ID);

	bool areYouSure();
	void disableUser(vector<LoginData>* data, LoginData userData, size_t index);
	void disableEmployeeProcesses(vector<LoginData>* data);
	void accountIsDisable();





	
	
};

