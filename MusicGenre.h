#ifndef _MUSICGENRE_H
#define _MUSICGENRE_H
#include <string>
#include<iostream>
using namespace std;

/**
*	Genre Info class.
*/
class MusicGenre {
public:

	/**
	*	default constructor.
	*/
	MusicGenre();

	/**
	*	constructor.
	*/
	MusicGenre(string, int);

	/**
	*	destructor.
	*/
	~MusicGenre() {}
	
	/**
	*	@brief	Get genre.
	*	@pre	music genre is set.
	*	@post	none.
	*	@return	music genre.
	*/
	string getGenre() const;

	/**
	*	@brief	Get song number.
	*	@pre	music song number is set.
	*	@post	none.
	*	@return	music song number.
	*/
	int getSongNumber();

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
	*	@brief	Display an genre record on screen.
	*	@pre	music record is set.
	*	@post	music record is on screen.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayGenreOnScreen();
	};

	bool operator==(const MusicGenre &obj);
	bool operator>(const MusicGenre &obj);
	bool operator<(const MusicGenre &obj);
	bool operator>=(const MusicGenre &obj);
	bool operator<=(const MusicGenre &obj);

protected:
	string genre;
	int songNumber;
};
#endif	// _MUSICGENRE_H