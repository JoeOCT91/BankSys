#include <iostream>
#include "banks
using namespace std;

int main()
{
    vector<LoginData> loginData = parsingLoginData();
    loginCheak(loginData);
    employeeWindow();
}
