#include "PlayListInfo.h"

PlayListInfo::PlayListInfo() {
	name = "";
	title = "";
}
PlayListInfo::PlayListInfo(string title,string name) {
	this->name = name;
	this->title = title;
}

string PlayListInfo::getName() const {
	return name;
}

string PlayListInfo::getTitle() const {
	return title;
}

void PlayListInfo::setName(string name) {
	this->name = name;
}

void PlayListInfo::setTitle(string title) {
	this->title = title;
}
