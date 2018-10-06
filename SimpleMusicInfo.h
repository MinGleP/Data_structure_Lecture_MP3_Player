#ifndef _SIMPLEMUSICINFO_H
#define _SIMPLEMUSICINFO_H
#include<string>
#include<iostream>
using namespace std;

class SimpleMusicInfo {
public:
	SimpleMusicInfo();
	SimpleMusicInfo(int,string);

	int getSongNum() const;

	string getTitle() const;

	void setSongNum(int);

	void setTitle(string);

	bool operator==(const SimpleMusicInfo &obj);
	bool operator>(const SimpleMusicInfo &obj);
	bool operator<(const SimpleMusicInfo &obj);
	bool operator>=(const SimpleMusicInfo &obj);
	bool operator<=(const SimpleMusicInfo &obj);

private:
	int songNum;
	string title;
};
#endif // _SIMPLEMUSICINFO_H