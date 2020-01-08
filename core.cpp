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


int core::get_selection_to_int(string& selection)
{
    getline(cin, selection, '\n');
    return string_to_int(selection);

}
int core::wait_user_input() {
    string theInput;

    int inputAsInt = get_selection_to_int(theInput);

    while (std::cin.fail() || std::cin.eof() || inputAsInt == -1 || theInput.find_first_not_of("0123456789") != std::string::npos) {
        cin.clear();
        inputAsInt = get_selection_to_int(theInput);
    }
    return  inputAsInt;

}

void core::set_account_type(int& t)
{
    account_type = t;
}

int core::get_account_type()
{
    return account_type;
}

