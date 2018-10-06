#include "Application.h"

// Program driver.
void Application::Run()
{
	while(1)
	{
		m_Command = GetCommand();

		switch(m_Command)
		{
		case 1:		// read a record and add to list.
			AddItem();
			break;
		case 2:		//delete.
			DeleteItem();
			break;
		case 3:	//replace.
			ReplaceItem();
			break;
		case 4:		//search list by title.
			RetriveRecordByTitle();
			break;
		case 5:		//search list by name
			RetriveRecordByMemberName();
			break;
		case 6:		//search list by album
			RetriveRecordByAlbum();
			break;
		case 7:		// search list by genre
			RetriveRecordByGenre();
			break;
		case 8:		//장르와 타이틀이 둘다 맞는걸 서치.
			RetriveRecordByTitleNGenre();
			break;
		case 9:		// Display all the records in list on screen.
			DisplayAllItem();
			break;
		case 10:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 11:		// save list data into a file.
			WriteDataToFile();
			break;
		case 12:		// 가장 최근에 추가한 30개의 곡을 화면에 출력
			DisplayNewMusic();
			break;
		case 13:		// 음악을 장르별로 출력
			DisplayMusicByGenre();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t    1 : Add music" << endl;
	cout << "\t    2 : Delete music" << endl;
	cout << "\t    3 : Replace music" << endl;
	cout << "\t    4 : Search music by title" << endl;
	cout << "\t    5 : Search music by singer" << endl;
	cout << "\t    6 : Search music by album" << endl;
	cout << "\t    7 : Search music by genre" << endl;
	cout << "\t    8 : Search music by genreNtitle" << endl;
	cout << "\t    9 : Print all on screen" << endl;
	cout << "\t   10 : Get from file" << endl; 
	cout << "\t   11 : Put to file " << endl;
	cout << "\t   12 : Display Recent Music " << endl;
	cout << "\t   13 : Display Music by genre " << endl;
	cout << "\t    0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	
	cin >> command;
	cout << endl;
	
	return command;
}


// Add new record into list.
int Application::AddItem()
{
	
	MusicInfo item;

	item.SetRecordFromKB();
	if (m_List.Get(item)) {
		cout << "\n\tSong Number가 같은 음악이 이미 있습니다." << endl;
		return 0;
	}
	m_List.Add(item);

	MusicGenre g(item.GetGenre(), item.GetSongNumber());	// 장르 리스트에 넣어주는 과정
	g_List.Add(g);

	recent_List.EnQueue(item.GetSongNumber());		// recent list에 넣어준다.

	// 현재 list 출력
	DisplayAllItem();

	return 1;
}

//Songnumber로 item을 찾아 출력한다.
int Application::SearchItemById()
{
	MusicInfo item;
	item.SetSongNumFromKB(); //Song number를 입력받는다.
	
	if(m_List.Get(item)) //0이 아니면(찾으면)
	{
		cout<<"<============I FOUND ITEM !==========>"<<endl;
		item.DisplayRecordOnScreen(); //해당 item을 출력한다.
		cout<<"<====================================>"<<endl;
		return 1;	//성공(1)을 리턴
	}
	cout<<"<========I CAN'T FIND ITEM !==========>"<<endl;
	return 0;	//실패(0)을 리턴
}

// title로 item을 찾아 출력한다.
int Application::SearchListByTitle(MusicInfo &inData) {
	MusicInfo tmp;
	int result = 0;

	m_List.ResetList();//iterator 초기화
	while (m_List.GetNextItem(tmp) != -1) //리스트의 마지막까지 반복
	{
		if (tmp.GetTitle().find(inData.GetTitle()) != -1) //만약 해당 리스트의 타이틀에 inData의 이름이 존재하면
		{
			if (result == 0) //처음 찾는 경우라면
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//성공(1)
		}
	}
	if (result)	//발견한 경우
		cout << "<====================================>" << endl;
	else	//발견 못하는 경우
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;

}

// album으로 item을 찾아 출력한다.
int Application::SearchListByAlbum(MusicInfo &inData) {
	MusicInfo tmp;
	int result = 0;

	m_List.ResetList();//iterator 초기화
	while (m_List.GetNextItem(tmp) != -1) //리스트의 마지막까지 반복
	{
		if (tmp.GetAlbum().find(inData.GetAlbum()) != -1) //만약 해당 리스트의 앨범에 inData의 앨범이 존재하면
		{
			if (result == 0) //처음 찾는 경우라면
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//성공(1)
		}
	}
	if (result)	//발견한 경우
		cout << "<====================================>" << endl;
	else	//발견 못하는 경우
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;

}

// genre로 item을 찾아 출력한다.
int Application::SearchListByGenre(MusicInfo &inData) {
	MusicInfo tmp;
	int result = 0;

	m_List.ResetList();//iterator 초기화
	while (m_List.GetNextItem(tmp) != -1) //리스트의 마지막까지 반복
	{
		if (tmp.GetGenre().find(inData.GetGenre()) != -1) //만약 해당 리스트의 장르에 inData의 장르가 존재하면
		{
			if (result == 0) //처음 찾는 경우라면
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//성공(1)
		}
	}
	if (result)	//발견한 경우
		cout << "<====================================>" << endl;
	else	//발견 못하는 경우
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;

}

//이름으로 item을 찾아서 출력한다.
int Application::SearchListByMemberName(MusicInfo &inData)
{
	MusicInfo tmp;
	int result = 0;

	m_List.ResetList();//iterator 초기화
	while (m_List.GetNextItem(tmp) != -1) //리스트의 마지막까지 반복
	{
		if (tmp.GetName().find(inData.GetName()) != -1) //만약 해당 리스트의 이름에 inData의 이름이 존재하면
		{
			if (result == 0) //처음 찾는 경우라면
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//성공(1)
		}
	}
	if (result)	//발견한 경우
		cout << "<====================================>" << endl;
	else	//발견 못하는 경우
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;
}

//이름을 입력받은 item으로 리스트에서 item을 찾아서 출력한다.
int Application::RetriveRecordByMemberName()
{
	MusicInfo item;
	item.SetNameFromKB(); //name을 입력받는다.

	if(SearchListByMemberName(item)) //0이 아니면(찾으면)
		return 1;	//성공(1)을 리턴
	return 0;	//실패(0)을 리턴
}

//제목을 입력받은 item으로 리스트에서 item을 찾아서 출력한다.
int Application::RetriveRecordByTitle()
{
	MusicInfo item;
	item.SetTitleFromKB(); //title을 입력받는다.

	if (SearchListByTitle(item)) //0이 아니면(찾으면)
		return 1;	//성공(1)을 리턴
	return 0;	//실패(0)을 리턴
}

//앨범을 입력받은 item으로 리스트에서 item을 찾아서 출력한다.
int Application::RetriveRecordByAlbum()
{
	MusicInfo item;
	item.SetAlbumFromKB(); //album을 입력받는다.

	if (SearchListByAlbum(item)) //0이 아니면(찾으면)
		return 1;	//성공(1)을 리턴
	return 0;	//실패(0)을 리턴
}

//장르를 입력받은 item으로 리스트에서 item을 찾아서 출력한다.
int Application::RetriveRecordByGenre()
{
	MusicInfo item;
	item.SetGenreFromKB(); //genre을 입력받는다.

	if (SearchListByGenre(item)) //0이 아니면(찾으면)
		return 1;	//성공(1)을 리턴
	return 0;	//실패(0)을 리턴
}

//제목과 장르를 입력받은 item으로 리스트에서 item을 찾아서 출력한다.
int Application::RetriveRecordByTitleNGenre()
{
	MusicInfo item;
	item.SetTitleFromKB(); //title을 입력받는다.
	item.SetGenreFromKB();

	if (SearchListByTitleNGenre(item)) //0이 아니면(찾으면)
		return 1;	//성공(1)을 리턴
	return 0;	//실패(0)을 리턴
}



//제목과 장르가 일치하는 item을 찾아서 출력한다.
int Application::SearchListByTitleNGenre(MusicInfo &inData)
{
	MusicInfo tmp;
	int result = 0;

	m_List.ResetList();//iterator 초기화
	while (m_List.GetNextItem(tmp) != -1) //리스트의 마지막까지 반복
	{
		if (tmp.GetTitle() == inData.GetTitle() && tmp.GetGenre() == inData.GetGenre()) //만약 해당 리스트의 이름에 inData의 이름이 존재하면
		{
		
			if (result == 0) //처음 찾는 경우라면
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//성공(1)
		}
	}
	if (result)	//발견한 경우
		cout << "<====================================>" << endl;
	else	//발견 못하는 경우
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;
}

//Song Number로 item을 찾아서 제거한다.
int Application::DeleteItem()
{
	int pre = m_List.GetLength();//이전 item개수를 받아온다.
	MusicInfo item;
	item.SetSongNumFromKB();
	
	g_List.ResetList();//iterator 초기화
	MusicGenre tmp;
	while (g_List.GetNextItem(tmp) != -1) //리스트의 마지막까지 반복 & 장르리스트에서 해당하는 음악을 지워줌
	{
		if (tmp.getSongNumber() == item.GetSongNumber()) //만약 해당 리스트의 이름에 inData의 이름이 존재하면
		{
			g_List.DeleteByIndex(g_List.GetCurPointer());
			break;
		}
	}

	m_List.Delete(item);

	if(pre> m_List.GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
	{
		
		cout<<"<========DELETE SUCCESS !===========>"<<endl;
		this->DisplayAllItem(); //모든 item을 출력한다.
		return 1;
	}
	
	cout<<"<========DELETE FAIL !=======>"<<endl;
	this->DisplayAllItem();//모든 item을 출력한다.
	return 0;
}

//해당 Song Number의 item을 변경한다.
int Application::ReplaceItem()
{
	MusicInfo item;
	item.SetRecordFromKB(); //키보드로부터 정보를 입력받음

	m_List.Replace(item); //해당 item의 Song Number와 일치하는 것을 찾아 바꾼다.
	this->DisplayAllItem();
	return 0;
}

// 새롭게 추가된 30개의 음악을 출력한다.
void Application::DisplayNewMusic() {

	int front, rear;
	front = recent_List.getFront();	// recent_list 로부터 front를 받는다
	rear = recent_List.getRear();		// recent_list 로부터 rear를 받는다
	MusicInfo data;

	if (front>rear)		//front가 Rear보다 클때
	{
		for(int i=front+1;i<30;i++)
		{
			data.SetSongNum(recent_List.getQueue(i));
			if (m_List.Get(data)) {		// recent list에는 있지만 music list에 없을 경우 예외처리
				data.DisplayRecordOnScreen();
			}
		}	
		for(int i=0;i<=rear;i++)
		{
			data.SetSongNum(recent_List.getQueue(i));
			if (m_List.Get(data)) {		// recent list에는 있지만 music list에 없을 경우 예외처리
				data.DisplayRecordOnScreen();
			}
		}	//배열의 처음부터 Rear까지 출력해준다.
	}
	else	//Rear가 Front보다 클때
	{
		for(int i=front+1;i<=rear;i++)
		{
			data.SetSongNum(recent_List.getQueue(i));
			if (m_List.Get(data)) {		// recent list에는 있지만 music list에 없을 경우 예외처리
				data.DisplayRecordOnScreen();
			}
		}	//Front+1에서부터 Rear까지 출력
	}
	cout << endl;
}

// 음악을 장르별로 출력한다.
void Application::DisplayMusicByGenre() {
	MusicGenre data;
	g_List.ResetList();
	int length = g_List.GetLength();
	int curIndex = g_List.GetNextItem(data);
	string tmp;

	cout << "\n\t*** Genre *** " << endl;
	while (curIndex < length && curIndex != -1) {
		if (tmp != data.getGenre()) {		//장르가 바뀔때만 장르를 출력한다.
			tmp = data.getGenre();
			cout << endl;
			data.DisplayGenreOnScreen();
		}
		MusicInfo item;
		item.SetSongNum(data.getSongNumber());
		m_List.GetBinarySearch(item);
		item.DisplayTitleOnScreen();		//아이템을 계속 출력한다.
		
		curIndex = g_List.GetNextItem(data);
	}
}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	MusicInfo data;

	cout << "\n\tCurrent list" << endl;

	// list의 모든 데이터를 화면에 출력
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
		cout << endl;
	}
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if(!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if(!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	MusicInfo data;	// 읽기용 임시 변수
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if(!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while(!m_InFile.eof())
	{
		// array에 음악의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	DisplayAllItem();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	MusicInfo data;	// 쓰기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if(!OpenOutFile(filename))
		return 0;

	// list 포인터를 초기화
	m_List.ResetList();

	// list의 모든 데이터를 파일에 쓰기
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}

int Application::SearchItemByBinarySearch()
{
	MusicInfo item;

	item.SetSongNumFromKB();	//Song Number를 입력받는다
	if(m_List.GetBinarySearch(item))	//이진탐색에 성공했다면
	{
		cout<<"<============I FOUND ITEM !==========>"<<endl;
		item.DisplayRecordOnScreen();
		cout<<"<====================================>"<<endl;
		return 1;	//성공(1)을 반환
	}
	//발견 못할시
	cout<<"<========I CAN'T FIND ITEM !==========>"<<endl;
	return 0;	//실패(0)을 반환
	
}
