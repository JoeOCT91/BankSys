#pragma once
#include <string>

using namespace std;
class Group{

private:
	string mGroupname;
	int groupManagerID;

public:
	void setGroupName(string groupName) {
		mGroupname = groupName;
	}
};

