#ifndef _MUSICINFO_H
#define _MUSICINFO_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
*	item information class.
*/
class MusicInfo
{
public:
	/**
	*	default constructor.
	*/
	MusicInfo()
	{
		songNum = 0;
		title = "";
		name = "";
		album = "";
		genre = "";
		lyrics = "";
	}

	/**
	*	destructor.
	*/
	~MusicInfo() {}

	int GetSongNumber() const {
		return songNum;
	}

	/**
	*	@brief	Get music title.
	*	@pre	music title is set.
	*	@post	none.
	*	@return	music title.
	*/
	string GetTitle()
	{
		return title;
	}

	/**
	*	@brief	Get singer name.
	*	@pre	singer name is set.
	*	@post	none.
	*	@return	singer name.
	*/
	string GetName()
	{
		return name;
	}

	/**
	*	@brief	Get music album
	*	@pre	music album is set.
	*	@post	none.
	*	@return	music album.
	*/
	string GetAlbum()
	{
		return album;
	}

	/**
	*	@brief	Get music genre.
	*	@pre	music genre is set.
	*	@post	none.
	*	@return	music genre.
	*/
	string GetGenre() {
		return genre;
	}

	/**
	*	@brief	Get music lyrics.
	*	@pre	music lyrics is set.
	*	@post	none.
	*	@return	music lyrics.
	*/
	string GetLyrics() {
		return lyrics;
	}


	void SetSongNum(int inSongNum)
	{
		songNum = inSongNum;
	}

	/**
	*	@brief	Set music title.
	*	@pre	none.
	*	@post	music title is set.
	*	@param	music title.
	*/
	void SetTitle(string inTitle)
	{
		title = inTitle;
	}

	/**
	*	@brief	Set singer name.
	*	@pre	none.
	*	@post	singer name is set.
	*	@param	singer name.
	*/
	void SetName(string inName)
	{
		name = inName;
	}

	/**
	*	@brief	Set music album.
	*	@pre	none.
	*	@post	music album is set.
	*	@param	music album.
	*/
	void SetAlbum(string inAlbum)
	{
		album = inAlbum;
	}

	/**
	*	@brief	Set music genre.
	*	@pre	none.
	*	@post	music genre is set.
	*	@param	music genre.
	*/
	void SetGenre(string inGenre) {
		genre = inGenre;
	}

	/**
	*	@brief	Set music lyrics.
	*	@pre	none.
	*	@post	music lyrics is set.
	*	@param	music lyrics.
	*/
	void SetLyrics(string inLyrics) {
		lyrics = inLyrics;
	}
	/**
	*	@brief	Set music record.
	*	@pre	none.
	*	@post	music record is set.
	*	@param	inTitle music title.
	*	@param	inName	singer name.
	*	@param	inAlbum	music album.
	*	@param	inGenre	music genre.
	*	@param inLyrics music lyrics.
	*/
	void SetRecord(int inSongNum, string inTitle, string inName, string inAlbum, string inGenre, string inLyrics)
	{
		SetSongNum(inSongNum);
		SetTitle(inTitle);
		SetName(inName);
		SetAlbum(inAlbum);
		SetGenre(inGenre);
		SetLyrics(inLyrics);
	}

	void DisplaySongNumOnScreen()
	{
		cout << "\tSongNumber   : " << songNum << endl;
	};

	/**
	*	@brief	Display music title on screen.
	*	@pre	music title is set.
	*	@post	music title is on screen.
	*/
	void DisplayTitleOnScreen()
	{
		cout << "\tTitle   : " << title << endl;
	};

	/**
	*	@brief	Display singer name on screen.
	*	@pre	singer name is set.
	*	@post	singer name is on screen.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName : " << name << endl;
	};

	/**
	*	@brief	Display music album on screen.
	*	@pre	music album is set.
	*	@post	music album is on screen.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\tAlbum : " << album << endl;
	};

	/**
	*	@brief	Display music genre on screen.
	*	@pre	music genre is set.
	*	@post	music genre is on screen.
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\tGenre: " << genre << endl;
	};

	/**
	*	@brief	Display music lyrics on screen.
	*	@pre	music lyrics is set.
	*	@post	music lyrics is on screen.
	*/
	void DisplayLyricsOnScreen()
	{
		cout << "\tLyrics : " << lyrics << endl;
	};

	/**
	*	@brief	Display an music record on screen.
	*	@pre	music record is set.
	*	@post	music record is on screen.
	*/
	void DisplayRecordOnScreen()
	{
		DisplaySongNumOnScreen();
		DisplayTitleOnScreen();
		DisplayNameOnScreen();
		DisplayAlbumOnScreen();
		DisplayGenreOnScreen();
		DisplayLyricsOnScreen();
	};

	void SetSongNumFromKB();

	/**
	*	@brief	Set music title from keyboard.
	*	@pre	none.
	*	@post	music title is set.
	*/
	void SetTitleFromKB();

	/**
	*	@brief	Set singer name from keyboard.
	*	@pre	none.
	*	@post	singer name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set music album from keyboard.
	*	@pre	none.
	*	@post	music album is set.
	*/
	void SetAlbumFromKB();

	/**
	*	@brief	Set music genre from keyboard.
	*	@pre	none.
	*	@post	music genre is set.
	*/
	void SetGenreFromKB();

	/**
	*	@brief	Set music lyrics from keyboard.
	*	@pre	none.
	*	@post	music lyrics is set.
	*/
	void SetLyricsFromKB();

	/**
	*	@brief	Set music record from keyboard.
	*	@pre	none.
	*	@post	music record is set.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	music record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new music record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);

	bool operator==(const MusicInfo &obj);
	bool operator>(const MusicInfo &obj);
	bool operator<(const MusicInfo &obj);
	bool operator>=(const MusicInfo &obj);
	bool operator<=(const MusicInfo &obj);


protected:
	int songNum;
	string title;
	string name;
	string album;
	string genre;
	string lyrics;
};

#endif	// _MUSICINFO_H
