#pragma once
#include "core.h"
#include "SearchFor.h"

using namespace std;

LoginData core::login_now(vector<LoginData>& login_data, size_t& t)
{
	size_t i = checkUsername(login_data);
	checkPassword(login_data[i]);
	t = i; //this user indexx in loginData list

	LoginData userLoginData = login_data[i];
	if (userLoginData.getIsActive()) {
		return  userLoginData;
	}
	else
	{
		accountIsDisable();
	}

}

size_t core::checkUsername(vector<LoginData>& login_data) {
	string username;
	size_t users_count = login_data.size();

	cout << "Please enter your username: ";
	cin.clear();
	getline(cin, username);

	while (true) {
		for (size_t n = 0; n < users_count; n++) {
			if (login_data.at(n).getLoginuser() == username) {
				return n;
			}
		}
		cout << "The username you enterd not exist, TRY AGAIN\n";
		cout << "Please enter your username: ";

		cin.clear();
		getline(cin, username);
	}
}

void core::checkPassword(LoginData userLoginData) {

	string password;

	cout << "Please enter your password: ";
	while (true) {
		cin.clear();
		getline(cin, password);
		if (password == userLoginData.getLoginPassword()) {
			return;
		}
		else {
			cout << "INVALID PASSWORD RETRY" << endl;
			cout << "Enter your password Again: ";
		}
	}
}

vector<string> core::read_a_file_to_vector_of_strings(string fileName)
{
    vector<string> vector_of_strings;
    string lineOfData;

    ifstream file(fileName);
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, lineOfData);

			// not store empty line in the list 
            if (lineOfData != "") {
                vector_of_strings.push_back(lineOfData);
            }	
        }
        file.close();
    }
    else{
        cout << "Unable to open file: " << fileName << endl;
    }
    return vector_of_strings;
}

bool core::text_is_empty(string fileName) {
    int length;
    ifstream myfile;
	
    myfile.open(fileName, ios::binary); // open your file
    myfile.seekg(0, ios::end); // put the "cursor" at the end of the file
    length = myfile.tellg(); // find the position of the cursor
    myfile.close(); // close your file

    if (length == 0) {
        return true;
    }
    else {
        return false;
    }
}

// To get last line in a text file and store it as string .... 
string core::get_last_line_in_text_file(string& fileName) {

    ifstream fin;
    fin.open(fileName);
    if (fin.is_open()) {
        fin.seekg(-3, ios_base::end);                // go to one spot before the EOF

        bool keepLooping = true;
        while (keepLooping) {
            char ch;
            fin.get(ch);                            // Get current byte's data

            if ((int)fin.tellg() <= 1) {             // If the data was at or before the 0th byte
                fin.seekg(0);                       // The first line is the last line
                keepLooping = false;                // So stop there
            }
            else if (ch == '\n') {                   // If the data was a newline
                keepLooping = false;                // Stop at the current position.
            }
            else {                                  // If the data was neither a newline nor at the 0 byte
                fin.seekg(-2, ios_base::cur);       // Move to the front of that data, then to the front of the data before it
            }
        }
        string lastLine;
        getline(fin, lastLine);                      // Read the current line
        
        fin.close();
        return lastLine;
    }

    else {
        cout << "Clients.txt faild to open" << endl;
        return "j";
    } 
}

// To extratct client id from a string 
long core::get_last_ID(string fileName) {
    string lastLine = get_last_line_in_text_file(fileName);
    long lastId;
    string::size_type pos = 0;
    string::size_type prev = 0;

    pos = lastLine.find(SEP, prev);
    string s = lastLine.substr(prev, pos - prev);
    lastId = stoll(s);

    return lastId;
         
    }

