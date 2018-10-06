#include "SimpleMusicInfo.h"

SimpleMusicInfo::SimpleMusicInfo() {
	songNum = 0;
	title = "";
}
SimpleMusicInfo::SimpleMusicInfo(int songNum, string title) {
	this->songNum = songNum;
	this->title = title;
}

int SimpleMusicInfo::getSongNum() const {
	return songNum;
}

string SimpleMusicInfo::getTitle() const {
	return title;
}

void SimpleMusicInfo::setSongNum(int songNum) {
	this->songNum = songNum;
}

void SimpleMusicInfo::setTitle(string title) {
	this->title = title;
}

bool SimpleMusicInfo::operator==(const SimpleMusicInfo &obj) {
	if (songNum == obj.getSongNum()) {
		return true;
	}
	return false;
}
bool SimpleMusicInfo::operator>(const SimpleMusicInfo &obj) {
	if (songNum > obj.getSongNum()) {
		return true;
	}
	return false;
}
bool SimpleMusicInfo::operator<(const SimpleMusicInfo &obj) {
	if (songNum < obj.getSongNum()) {
		return true;
	}
	return false;
}
bool SimpleMusicInfo::operator>=(const SimpleMusicInfo &obj) {
	if (songNum >= obj.getSongNum()) {
		return true;
	}
	return false;
}
bool SimpleMusicInfo::operator<=(const SimpleMusicInfo &obj) {
	if (songNum <= obj.getSongNum()) {
		return true;
	}
	return false;
}