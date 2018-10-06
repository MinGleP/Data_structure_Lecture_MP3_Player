#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ArrayList.h"
#include "CircularQueueType.h"

#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
	}
	
	/**
	*	destructor.
	*/
	~Application()	{}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItem();

	/**
	*	@brief	Display recent music in the list on screen.
	*	@pre	music should have added in list.
	*	@post	Display recent music.
	*/
	void DisplayNewMusic();

	/**
	*	@brief	Display music by genre in the list on screen.
	*	@pre	music should have added in list.
	*	@post	Display music by genre.
	*/
	void DisplayMusicByGenre();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllItem();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/**
	*	@brief	����Ʈ���� �ش� ���� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchItemById();


	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� item�� ã�� ��ȯ�Ѵ�.
	*	@pre	���ڷ� �޴� MusicInfo�� �̸��� �ԷµǾ� �־�� �Ѵ�.
	*	@post	ã�� item�� ���ڷ� ���´�.
	*	@param	inData	�̸��� �Էµ� �ִ� MusicInfo��.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int RetriveRecordByMemberName();

	/**
	*	@brief	����Ʈ���� �ش� Ÿ��Ʋ�� �帣�� ���ÿ� ���� item�� ã�� ��ȯ�Ѵ�.
	*	@pre	���ڷ� �޴� MusicInfo�� �̸��� �帣�� �ԷµǾ� �־�� �Ѵ�.
	*	@post	ã�� item�� ���ڷ� ���´�.
	*	@param	inData	�̸��� �帣�� �Էµ� �ִ� MusicInfo��.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int RetriveRecordByTitleNGenre();

	/**
	*	@brief	����Ʈ���� �ش� �̸��� �帣�� ���ÿ� ���� item�� ã�� ��� ����Ѵ�.
	*	@pre	����.
	*	@post	ã�� ��� item�� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchListByTitleNGenre(MusicInfo &data);

	/**
	*	@brief	����Ʈ���� �ش� �̸��� ���� item�� ã�� ��� ����Ѵ�.
	*	@pre	����.
	*	@post	ã�� ��� item�� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchListByMemberName( MusicInfo &inData );

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� item�� �����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int DeleteItem();
	
	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� item�� ����ȴ�.
	*/
	int ReplaceItem();

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ����Ž���� �̿��� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ȭ�鿡 ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchItemByBinarySearch();

	/**
	*	@brief	����Ʈ���� �ش� ������ ���� item�� ã�� ��� ����Ѵ�.
	*	@pre	����.
	*	@post	ã�� ��� item�� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchListByTitle(MusicInfo &inData);

	/**
	*	@brief	����Ʈ���� �ش� �ٹ��� ���� item�� ã�� ��� ����Ѵ�.
	*	@pre	����.
	*	@post	ã�� ��� item�� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchListByAlbum(MusicInfo &inData);

	/**
	*	@brief	����Ʈ���� �ش� �帣�� ���� item�� ã�� ��� ����Ѵ�.
	*	@pre	����.
	*	@post	ã�� ��� item�� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchListByGenre(MusicInfo &inData);

	/**
	*	@brief	����Ʈ���� �ش� ������ ���� item�� ã�� ��ȯ�Ѵ�.
	*	@pre	���ڷ� �޴� MusicInfo�� ������ �ԷµǾ� �־�� �Ѵ�.
	*	@post	ã�� item�� ���ڷ� ���´�.
	*	@param	inData	������ �Էµ� �ִ� MusicInfo��.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int RetriveRecordByTitle();

	/**
	*	@brief	����Ʈ���� �ش� �ٹ��� ���� item�� ã�� ��ȯ�Ѵ�.
	*	@pre	���ڷ� �޴� MusicInfo�� �ٹ��� �ԷµǾ� �־�� �Ѵ�.
	*	@post	ã�� item�� ���ڷ� ���´�.
	*	@param	inData	�ٹ��� �Էµ� �ִ� MusicInfo��.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int RetriveRecordByAlbum();

	/**
	*	@brief	����Ʈ���� �ش� �帣�� ���� item�� ã�� ��ȯ�Ѵ�.
	*	@pre	���ڷ� �޴� MusicInfo�� �帣�� �ԷµǾ� �־�� �Ѵ�.
	*	@post	ã�� item�� ���ڷ� ���´�.
	*	@param	inData	�帣�� �Էµ� �ִ� MusicInfo��.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int RetriveRecordByGenre();

private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	ArrayList<MusicInfo> m_List;		///< item list.
	ArrayList<MusicGenre> g_List;		///< �帣 ����Ʈ
	CircularQueueType<int> recent_List;	///< �ֱٰ� ����Ʈ

	int m_Command;			///< current command number.
};

#endif	// _APPLICATION_H