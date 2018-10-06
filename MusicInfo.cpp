#include "MusicInfo.h"


void MusicInfo::SetSongNumFromKB() {
	cout << "\tSong Number : ";
	cin >> songNum;
}

// Set music title from keyboard.
void MusicInfo::SetTitleFromKB()
{
	cout << "\tTitle : ";
	cin >> title;
}


// Set singer name from keyboard.
void MusicInfo::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> name;
}


// Set music album from keyboard.
void MusicInfo::SetAlbumFromKB()
{
	cout << "\tAlbum : ";
	cin >> album;
}

// Set music genre from keyboard.
void MusicInfo::SetGenreFromKB()
{
	cout << "\tGenre : ";
	cin >> genre;
}

// Set music lyrics from keyboard.
void MusicInfo::SetLyricsFromKB()
{
	cout << "\tLyrics : ";
	cin.ignore(1);
	getline(cin, lyrics); // 띄어쓰기까지 입력하기 위함
}

// Set music record from keyboard.
void MusicInfo::SetRecordFromKB()
{
	SetSongNumFromKB();
	SetTitleFromKB();
	SetNameFromKB();
	SetAlbumFromKB();
	SetGenreFromKB();
	SetLyricsFromKB();
}


// Read a record from file.
int MusicInfo::ReadDataFromFile(ifstream& fin)
{
	fin >> songNum;
	fin >> title;
	fin >> name;
	fin >> album;
	fin >> genre;
	fin >> lyrics;

	return 1;
};


// Write a record into file.
int MusicInfo::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << songNum << " ";
	fout << title << " ";
	fout << name << " ";
	fout << album << " ";
	fout << genre << " ";
	fout << lyrics;

	return 1;
}


// Compare two MusicInfos.
RelationType MusicInfo::CompareByKey(const MusicInfo &data)
{
	if(this->songNum > data.songNum)
		return RelationType::GREATER;
	else if(this->songNum < data.songNum)
		return RelationType::LESS;
	else
		return RelationType::EQUAL;
}

bool MusicInfo::operator==(const MusicInfo &obj) {
	if (songNum == obj.GetSongNumber()) {
		return true;
	}
	return false;
}
bool MusicInfo::operator>(const MusicInfo &obj) {
	if (songNum > obj.GetSongNumber()) {
		return true;
	}
	return false;
}
bool MusicInfo::operator<(const MusicInfo &obj) {
	if (songNum < obj.GetSongNumber()) {
		return true;
	}
	return false;
}
bool MusicInfo::operator>=(const MusicInfo &obj) {
	if (songNum >= obj.GetSongNumber()) {
		return true;
	}
	return false;
}
bool MusicInfo::operator<=(const MusicInfo &obj) {
	if (songNum <= obj.GetSongNumber()) {
		return true;
	}
	return false;
}