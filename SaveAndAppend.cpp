#include "SaveAndAppend.h"

void SaveAndAppend::saveDataToEmployees(vector<Employee> employeesData) {

	ofstream myfile(EMPLOYEEFILE);
	string lineOfData;

	if (myfile.is_open())
	{
		for (int i = 0; i < employeesData.size(); i++)
		{
			lineOfData = employeesData.at(i).getID() + SEP;
			lineOfData += employeesData.at(i).getEmployeeName() + SEP;
			lineOfData += employeesData.at(i).getEmployeePostion() + SEP;
			lineOfData += employeesData.at(i).getEmployeeSalary() + SEP;
			lineOfData += employeesData.at(i).getEmployeeAge() + SEP;
			lineOfData += bool_to_string(employeesData.at(i).getIsActive());

			myfile << lineOfData << endl;
		}
		myfile.close();
	}
}

int SaveAndAppend::append2employee(Employee employee){

	string lineOfData;
	ofstream myfile(EMPLOYEEFILE, ios::app);
	if (myfile.is_open())
	{
		lineOfData = employee.getID() + SEP;
		lineOfData += employee.getEmployeeName() + SEP;
		lineOfData += employee.getEmployeePostion() + SEP;
		lineOfData += employee.getEmployeeSalary() + SEP;
		lineOfData += employee.getEmployeeAge() + SEP;
		lineOfData += bool_to_string(employee.getIsActive());

		myfile << lineOfData << endl;

		myfile.close();
		return 0;
	}
	else
	{
		cout << "Unable to open file";
		return 1;
	}

	return 0;
}

void SaveAndAppend::saveDataToUsers(vector<LoginData> loginData) {

	ofstream myfile(USERSFILE);
	string lineOfData;
	if (myfile.is_open())
	{
		for (int i = 0; i < loginData.size(); i++)
		{
			lineOfData = loginData.at(i).getID() + SEP;
			lineOfData += loginData.at(i).getLoginuser() + SEP;
			lineOfData += loginData.at(i).getLoginPassword() + SEP;
			lineOfData += loginData.at(i).getAccountType() + SEP;
			lineOfData += bool_to_string(loginData.at(i).getIsFristLogin()) + SEP;
			lineOfData += bool_to_string(loginData.at(i).getIsActive());
			myfile << lineOfData << endl;
		}
		myfile.close();
	}
}

int SaveAndAppend::append2users(LoginData& loginData)
{
	string lineOfData;
	ofstream myfile(USERSFILE, ios::app);
	if (myfile.is_open())
	{
		lineOfData = loginData.getID() + SEP;
		lineOfData += loginData.getLoginuser() + SEP;
		lineOfData += loginData.getLoginPassword() + SEP;
		lineOfData += loginData.getAccountType() + SEP;
		lineOfData += bool_to_string(loginData.getIsFristLogin()) + SEP;
		lineOfData += bool_to_string(loginData.getIsActive());

		myfile << lineOfData << endl;

		myfile.close();
		return 0;
	}
	else
	{
		cout << "Unable to open file";
		return 1;
	}

	return 0;
}

void SaveAndAppend::saveDataToClients(vector<Client> clients) {

	ofstream myfile(CLIENTSFILE);
	string lineOfData;
	if (myfile.is_open())
	{
		for (int i = 0; i < clients.size(); i++)
		{
			lineOfData = clients.at(i).getID() + SEP;
			lineOfData += clients.at(i).getClientFullName() + SEP;
			lineOfData += clients.at(i).getClientBlance() + SEP;
			lineOfData += bool_to_string(clients.at(i).getIsActive());
			myfile << lineOfData << endl;
		}
		myfile.close();
	}
}

int SaveAndAppend::append2Clients(Client& new_client)
{
	string lineOfData;
	ofstream myfile(CLIENTSFILE, ios::app);
	if (myfile.is_open())
	{
		lineOfData = new_client.getID() + SEP;
		lineOfData += new_client.getClientFullName() + SEP;
		lineOfData += new_client.getClientBlance() + SEP;
		lineOfData += new_client.getLoginuser() + SEP;
		lineOfData += new_client.getIsActive() + SEP;
		myfile << lineOfData << endl;
		myfile.close();
		return 0;
	}
	else
	{
		cout << "Unable to open file";
		return 1;
	}
	return 0;
}
bool SaveAndAppend::string_to_bool(string s) {
	bool r = false;
	if (s == "true") {
		r = true;
	}
	else if (s == "false") {
		r = false;
	}
	return r;
}

string SaveAndAppend::bool_to_string(bool b) {
	string r = "";
	if (b) {
		r = "true";
	}
	else if (!b) {
		r = "false";
	}
	return r;
}