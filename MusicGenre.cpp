#include "MusicGenre.h"

// ����Ʈ ������
MusicGenre::MusicGenre() {}

// ������
MusicGenre::MusicGenre(string inGenre, int inSongNumber) {
	genre = inGenre;
	songNumber = inSongNumber;
}

//	���� ��ȣ ����
int MusicGenre::getSongNumber() {
	return songNumber;
}

//	���� �帣 ����
string MusicGenre::getGenre() const {
	return genre;
}

bool MusicGenre::operator==(const MusicGenre &obj) {
	if (genre == obj.getGenre()) {
		return true;
	}
	return false;
}
bool MusicGenre::operator>(const MusicGenre &obj) {
	if (genre > obj.getGenre()) {
		return true;
	}
	return false;
}
bool MusicGenre::operator<(const MusicGenre &obj) {
	if (genre < obj.getGenre()) {
		return true;
	}
	return false;
}
bool MusicGenre::operator>=(const MusicGenre &obj) {
	if (genre >= obj.getGenre()) {
		return true;
	}
	return false;
}
bool MusicGenre::operator<=(const MusicGenre &obj) {
	if (genre <= obj.getGenre()) {
		return true;
	}
	return false;
}