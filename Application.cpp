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
		case 8:		//�帣�� Ÿ��Ʋ�� �Ѵ� �´°� ��ġ.
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
		case 12:		// ���� �ֱٿ� �߰��� 30���� ���� ȭ�鿡 ���
			DisplayNewMusic();
			break;
		case 13:		// ������ �帣���� ���
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
		cout << "\n\tSong Number�� ���� ������ �̹� �ֽ��ϴ�." << endl;
		return 0;
	}
	m_List.Add(item);

	MusicGenre g(item.GetGenre(), item.GetSongNumber());	// �帣 ����Ʈ�� �־��ִ� ����
	g_List.Add(g);

	recent_List.EnQueue(item.GetSongNumber());		// recent list�� �־��ش�.

	// ���� list ���
	DisplayAllItem();

	return 1;
}

//Songnumber�� item�� ã�� ����Ѵ�.
int Application::SearchItemById()
{
	MusicInfo item;
	item.SetSongNumFromKB(); //Song number�� �Է¹޴´�.
	
	if(m_List.Get(item)) //0�� �ƴϸ�(ã����)
	{
		cout<<"<============I FOUND ITEM !==========>"<<endl;
		item.DisplayRecordOnScreen(); //�ش� item�� ����Ѵ�.
		cout<<"<====================================>"<<endl;
		return 1;	//����(1)�� ����
	}
	cout<<"<========I CAN'T FIND ITEM !==========>"<<endl;
	return 0;	//����(0)�� ����
}

// title�� item�� ã�� ����Ѵ�.
int Application::SearchListByTitle(MusicInfo &inData) {
	MusicInfo tmp;
	int result = 0;

	m_List.ResetList();//iterator �ʱ�ȭ
	while (m_List.GetNextItem(tmp) != -1) //����Ʈ�� ���������� �ݺ�
	{
		if (tmp.GetTitle().find(inData.GetTitle()) != -1) //���� �ش� ����Ʈ�� Ÿ��Ʋ�� inData�� �̸��� �����ϸ�
		{
			if (result == 0) //ó�� ã�� �����
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//����(1)
		}
	}
	if (result)	//�߰��� ���
		cout << "<====================================>" << endl;
	else	//�߰� ���ϴ� ���
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;

}

// album���� item�� ã�� ����Ѵ�.
int Application::SearchListByAlbum(MusicInfo &inData) {
	MusicInfo tmp;
	int result = 0;

	m_List.ResetList();//iterator �ʱ�ȭ
	while (m_List.GetNextItem(tmp) != -1) //����Ʈ�� ���������� �ݺ�
	{
		if (tmp.GetAlbum().find(inData.GetAlbum()) != -1) //���� �ش� ����Ʈ�� �ٹ��� inData�� �ٹ��� �����ϸ�
		{
			if (result == 0) //ó�� ã�� �����
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//����(1)
		}
	}
	if (result)	//�߰��� ���
		cout << "<====================================>" << endl;
	else	//�߰� ���ϴ� ���
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;

}

// genre�� item�� ã�� ����Ѵ�.
int Application::SearchListByGenre(MusicInfo &inData) {
	MusicInfo tmp;
	int result = 0;

	m_List.ResetList();//iterator �ʱ�ȭ
	while (m_List.GetNextItem(tmp) != -1) //����Ʈ�� ���������� �ݺ�
	{
		if (tmp.GetGenre().find(inData.GetGenre()) != -1) //���� �ش� ����Ʈ�� �帣�� inData�� �帣�� �����ϸ�
		{
			if (result == 0) //ó�� ã�� �����
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//����(1)
		}
	}
	if (result)	//�߰��� ���
		cout << "<====================================>" << endl;
	else	//�߰� ���ϴ� ���
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;

}