vector<LoginData> core::get_login_creditentials() {
    vector<LoginData> loginData;
    vector<string> logins_as_strings = read_a_file_to_vector_of_strings(USERSFILE);
    size_t user_count = logins_as_strings.size();

    string::size_type pos = 0;
    string::size_type prev = 0;

    for (int i = 0; i < user_count; i++)
    {
        LoginData data;
        string userData = logins_as_strings.at(i);
		pos = userData.find(SEP, prev);
		data.setID(userData.substr(prev, pos - prev));
		prev = pos + 1;
        pos = userData.find(SEP, prev);
        data.setLoginUser(userData.substr(prev, pos - prev));
        prev = pos + 1;
        pos = userData.find(SEP, prev);
        data.setLoginPassword(userData.substr(prev, pos - prev));
        prev = pos + 1;
        pos = userData.find(SEP, prev);
        data.setAccountType(userData.substr(prev, pos - prev));
        prev = pos + 1;
		pos = userData.find(SEP, prev);
        data.SetIsFristLogin(string_to_bool(userData.substr(prev, pos - prev)));
		prev = pos + 1;
		data.setIsActive(string_to_bool(userData.substr(prev)));

        loginData.push_back(data);
        pos = 0;
        prev = 0;
    }
    return loginData;
}

//grap all clients data from text file ............
//this function will use it to print all clients information in employee window .. worth time to creat it :)
vector<Client> core::get_clients_data() {

    vector<Client> clientsData;
    vector<string> clientsAsStrings = read_a_file_to_vector_of_strings(CLIENTSFILE);
    size_t user_count = clientsAsStrings.size();

    string::size_type pos = 0;
    string::size_type prev = 0;

    for (int i = 0; i < user_count; i++)
    {
        Client client;
        string clientData = clientsAsStrings.at(i);
        pos = clientData.find(SEP, prev);
        //Get client ID as String then convert it to Long
        string clientID = clientData.substr(prev, pos - prev);
        client.setClientAccountId(stoll(clientID));
        prev = pos + 1;
        pos = clientData.find(SEP, prev);
        client.setClientFullName(clientData.substr(prev, pos - prev));
        prev = pos + 1;
        pos = clientData.find(SEP, prev);
        //get client blance as String then convert it to Long
        string clientBlance = clientData.substr(prev, pos - prev);
        client.setClientBlance(stoll(clientBlance));
        prev = pos + 1;

        //pos = clientData.find(SEP, prev);
        client.setClientLoginUsername(clientData.substr(prev));




        clientsData.push_back(client);
        pos = 0;
        prev = 0;
    }


    return clientsData;
}
// grab client data from clients data ......
int core::get_client_index(LoginData& userLoginData, vector<Client>& clientsData){

    size_t clients_count = clientsData.size();

    for (int i = 0; i < clients_count; i++) {

        if (userLoginData.getLoginuser() == clientsData.at(i).getClientUsername()) {
            return i;
        }    
    }
	return -1;
}

//////////////////////////////////////////////////////////////////////////
int core::wait_user_input() {
    string theInput;
    int i = 1;
	cin.clear();
    int inputAsInt = get_input_to_digit(theInput, i);

    while (cin.fail() || cin.eof() || inputAsInt == -1 || theInput.find_first_not_of("0123456789") != std::string::npos) {
        cin.clear();
		cout << "INVALID INPUT\nEnter your choice: ";
        inputAsInt = get_input_to_digit(theInput, i);
    }
    return  inputAsInt;

}
long long core::wait_user_input(string errorMessage) {
    string theInput;
    long l = 1;
    long long inputAsLong = get_input_to_digit(theInput, l);

    while (cin.fail() || cin.eof() || inputAsLong == -1 || theInput.find_first_not_of("0123456789") != std::string::npos) {
        
        cout << errorMessage;
        cin.clear();
        inputAsLong = get_input_to_digit(theInput, l);
    }
    return  inputAsLong;
}

int core::get_input_to_digit(string& selection, int i)
{
    getline(cin, selection, '\n');
    return string_to_int(selection);

}
long long core::get_input_to_digit(string& selection, long l)
{
    getline(cin, selection, '\n');
    return string_to_long(selection);

}

