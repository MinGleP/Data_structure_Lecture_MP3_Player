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

// �� �帣�� ��
RelationType MusicGenre::CompareByKey(const MusicGenre &data)
{
	if (this->genre > data.genre)
		return RelationType::GREATER;
	else if (this->genre < data.genre)
		return RelationType::LESS;
	else
		return RelationType::EQUAL;
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