//�̸����� item�� ã�Ƽ� ����Ѵ�.
int Application::SearchListByMemberName(MusicInfo &inData)
{
	MusicInfo tmp;
	int result = 0;

	m_List.ResetList();//iterator �ʱ�ȭ
	while (m_List.GetNextItem(tmp) != -1) //����Ʈ�� ���������� �ݺ�
	{
		if (tmp.GetName().find(inData.GetName()) != -1) //���� �ش� ����Ʈ�� �̸��� inData�� �̸��� �����ϸ�
		{
			if (result == 0) //ó�� ã�� �����
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//����(1)
		}
	}
	if (result)	//�߰��� ���
		cout << "<====================================>" << endl;
	else	//�߰� ���ϴ� ���
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;
}

//�̸��� �Է¹��� item���� ����Ʈ���� item�� ã�Ƽ� ����Ѵ�.
int Application::RetriveRecordByMemberName()
{
	MusicInfo item;
	item.SetNameFromKB(); //name�� �Է¹޴´�.

	if(SearchListByMemberName(item)) //0�� �ƴϸ�(ã����)
		return 1;	//����(1)�� ����
	return 0;	//����(0)�� ����
}

//������ �Է¹��� item���� ����Ʈ���� item�� ã�Ƽ� ����Ѵ�.
int Application::RetriveRecordByTitle()
{
	MusicInfo item;
	item.SetTitleFromKB(); //title�� �Է¹޴´�.

	if (SearchListByTitle(item)) //0�� �ƴϸ�(ã����)
		return 1;	//����(1)�� ����
	return 0;	//����(0)�� ����
}

//�ٹ��� �Է¹��� item���� ����Ʈ���� item�� ã�Ƽ� ����Ѵ�.
int Application::RetriveRecordByAlbum()
{
	MusicInfo item;
	item.SetAlbumFromKB(); //album�� �Է¹޴´�.

	if (SearchListByAlbum(item)) //0�� �ƴϸ�(ã����)
		return 1;	//����(1)�� ����
	return 0;	//����(0)�� ����
}

//�帣�� �Է¹��� item���� ����Ʈ���� item�� ã�Ƽ� ����Ѵ�.
int Application::RetriveRecordByGenre()
{
	MusicInfo item;
	item.SetGenreFromKB(); //genre�� �Է¹޴´�.

	if (SearchListByGenre(item)) //0�� �ƴϸ�(ã����)
		return 1;	//����(1)�� ����
	return 0;	//����(0)�� ����
}

//����� �帣�� �Է¹��� item���� ����Ʈ���� item�� ã�Ƽ� ����Ѵ�.
int Application::RetriveRecordByTitleNGenre()
{
	MusicInfo item;
	item.SetTitleFromKB(); //title�� �Է¹޴´�.
	item.SetGenreFromKB();

	if (SearchListByTitleNGenre(item)) //0�� �ƴϸ�(ã����)
		return 1;	//����(1)�� ����
	return 0;	//����(0)�� ����
}



//����� �帣�� ��ġ�ϴ� item�� ã�Ƽ� ����Ѵ�.
int Application::SearchListByTitleNGenre(MusicInfo &inData)
{
	MusicInfo tmp;
	int result = 0;

	m_List.ResetList();//iterator �ʱ�ȭ
	while (m_List.GetNextItem(tmp) != -1) //����Ʈ�� ���������� �ݺ�
	{
		if (tmp.GetTitle() == inData.GetTitle() && tmp.GetGenre() == inData.GetGenre()) //���� �ش� ����Ʈ�� �̸��� inData�� �̸��� �����ϸ�
		{
		
			if (result == 0) //ó�� ã�� �����
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//����(1)
		}
	}
	if (result)	//�߰��� ���
		cout << "<====================================>" << endl;
	else	//�߰� ���ϴ� ���
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;
}

//Song Number�� item�� ã�Ƽ� �����Ѵ�.
int Application::DeleteItem()
{
	int pre = m_List.GetLength();//���� item������ �޾ƿ´�.
	MusicInfo item;
	item.SetSongNumFromKB();
	
	g_List.ResetList();//iterator �ʱ�ȭ
	MusicGenre tmp;
	while (g_List.GetNextItem(tmp) != -1) //����Ʈ�� ���������� �ݺ� & �帣����Ʈ���� �ش��ϴ� ������ ������
	{
		if (tmp.getSongNumber() == item.GetSongNumber()) //���� �ش� ����Ʈ�� �̸��� inData�� �̸��� �����ϸ�
		{
			g_List.DeleteByIndex(g_List.GetCurPointer());
			break;
		}
	}

	m_List.Delete(item);

	if(pre> m_List.GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		
		cout<<"<========DELETE SUCCESS !===========>"<<endl;
		this->DisplayAllItem(); //��� item�� ����Ѵ�.
		return 1;
	}
	
	cout<<"<========DELETE FAIL !=======>"<<endl;
	this->DisplayAllItem();//��� item�� ����Ѵ�.
	return 0;
}