int core::string_to_int(string& s)
{
    int ret;
    try {
        ret = stoi(s, nullptr);
    }
    catch (...)
    {
        ret = -1;
    }
    return ret;
}

long long core::string_to_long(string& s)
{
    long long ret;
    try {
        ret = stoll(s);
    }
    catch (...)
    {
        ret = -1;
    }
    return ret;
}

string core::set_login_username(string& fullName) {
    string clientLoginUsername;
    clientLoginUsername = fullName[0];
    string::size_type pos = 0;
    string::size_type prev = 0;
    pos = fullName.find(" ", prev);
    prev = pos + 1;
    pos = fullName.find(" ", prev);
    clientLoginUsername += fullName.substr(prev, pos - prev);
    clientLoginUsername += to_string(fullName.size());

    return clientLoginUsername;
}

void core::saveDataToClients(string fileName, vector<Client> clients) {

    ofstream myfile(fileName);
    string lineOfData;
    if (myfile.is_open())
    {
        for(int i = 0; i < clients.size(); i++)
        {
            lineOfData = clients.at(i).getClientId() + SEP;
            lineOfData += clients.at(i).getClientFullName() + SEP;
            lineOfData += clients.at(i).getClientBlance() + SEP;
            lineOfData += clients.at(i).getClientUsername();
            myfile << lineOfData << endl;
        }
        myfile.close();
    }
}

