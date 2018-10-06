#ifndef _USER_H
#define _USER_H
#include "ArrayList.h"
using namespace std;

class User {

private:
	string id;
	string password;
	int Max = 3;
	int length;
	ArrayList<PlayListInfo> *m_playlist = new ArrayList<PlayListInfo>[Max];

public:
	User();
	User(string, string);

	void setPassword(string);
	string getId();

	//void add();
	//void del();

};


#endif //_USER_H