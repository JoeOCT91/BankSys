#include "core.h"


using namespace std;
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


            if (lineOfData != "") {
                vector_of_strings.push_back(lineOfData);
            }



            //file >> lineOfData;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file: " << fileName << endl;
    }
    cout << vector_of_strings.size() << endl;
    return vector_of_strings;
}


bool core::text_is_empty() {
    int length;
    ifstream myfile;

    myfile.open("clients.txt", ios::binary); // open your file
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
string core::get_last_line_in_text_file() {

    ifstream fin;
    fin.open(CLIENTSFILE);
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
                fin.seekg(-2, ios_base::cur);        // Move to the front of that data, then to the front of the data before it
            }
        }

        string lastLine;
        getline(fin, lastLine);                      // Read the current line
        
        fin.close();
        return lastLine;
    }

    else {
        cout << "Clients.txt faild to open" << endl;
        return 0;
    } 
}

// To extratct client id from a string 
long core::get_last_Client_ID() {
    string lastLine = get_last_line_in_text_file();
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
        data.setLoginUser(userData.substr(prev, pos - prev));
        prev = pos + 1;
        pos = userData.find(SEP, prev);
        data.setLoginPassword(userData.substr(prev, pos - prev));
        prev = pos + 1;
        pos = userData.find(SEP, prev);
        data.setAccountType(userData.substr(prev, pos - prev));
        prev = pos + 1;
        data.SetIsFristLogin(string_to_bool(userData.substr(prev)));
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
        pos = clientData.find(SEP, prev);
        client.setClientLoginUsername(clientData.substr(prev));
        prev = pos + 1;
        int isLogin = stoi(clientData.substr(prev));
        client.setFristLogin(isLogin);


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
}


//////////////////////////////////////////////////////////////////////////
int core::wait_user_input() {
    string theInput;
    int i = 1;
    int inputAsInt = get_input_to_digit(theInput, i);

    while (cin.fail() || cin.eof() || inputAsInt == -1 || theInput.find_first_not_of("0123456789") != std::string::npos) {
        cin.clear();
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




LoginData core::changeUssrPassword(LoginData userLoginData) {
    string oldPassword = userLoginData.getLoginPassword();
    string newPassword;
    cout << "Please enter your new password: ";
    cin.clear();
    cin.ignore();
    getline(cin, newPassword);
    userLoginData.setLoginPassword(newPassword);
    userLoginData.SetIsFristLogin(false);
    // rewrite this user data to USERS.txt in the same line by replacing the old line,
    // line start with LOGINUSERNAME >> will find it then replace it 
    // need to creat function that read text file then replace the line;
    read_text_file_then_replace_a_line(USERSFILE, userLoginData.getLoginuser(), oldPassword, newPassword);
    return userLoginData;
}


void core::read_text_file_then_replace_a_line(string fileName, string searchFor, string replaceThis, string replaceTo) {
    
    char file_name[20];
    strcpy_s(file_name, fileName.c_str());

    ifstream file(fileName);
    ofstream TEMPFILE("temp.txt", ios_base::app);
    string lineOfStream;
    if (file.is_open())
    {
        while (getline(file, lineOfStream))
        {
            

            if (lineOfStream.find(searchFor) != std::string::npos) {
                
                lineOfStream.replace(lineOfStream.find(replaceThis), replaceThis.length(), replaceTo);

            }

            TEMPFILE << lineOfStream << endl;
        
        }
        file.close();
        TEMPFILE.close();
        remove(file_name);
        rename("temp.txt", file_name);

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



int core::showAccountBlance(Client& currentclient) {
    system("cls");
    cout << currentclient.getClientFullName() << endl;
    cout << "Your blance is: " << currentclient.getClientBlance() << endl << endl;
    cout << "press 1 to main menu  2 to exit" << endl;
    cout << "Choose: ";
    int i = wait_user_input();

    return i;

}

void core::Withdrawal(vector<Client>& clientsData, Client& currentClient, int index) {


    long long blance = stoll(currentClient.getClientBlance());
    string replaceThis = currentClient.getClientBlance();
    string replaceTO;

    string errorMessage = "Error";

    cout << blance << endl;
    cout << "Please enter amount of money you want to withdraw: ";
    long long amount = wait_user_input(errorMessage) ;
    while (amount > blance) {
        amount = wait_user_input(errorMessage);
    }
    blance -= amount;
    replaceTO = to_string(blance);
    
    read_text_file_then_replace_a_line(CLIENTSFILE, currentClient.getClientUsername(), replaceThis, replaceTO);
    currentClient.setClientBlance(blance);
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
        myfile << endl <<new_client.getClientId() << SEP << new_client.getClientFullName() << SEP
            << new_client.getClientBlance() << SEP << new_client.getClientUsername() << new_client.isFristLogin();
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
        myfile << endl << loginData.getLoginuser() << SEP << loginData.getLoginPassword() << SEP << loginData.getAccountType()
            << SEP << bool_to_string(loginData.getIsFristLogin()) ;
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