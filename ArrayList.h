#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "MusicInfo.h"
#include "MusicGenre.h"
template<class RecordType>
class ArrayList
{
public:
	/**
	*	default constructor.
	*/
	ArrayList()
	{
		m_Length = 0;
		ResetList();
	}

	/**
	*	destructor.
	*/
	~ArrayList() {}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	add a new data into list. 만약 리스트가 풀이면 리스트의 크기를 늘린다.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(RecordType data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(RecordType& data);

	/**
	*	@brief	item을 찾아서 해당 item을 반환한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 id가 입력된 MusicInfo값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Get(RecordType& data);

	/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 제거한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 id가 입력된 MusicInfo값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Delete(RecordType data);

	/**
	*	@brief	인덱스를 받아서 해당 인덱스의 배열을 삭제
	*	@pre	해당 인덱스가 배열에 존재해야함
	*	@post	list 내에 해당 인덱스가 삭제된다.
	*	@param data	제거하고자 하는 인덱스가 입력
	*/
	void DeleteByIndex(int index);

	/**
	*	@brief	id가 일치하는 list내 item을 찾아서 변경한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	배열 내에 넘겨받은 item과 id가 일치하는 값이 넘겨받은 item의 내용으로 변경된다.
	*	@param	data	교체하고자 하는 id와 레코드를 가진 MusicInfo값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Replace(RecordType data);

	/**
	*	@brief	이진탐색을 통해 id가 일치하는 list내 item을 찾아서 반환한다.
	*	@pre	없음.
	*	@post	배열 내에 넘겨받은 item과 id가 일치하는 값을 찾아서 data로 반환된다.
	*	@param	data	찾고자 하는 id가 입력된 MusicInfo값.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int GetBinarySearch(RecordType& data);

	/**
	*	@brief	Get a pointer
	*	@pre	none.
	*	@post	none.
	*	@return	pointer.
	*/
	int GetCurPointer();

private:
	int MAXSIZE = 2;  // 배열의 최대 크기를 나타낸다.
	RecordType *m_Array = new RecordType[MAXSIZE];  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

// Make list empty.
template<class RecordType>
void ArrayList<RecordType>::MakeEmpty()
{
	m_Length = 0;
}

// Get a number of records in current list.
template<class RecordType>
int ArrayList<RecordType>::GetLength()
{
	return m_Length;
}

// Get Pointer 
template<class RecordType>
int ArrayList<RecordType>::GetCurPointer()
{
	return m_CurPointer;
}

// Check capacity of list is full.
template<class RecordType>
bool ArrayList<RecordType>::IsFull()
{
	if(m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// add a new data into list.
template<class RecordType>
int ArrayList<RecordType>::Add(RecordType inData)
{
	//리스트가 풀인지 확인하고 풀이면 크기를 늘려준다.
	if (IsFull()) {
		RecordType *tmp = new RecordType[MAXSIZE * 2];	//원래 크기의 두배 만큼의 크기를 갖는 리스트를 동적할당
		for (int i = 0; i < MAXSIZE; i++) {		// 원래 리스트에 있던 데이터를 tmp에 옮겨놓음
			tmp[i] = m_Array[i];
		}
		delete[] m_Array;	//원래 있던 동적할당된 리스트를 반환함
		m_Array = new RecordType[MAXSIZE*2];	// 원래 크기의 두배 만큼의 크기를 갖는 리스트를 동적할당
		for (int i = 0; i < MAXSIZE; i++) {		// tmp 배열에 옮겨놨던 값들을 다시 m_Array에 넣어줌
			m_Array[i] = tmp[i];
		}
		delete[] tmp;	// 동적할당 된 tmp를 반환해준다.
		MAXSIZE *= 2;	// MAXSIZE를 두배로 늘려준다.
	}
	
		RecordType CurItem;
		ResetList();
		GetNextItem(CurItem);

		while(m_CurPointer<=m_Length) //처음부터 끝까지
		{
			if(CurItem.CompareByKey(inData)== GREATER || m_CurPointer==m_Length)	//만약 CurItem>inData일경우 혹은 배열의 마지막이라서 비교대상이 없는경우
			{
				for(int i=m_Length;i>m_CurPointer;i--)	//맨뒤에서 부터 하나씩 땡긴다.
					m_Array[i]=m_Array[i-1];	//배열 밀기
				m_Array[m_CurPointer]=inData;	//배열 밀은 후 현재 포인터에 아이템 넣는다.
				m_Length++;	//개수 증가
				break;
			}
			GetNextItem(CurItem);	//다음아이템으로
		}
	
	return 1;
}

// Initialize list iterator.
template<class RecordType>
void ArrayList<RecordType>::ResetList()
{
	m_CurPointer = -1;
}

// move list iterator to the next item in list and get that item.
template<class RecordType>
int ArrayList<RecordType>::GetNextItem(RecordType& data)
{
	m_CurPointer++;	// list pointer 증가
	if(m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

//id가 일치하는 item을 찾아서 반환함
template<class RecordType>
int ArrayList<RecordType>::Get(RecordType& data)
{
	RecordType CurItem;
	
	ResetList();	//iterator 초기화
	GetNextItem(CurItem);	//첫아이템 가져옴
	while(m_CurPointer<m_Length)	//처음부터 끝까지
	{
		switch(CurItem.CompareByKey(data))	//입력 아이템과 현재 아이템을 비교
		{
		case EQUAL:	//일치하면
			data=CurItem;	//data에 현재 아이템을 반환
			return 1;	//성공(1)을 리턴
			break;
		case GREATER:	//현재 아이템의 id가 더 크면(정렬되있으므로 나머지에 찾는게 없다)
			return 0;	//실패(0)을 리턴
			break;
		default:	//현재 아이템의 id가 더 작으면
			GetNextItem(CurItem);	//다음 아이템을 가져온다.(계속 탐색)
			break;
		}
	}
	return 0; //실패시0
}


//id가 일치하는 item을 찾아서 제거함
template<class RecordType>
int ArrayList<RecordType>::Delete(RecordType data)
{
	if(Get(data))	//id가 일치하는 item을 발견한다면(1)
	{
		for(int i=m_CurPointer;i<m_Length;i++)	//현재 포인터부터 입력된 배열 끝까지 반복
			m_Array[i]=m_Array[i+1];	//배열 뒤에걸 앞으로 하나씩 땡김
		m_Length--;	//아이템 개수를 하나 줄임
		return 1;	//성공(1)을 리턴
	}
	return 0;	//id일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

// 해당 인덱스의 레코드를 삭제
template<class RecordType>
void ArrayList<RecordType>::DeleteByIndex(int index) {
	
	for (int i = index; i < m_Length; i++) {	//현재 포인터부터 입력된 배열 끝까지 반복
		m_Array[i] = m_Array[i + 1];		//배열 뒤에걸 앞으로 하나씩 땡김
	}
	m_Length--;	//아이템 개수를 하나 줄임
}

//id가 일치하는 item의 내용을 교체시킴
template<class RecordType>
int ArrayList<RecordType>::Replace(RecordType data)
{
	RecordType tmp(data);	//입력받은 item을 백업

	if(Get(data))	//일치하는 아이템을 찾은 경우
	{
		m_Array[m_CurPointer]=tmp;	//배열에서 현재포인터가 가르키는 것을 백업했던 아이템으로 교체시킴
		return 1;	//성공(1)을 리턴
	}
	return 0;	//id일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

//id가 일치하는 item을 이진탐색으로 검색해서 반환한다.
template<class RecordType>
int ArrayList<RecordType>::GetBinarySearch(RecordType& data )
{
	if(m_Length==0)	//만약 배열이 비었다면
		return 0;	//실패(0)을 리턴
	int currentPos=m_Length/2;	//배열의 중간부터 시작
	while(1)
	{
		switch(m_Array[currentPos].CompareByKey(data))
		{
		case EQUAL:	//현재 아이템과 입력 아이템의 id가 일치한다면
			data=m_Array[currentPos];	//data에 발견한 값을 리턴
			return 1;	//성공(1)을 리턴
			break;
		case GREATER:	//현재 아이템의 id가 입력 아이템의 id보다 크다면
			if(currentPos==0)	//처음 배열의 값보다 작은경우
				return 0;	//실패(0)을 리턴
			currentPos/=2;	//더 작은쪽 인덱스의 절반로 이동
			break;
		case LESS:	//현재 아이템의 id가 입력 아이템의 id보다 작다면
			if(currentPos==m_Length-1)	//마지막 배열의 값보다 큰경우
				return 0;	//실패(0)을 리턴
			currentPos=(currentPos+m_Length)/2;	//더 큰쪽 인덱스의 절반으로 이동
			break;
		}
	}
	return 0;	//호출될 일 없는 리턴(WARNING 방지용)
}

