#ifndef _PLAYLISTINFO_H
#define _PLAYLISTINFO_H
#include<string>
#include<iostream>
using namespace std;

class PlayListInfo {
public:
	PlayListInfo();
	PlayListInfo(string, string);

	string getName() const;

	string getTitle() const;

	void setName(string);

	void setTitle(string);

private:
	string title;
	string name;
};
#endif // _PLAYLISTINFO_H