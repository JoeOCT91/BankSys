#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include "client.h"
#include "LoginData.h"

using namespace std;
char SEP = ',';
/*void validateBlanceEntry(string blance) {
    string zsdd;
    int inputAsInt;

  //  std::getline(std::cin, theInput);

    while (std::cin.fail() || std::cin.eof() || theInput.find_first_not_of("0123456789") != std::string::npos) {

        std::cout << "Error" << std::endl;

        if (theInput.find_first_not_of("0123456789") == std::string::npos) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }

        std::getline(std::cin, theInput);
    }

    std::string::size_type st;
    inputAsInt = std::stoi(theInput, &st);
    std::cout << inputA
} */
vector<LoginData> parsingLoginData() {
    string fileName = "users.txt";
    vector<LoginData> loginData;
    vector<string> rawsOfLoginData;
    string lineOfData;

    ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            myfile >> lineOfData;
            rawsOfLoginData.push_back(lineOfData);
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    string::size_type pos = 0;
    string::size_type prev = 0;

    for (int i = 0; i < rawsOfLoginData.size(); i++)
    {
        LoginData data;
        string userData = rawsOfLoginData.at(i);
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




//This function to cheak the entery of user is an intger ,
int cheakInputIsInt() {
    string theInput;
    int inputAsInt = 0;

    std::getline(std::cin, theInput);

    while (std::cin.fail() || std::cin.eof() || theInput.find_first_not_of("0123456789") != std::string::npos) {

        std::cout << "Error" << std::endl;

        if (theInput.find_first_not_of("0123456789") == std::string::npos) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }

        std::getline(std::cin, theInput);
    }

    std::string::size_type st;
    inputAsInt = std::stoi(theInput, &st);
    std::cout << inputAsInt << std::endl;
    return inputAsInt;
}

void clientWindow() {
    cout << "Welcome you can manage your account from here" << endl;
    cout << "1- Account blance" << endl;
    cout << "2- Deposite" << endl;
    cout << "3- With";
}

void employeeWindow() {
    int choice;
    cout << "Welcome you can manage bank clients from here" << endl;
    cout << "1- Add new client" << endl;
    cout << "2- Edit existing account" << endl;
    cout << "3- " << endl;
    cout << "Enter your choice :";
    choice = cheakInputIsInt();

}
void managerWindow() {
    cout << "Welcome you can manage your account from here" << endl;
    cout << "1- Account blance" << endl;
    cout << "2- Deposite" << endl;
    cout << "3- With";
}

// this function to cheak login username and password then direct account acording to it type
int loginCheak(vector<LoginData>& loginData) {
    string username;
    string password;
    int accountType;
    cout << "Please enter your username: ";
    cin >> username;
    for (int i = 0; i < loginData.size(); i++) {
        if (username == loginData[i].getLoginuser()) {
            cout << "Please enter your password: ";
            cin >> password;
            while (password != loginData[i].getLoginPassword()) {
                cout << "INVALID PASSWORD RETRY" << endl;
                cout << "Enter your password Again: ";
                cin >> password;
            }
            accountType = stoi(loginData[i].getAccountType());
            switch (accountType)
            {
            case 0:
                system("cls");
                clientWindow();
                break;
            case 1:
                system("cls");
                employeeWindow();
                break;
            case 2:
                system("cls");
                managerWindow();
                break;
            default:
                break;
            }
        }

    }
    return 0;
}
int addClient() {
    string clientFullName;
    Client client;

    cout << "Client full name: ";
    getline(cin, clientFullName);
    client.setClientFullName(clientFullName);
    client.setClientLoginUsername(clientFullName);
    cout << "The password set by default to asd123" << endl;
    cout << "Enter account opening blance most be more the 5000LE";
    client.setClientBlance();
    cout << client.getClientUsername();
    return 0;
}



int main()
{

   vector<LoginData> loginData = parsingLoginData();
   loginCheak(loginData);
   employeeWindow();
   
  //  addClient();

   
}

