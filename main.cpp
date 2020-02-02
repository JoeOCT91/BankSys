#include <iostream>
#include "gui.h"

using namespace std;

int main()
{
    vector<LoginData> loginData = parsingLoginData();
    loginCheak(loginData);

}
