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
            file >> lineOfData;
            vector_of_strings.push_back(lineOfData);
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file: " << fileName << endl;
    }
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
    lastId = stol(s);

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
        data.setAccountType(userData.substr(prev));

        loginData.push_back(data);
        pos = 0;
        prev = 0;
    }
    return loginData;
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


long core::string_to_long(string& s)
{
    long ret;
    try {
        ret = stol(s);
    }
    catch (...)
    {
        ret = -1;
    }
    return ret;
}


int core::get_selection_to_int(string& selection)
{
    getline(cin, selection, '\n');
    return string_to_int(selection);

}
int core::wait_user_input() {
    string theInput;

    int inputAsInt = get_selection_to_int(theInput);

    while (cin.fail() || cin.eof() || inputAsInt == -1 || theInput.find_first_not_of("0123456789") != std::string::npos) {
        cin.clear();
        inputAsInt = get_selection_to_int(theInput);
    }
    return  inputAsInt;

}




long core::get_blance_to_long(string& selection)
{
    getline(cin, selection, '\n');
    return string_to_long(selection);

}
long core::wait_blance_input() {
    string theInput;

    long inputAsLong = get_blance_to_long(theInput);

    while (cin.fail() || cin.eof() || inputAsLong == -1 || theInput.find_first_not_of("0123456789") != std::string::npos) {
        cin.clear();
        inputAsLong = get_blance_to_long(theInput);
    }
    return  inputAsLong;

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















void core::set_account_type(int& t)
{
    account_type = t;
}

int core::get_account_type()
{
    return account_type;
}

int core::append2Clients(string& file_name, Client& new_client)
{
    ofstream myfile(file_name, ios::app);
    if (myfile.is_open())
    {
        myfile << new_client.getClientId() << SEP << new_client.getClientFullName() << SEP << new_client.getClientBlance() <<endl;
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

int core::append2users(string& file_name, Client& new_client)
{
    ofstream myfile(file_name, ios::app);
    if (myfile.is_open())
    {
        myfile << SEP << endl;
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

