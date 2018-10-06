#include "MusicGenre.h"

// 디폴트 생성자
MusicGenre::MusicGenre() {}

// 생성자
MusicGenre::MusicGenre(string inGenre, int inSongNumber) {
	genre = inGenre;
	songNumber = inSongNumber;
}

//	음악 번호 리턴
int MusicGenre::getSongNumber() {
	return songNumber;
}

//	음악 장르 리턴
string MusicGenre::getGenre() const {
	return genre;
}

// 두 장르를 비교
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