//�ش� Song Number�� item�� �����Ѵ�.
int Application::ReplaceItem()
{
	MusicInfo item;
	item.SetRecordFromKB(); //Ű����κ��� ������ �Է¹���

	m_List.Replace(item); //�ش� item�� Song Number�� ��ġ�ϴ� ���� ã�� �ٲ۴�.
	this->DisplayAllItem();
	return 0;
}

// ���Ӱ� �߰��� 30���� ������ ����Ѵ�.
void Application::DisplayNewMusic() {

	int front, rear;
	front = recent_List.getFront();	// recent_list �κ��� front�� �޴´�
	rear = recent_List.getRear();		// recent_list �κ��� rear�� �޴´�
	MusicInfo data;

	if (front>rear)		//front�� Rear���� Ŭ��
	{
		for(int i=front+1;i<30;i++)
		{
			data.SetSongNum(recent_List.getQueue(i));
			if (m_List.Get(data)) {		// recent list���� ������ music list�� ���� ��� ����ó��
				data.DisplayRecordOnScreen();
			}
		}	
		for(int i=0;i<=rear;i++)
		{
			data.SetSongNum(recent_List.getQueue(i));
			if (m_List.Get(data)) {		// recent list���� ������ music list�� ���� ��� ����ó��
				data.DisplayRecordOnScreen();
			}
		}	//�迭�� ó������ Rear���� ������ش�.
	}
	else	//Rear�� Front���� Ŭ��
	{
		for(int i=front+1;i<=rear;i++)
		{
			data.SetSongNum(recent_List.getQueue(i));
			if (m_List.Get(data)) {		// recent list���� ������ music list�� ���� ��� ����ó��
				data.DisplayRecordOnScreen();
			}
		}	//Front+1�������� Rear���� ���
	}
	cout << endl;
}

// ������ �帣���� ����Ѵ�.
void Application::DisplayMusicByGenre() {
	MusicGenre data;
	g_List.ResetList();
	int length = g_List.GetLength();
	int curIndex = g_List.GetNextItem(data);
	string tmp;

	cout << "\n\t*** Genre *** " << endl;
	while (curIndex < length && curIndex != -1) {
		if (tmp != data.getGenre()) {		//�帣�� �ٲ𶧸� �帣�� ����Ѵ�.
			tmp = data.getGenre();
			cout << endl;
			data.DisplayGenreOnScreen();
		}
		MusicInfo item;
		item.SetSongNum(data.getSongNumber());
		m_List.GetBinarySearch(item);
		item.DisplayTitleOnScreen();		//�������� ��� ����Ѵ�.
		
		curIndex = g_List.GetNextItem(data);
	}
}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	MusicInfo data;

	cout << "\n\tCurrent list" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
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
	
	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	MusicInfo data;	// �б�� �ӽ� ����
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while(!m_InFile.eof())
	{
		// array�� ������ ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
	DisplayAllItem();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	MusicInfo data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
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

	item.SetSongNumFromKB();	//Song Number�� �Է¹޴´�
	if(m_List.GetBinarySearch(item))	//����Ž���� �����ߴٸ�
	{
		cout<<"<============I FOUND ITEM !==========>"<<endl;
		item.DisplayRecordOnScreen();
		cout<<"<====================================>"<<endl;
		return 1;	//����(1)�� ��ȯ
	}
	//�߰� ���ҽ�
	cout<<"<========I CAN'T FIND ITEM !==========>"<<endl;
	return 0;	//����(0)�� ��ȯ
	
}