void core::saveDataToUsers(string fileName, vector<LoginData> loginData) {

	ofstream myfile(fileName);
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




void core::set_account_type(int& t)
{
    account_type = t;
}

int core::get_account_type()
{
    return account_type;
}

void core::editClientInformation(vector<Client>& clientsData, Client& currentClient, int& clientIndex) {
	cout << "1- Edit client name" << endl;
	cout << "2- Reset password" << endl;
	cout << "3- Disable client" << endl;
	cout << "4 -Return to main menu" << endl;
	cout << "5- exit" << endl;
	cout << "Your choice: ";
	
	int selected_option = checkSelectionRange(4);
	switch (selected_option)
	{
	case 1:
		editClientName(clientsData, currentClient, clientIndex);
		break;
	case 2:
		resetPassword(currentClient.getClientId());
		break;
	case 3:

	case 4:
		return;
		break;
	case 5:
		exit(0);
		break;
	}
}

void core::editClientName(vector<Client>& clientsData, Client& currentClient, int& clientIndex) {
	cout << "This client name is: " << currentClient.getClientFullName() << endl;
	cout << "please enter the new name: ";
	string newName;
	cin.clear();
	getline(cin, newName);

	system("cls");

	cout << "Client infrormation after changed: " << endl;
	cout << newName << endl ;
	cout << currentClient.getClientId() << endl;

	if (areYouSure()) {
		// save new data to clients list 
		currentClient.setClientFullName(newName);
		clientsData.at(clientIndex) = currentClient;
		saveDataToClients(CLIENTSFILE, clientsData);
	}
	else {
		return;
	}
	return;
}

void core::resetPassword(string ID) {
	cout << "Will reset user password to defult password \"asd123\"" << endl;
	if (areYouSure()) {
		vector<LoginData> loginData = get_login_creditentials();
		for (size_t i = 0; i < loginData.size(); i++) {
			if (loginData.at(i).getID() == ID) {
				loginData.at(i).setLoginPassword("asd123");
				loginData.at(i).SetIsFristLogin(true);
				saveDataToUsers(USERSFILE, loginData);
				return;
			}
		}
	}
}

bool core::areYouSure() {
	bool sure = false;
	cout << "Are you sure to apply this changes :" << endl;
	cout << "1- Yes" << endl;
	cout << "2- No" << endl;
	cout << "Your Choice: ";
	int selected_option = checkSelectionRange(2);
	if (selected_option == 1) {
		sure = true;
		return true;
	}
	else{
		return sure;
	}
}

// Alwayes split functions to smaller functions its better :) 
int core::userReturnOExit() {
	cout << "press 1 to main menu  2 to exit" << endl;
	cout << "Choose: ";
	int i = checkSelectionRange(2);
	if (i == 2) {
		exit(0);
	}
	else {
		return i;
	}
}
// to print account full information ...
// 
void core::fullAccountInfo(Client& currentClient) {
	currentClient.printClientInf();
	userReturnOExit();
}
// to print account blance ...
int core::showAccountBlance(Client& currentclient) {
    system("cls");
    cout << currentclient.getClientFullName() << endl;
    cout << "Your blance is: " << currentclient.getClientBlance() << endl << endl;
    cout << "press 1 to main menu  2 to exit" << endl;
    cout << "Choose: ";
    int i = wait_user_input();
    return i;
}
// to make a withdrawal ...
void core::Withdrawal(vector<Client>& clientsData, Client& currentClient, int index) {
    long long blance = stoll(currentClient.getClientBlance());
    string replaceThis = currentClient.getClientBlance();
    string replaceTO;
    string errorMessage = "Error";

    cout << "Your Curent Blance is: " << blance << endl;
    cout << "Please enter amount of money you want to withdraw: ";
    long long amount = wait_user_input(errorMessage) ;
    while (amount > blance) {
        amount = wait_user_input(errorMessage);
    }
    blance -= amount;
    replaceTO = to_string(blance);
    
    currentClient.setClientBlance(blance);
    clientsData.at(index) = currentClient;
    saveDataToClients(CLIENTSFILE, clientsData);
}
//Deposite money to account ... 
void core::Deposite(vector<Client>& clientsData, Client& currentClient, int index) {
	long long depositeAmount;
	long long blance = stoll(clientsData.at(index).getClientBlance());
	string error = "INVALID INPUT Please enter digits only \nEnter the amount you want to deposite: ";

	cout << "Please enter the amount you want to deposite: ";
	depositeAmount = wait_user_input(error);
	blance += depositeAmount;
	clientsData.at(index).setClientBlance(blance);
	saveDataToClients(CLIENTSFILE, clientsData);

}
// Transfer money from account to other ... 
void core::transferTo(vector<Client>& clientsData, Client& currentClient, int index) {
    long long blance = stoll(currentClient.getClientBlance());
    long long amountToTransfer;
    long long transferToId;
    int transferToIndex;
    string userInput;
    cout << "Your Curent Blance is: " << blance << endl;
    cout << "Please enter the amount of money you want to transfer: ";
    amountToTransfer = checkBlance(currentClient);
    transferToId = checkId(clientsData, transferToIndex);
}
// change account password will use it in the 3 sections of the program "Manager - employee - client " ...
void core::changeUserPassword(vector<LoginData>& loginData, LoginData& userLoginData, size_t index) {
	string newPassword;
	cout << "Please enter your new password: ";
	cin.clear();
	getline(cin, newPassword);
	userLoginData.setLoginPassword(newPassword);
	userLoginData.SetIsFristLogin(false);
	loginData.at(index) = userLoginData;

	//for (int i = 0; i < loginData.size(); i++) {
	//	if (loginData.at(i).getLoginuser() == userLoginData.getLoginuser()) {
	//		cout << userLoginData.getIsFristLogin() << endl;
	//	}
	//}
	saveDataToUsers(USERSFILE, loginData);
}

long long core::checkBlance(Client& currentClient) {
    long long amountToTransfer;
    string errorMessage ="Your entry is !INVALID PLEASE EMTER NUMBERS ONLY \nPlease enter the amount of money you want to transfer: ";
    amountToTransfer = wait_user_input(errorMessage);
    if (amountToTransfer > stoll((currentClient.getClientBlance()))) {
        cout << "Your Curent Blance is: " << currentClient.getClientBlance() << endl;
        cout << "Your entry is greater than your blance\n";
        checkBlance(currentClient);
    } 

    return amountToTransfer;
}
long long core::checkId(vector<Client>& clientsData,int& index ){

    long long transferToId;
    string errorMessage = "Your entry is !INVALID PLEASE EMTER NUMBERS ONLY \nPlease enter account id that you want to transfer to: ";
    cout << "Please enter account id that you want to transfer to: ";
    transferToId = wait_user_input(errorMessage);
    for (int i = 0; i < clientsData.size(); i++) {
        if (stoll(clientsData[i].getClientId()) == transferToId) {
            index = i;
            return transferToId;
        }
    }
    cout << "INVLID ACCOUNT ID\n";
    checkId(clientsData, index);
}


bool core::string_to_bool(string s) {
    bool r = false;
    if (s == "true") {
        r = true;
    }
    else if (s == "false")  {
        r = false;
    }
    return r;
}
// ineed a girl like you yeah ya yeah ...
// myabe i know i drunk ... maybe i know you the one ...
string core::bool_to_string(bool b) {
    string r= "";
    if (b) {
        r = "true";
    }
    else if (!b) {
        r = "false";
    }
    return r;
}

int core::append2Clients(string& file_name, Client& new_client)
{
    ofstream myfile(file_name, ios::app);
    if (myfile.is_open())
    {
        myfile << new_client.getClientId() << SEP << new_client.getClientFullName() << SEP
            << new_client.getClientBlance() << SEP << new_client.getClientUsername() << endl;
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

int core::append2users(string& file_name, LoginData& loginData)
{
    ofstream myfile(file_name, ios::app);
    if (myfile.is_open())
    {
        myfile << loginData.getID() << SEP << loginData.getLoginuser() << SEP << loginData.getLoginPassword() << SEP
			<< loginData.getAccountType()<< SEP << bool_to_string(loginData.getIsFristLogin()) << SEP
			<< bool_to_string(loginData.getIsActive()) << endl;
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
// Good job ... dont be lazy :) <3 <3
int core::checkSelectionRange(int to) {
	int selection = wait_user_input();
	if (selection < 1 || selection > to) {
		cout << "Your selection is out of range\nEnter your choice: ";
		cin.clear();
		selection = wait_user_input();
	}
	else {
		return selection;
	}
}

//grap all clients data from text file ............
//this function will use it to print all clients information in employee window .. worth time to creat it :)
vector<Employee> core::getEmployeesData() {

	vector<Employee> employeesData;
	vector<string> employeesAsStrings = read_a_file_to_vector_of_strings(EMPLOYEEFILE);
	size_t user_count = employeesAsStrings.size();
	
	string::size_type pos = 0;
	string::size_type prev = 0;

	for (int i = 0; i < user_count; i++)
	{
		Employee employee;
		string employeeData = employeesAsStrings.at(i);
		pos = employeeData.find(SEP, prev);
		string employeeID = employeeData.substr(prev, pos - prev);
		employee.setID(stoi(employeeID));
		prev = pos + 1;

		pos = employeeData.find(SEP, prev);
		employee.setEmployeeName(employeeData.substr(prev, pos - prev));
		prev = pos + 1;

		pos = employeeData.find(SEP, prev);
		employee.setEmployeePostion(employeeData.substr(prev, pos - prev));
		prev = pos + 1;

		pos = employeeData.find(SEP, prev);
		string salary = employeeData.substr(prev, pos - prev);
		employee.setEmployeeSalary(stoi(salary));
		prev = pos + 1;

		pos = employeeData.find(SEP, prev);
		employee.setEmployeeAge(employeeData.substr(prev, pos - prev));
		prev = pos + 1;

		employee.setIsActive(string_to_bool(employeeData.substr(prev)));

		employeesData.push_back(employee);
		pos = 0;
		prev = 0;
	}
	return employeesData;
}

//This function to add a new client.
void core::addNewClient() {

	Client new_client;
	LoginData loginData;
	string new_client_fullname;
	string new_client_full_info;
	long clientId = 20000000;

	new_client_fullname = getFullName();
	new_client.setClientFullName(new_client_fullname);

	new_client.setClientLoginUsername(set_login_username(new_client_fullname));
	// set ID for this new client ....
	if (text_is_empty(CLIENTSFILE)) {
		new_client.setClientAccountId(clientId); //if this client is the frist client in the bank
	}
	else {

		clientId = get_last_ID(CLIENTSFILE);
		clientId += 1;
		new_client.setClientAccountId(clientId);
	}

	string errorMessage = "Entry must be a number \nPlease enter account opening blance: ";
	cout << "Please enter account opening blance: ";
	long long blance = wait_user_input(errorMessage);
	if (blance < 5000) {
		system("cls");
		cout << "opening blance must be 5000 " << endl;
		cout << "Please enter account opening blance: ";
		long long blance = wait_user_input(errorMessage);
	}
	new_client.setClientBlance(blance);
	new_client.printClientInf();


	if (areYouSure()) {
		string s = to_string(clientId);
		loginData.setID(s);
		loginData.setAccountType("0");
		loginData.setLoginUser(new_client.getClientUsername());
		loginData.SetIsFristLogin(true);
		loginData.setIsActive(true);
		append2Clients(CLIENTSFILE, new_client);
		append2users(USERSFILE, loginData);
	}
	else {
		return;
	}
}

string core::getFullName() {
	string fullName;
	cout << "Enter client full name: ";
	fullName = cheackStringNotHasNumbers();
	return fullName;
}
string core::getString(string message) {
	string s;
	cout << message ;
	s = cheackStringNotHasNumbers();
	return s;
}

string core::cheackStringNotHasNumbers() {

	string theInput;
	string errorMessage = "Your input is invalid\nEnter client full name: ";
	 
	cin.clear();
	getline(cin, theInput);

	while (cin.fail() || cin.eof() || theInput.find_first_of("0123456789") != std::string::npos) {
		cout << errorMessage;
		cin.clear();
		getline(cin, theInput);
	}
	return  theInput;
}

string core::stringAddPadding(string s, rsize_t count) {
	s.resize(count, ' ');
	return s;
}

//This function to add a new client.
void core::addNewEmployee(vector<Employee>& employeesData) {

	Employee newEmployee;
	LoginData loginData;
	string employee_fullname;
	long employeeID = 1000;

	employee_fullname = getFullName();
	newEmployee.setEmployeeName(employee_fullname);

	string loginUserName = set_login_username(employee_fullname);

	// set ID for this new client ....
	if (text_is_empty(EMPLOYEEFILE)) {
		newEmployee.setID(employeeID); //if this client is the frist client in the bank
	}
	else {
		employeeID = get_last_ID(EMPLOYEEFILE);
		employeeID += 1;
		newEmployee.setID(employeeID);
	}

	string errorMessage = "Entry must be a number \nPlease enter employee salary: ";
	cout << "Please enter employee salary: ";
	int salary = wait_user_input(errorMessage);
	if (salary < 5000) {
		system("cls");
		cout << "slary must be 5000 or higher" << endl;
		cout << "Please enter employee blance: ";
		salary = wait_user_input(errorMessage);
	}
	newEmployee.setEmployeeSalary(salary);

	errorMessage = "Entry must be a number \nPlease Employee age: ";
	cout << "Please enter employee age: ";
	int age = wait_user_input(errorMessage);
	newEmployee.setEmployeeAge(to_string(age));
	
	system("cls");

	newEmployee.printEmployeeInf();
	if (areYouSure()) {
		string s = to_string(employeeID);
		loginData.setID(s);
		loginData.setAccountType("1");
		loginData.setLoginUser(loginUserName);
		loginData.SetIsFristLogin(true);
		append2employee(newEmployee);
		append2users(USERSFILE, loginData);
		employeesData.push_back(newEmployee);
	}
	else {
		return;
	} 
}

int core::append2employee(Employee employee)
{
	ofstream myfile(EMPLOYEEFILE, ios::app);
	if (myfile.is_open())
	{
		myfile << employee.getID() << SEP;
		myfile << employee.getEmployeeName() << SEP;
		myfile << employee.getEmployeePostion() << SEP;
		myfile << employee.getEmployeeSalary() << SEP;
		myfile << employee.getEmployeeAge() << SEP;
		myfile << bool_to_string(employee.getIsFristLogin()) << endl;

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

void core::editEmployeeInformation(vector<Employee>& employeesData, Employee currentEmployee, size_t index) {
	cout << "1- Edit Employee" << endl;
	cout << "2- Reset password" << endl;
	cout << "3 -Return to main menu" << endl;
	cout << "4- exit" << endl;
	cout << "Your choice: ";

	int selected_option = checkSelectionRange(4);
	switch (selected_option)
	{
	case 1:
		editEmployee(employeesData, currentEmployee, index);
		break;
	case 2:
		resetPassword(currentEmployee.getID());
		break;
	case 3:
		return;
		break;
	case 4:
		exit(0);
		break;
	}
}

void core::editEmployee(vector<Employee>& employeesData, Employee currentEmployee, size_t index) {
	system("cls");
	currentEmployee.printEmployeeInf();

	if (!currentEmployee.getIsActive()) {

	
	}
	 else {

		cout << "1- Edit name" << endl;
		cout << "2- Edit postion" << endl;
		cout << "3- Edit salary" << endl;
		cout << "4- Terminate" << endl;
		cout << "5- Return to main Menu" << endl;
		cout << "6- Main menu" << endl;
		cout << "Your choice: ";

		int selected_option = checkSelectionRange(6);
		string s;
		string message;
		switch (selected_option)
		{
		case 1:
		s = getFullName();
		if (areYouSure()) {
			currentEmployee.setEmployeeName(s);
			employeesData.at(index) = currentEmployee;
			saveAndAppend.saveDataToEmployees(employeesData);
		}
		break;
		case 2:
		message = "Please enter employee new postion: ";
		s = getString(message);
		system("cls");
		currentEmployee.printEmployeeInf();
		if (areYouSure()) {
			currentEmployee.setEmployeePostion(s);
			employeesData.at(index) = currentEmployee;
			saveAndAppend.saveDataToEmployees(employeesData);
		}
		break;
		case 3:
			vector<LoginData>  *ddd = employeesData (LoginData);
			disableUser(employeesData, currentEmployee, index)
		case 4:

		break;
		case 5:
		exit(0);
		break;
		}
		editEmployee(employeesData, currentEmployee, index);
	}
}



void core::disableUser(vector<LoginData> *data, LoginData userData, size_t index) {
	//cout << "Disabling this user " << userLoginData.getLoginuser() << endl;
	
	if (areYouSure()) {
		vector<LoginData> loginData = get_login_creditentials();
		for (size_t i = 0; i < loginData.size(); i++) {

			if (loginData.at(i).getID() == userData.getID()) {

				loginData.at(i).setIsActive(false);
				saveDataToUsers(USERSFILE, loginData);

				size_t userToDiableID = stoll(data->at(index).getID());

				

				if (userData.getAccountType() == to_string(0)) {


				}
				if (userData.getAccountType() == to_string(1)) {
				}
				return;
			}
		}
	}
}
void core::disableEmployeeProcesses(vector<LoginData>* data) {



	//vector<Employee> allEmployees = getEmployeesData();
	//allEmployees.at(index).setIsActive(false);
	//allEmployees.at(index).setEmployeeSalary(0);

	//saveAndAppend.saveDataToEmployees(allEmployees);

	return;
}


void core::accountIsDisable() {
	cout << "This account is disabled \nPlease contact tecnical support for more information " << endl;
	exit(0);
}