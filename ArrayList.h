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
	*	@brief	add a new data into list. ���� ����Ʈ�� Ǯ�̸� ����Ʈ�� ũ�⸦ �ø���.
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
	*	@brief	item�� ã�Ƽ� �ش� item�� ��ȯ�Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� item�� data�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� MusicInfo��. �߰��� item�� ���ϵȴ�.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int Get(RecordType& data);

	/**
	*	@brief	id�� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� �����Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ���� �ش� item�� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� id�� �Էµ� MusicInfo��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Delete(RecordType data);

	/**
	*	@brief	�ε����� �޾Ƽ� �ش� �ε����� �迭�� ����
	*	@pre	�ش� �ε����� �迭�� �����ؾ���
	*	@post	list ���� �ش� �ε����� �����ȴ�.
	*	@param data	�����ϰ��� �ϴ� �ε����� �Է�
	*/
	void DeleteByIndex(int index);

	/**
	*	@brief	id�� ��ġ�ϴ� list�� item�� ã�Ƽ� �����Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	�迭 ���� �Ѱܹ��� item�� id�� ��ġ�ϴ� ���� �Ѱܹ��� item�� �������� ����ȴ�.
	*	@param	data	��ü�ϰ��� �ϴ� id�� ���ڵ带 ���� MusicInfo��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Replace(RecordType data);

	/**
	*	@brief	����Ž���� ���� id�� ��ġ�ϴ� list�� item�� ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	�迭 ���� �Ѱܹ��� item�� id�� ��ġ�ϴ� ���� ã�Ƽ� data�� ��ȯ�ȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� MusicInfo��.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
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
	int MAXSIZE = 2;  // �迭�� �ִ� ũ�⸦ ��Ÿ����.
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
	//����Ʈ�� Ǯ���� Ȯ���ϰ� Ǯ�̸� ũ�⸦ �÷��ش�.
	if (IsFull()) {
		RecordType *tmp = new RecordType[MAXSIZE * 2];	//���� ũ���� �ι� ��ŭ�� ũ�⸦ ���� ����Ʈ�� �����Ҵ�
		for (int i = 0; i < MAXSIZE; i++) {		// ���� ����Ʈ�� �ִ� �����͸� tmp�� �Űܳ���
			tmp[i] = m_Array[i];
		}
		delete[] m_Array;	//���� �ִ� �����Ҵ�� ����Ʈ�� ��ȯ��
		m_Array = new RecordType[MAXSIZE*2];	// ���� ũ���� �ι� ��ŭ�� ũ�⸦ ���� ����Ʈ�� �����Ҵ�
		for (int i = 0; i < MAXSIZE; i++) {		// tmp �迭�� �Űܳ��� ������ �ٽ� m_Array�� �־���
			m_Array[i] = tmp[i];
		}
		delete[] tmp;	// �����Ҵ� �� tmp�� ��ȯ���ش�.
		MAXSIZE *= 2;	// MAXSIZE�� �ι�� �÷��ش�.
	}
	
		RecordType CurItem;
		ResetList();
		GetNextItem(CurItem);

		while(m_CurPointer<=m_Length) //ó������ ������
		{
			if(CurItem.CompareByKey(inData)== GREATER || m_CurPointer==m_Length)	//���� CurItem>inData�ϰ�� Ȥ�� �迭�� �������̶� �񱳴���� ���°��
			{
				for(int i=m_Length;i>m_CurPointer;i--)	//�ǵڿ��� ���� �ϳ��� �����.
					m_Array[i]=m_Array[i-1];	//�迭 �б�
				m_Array[m_CurPointer]=inData;	//�迭 ���� �� ���� �����Ϳ� ������ �ִ´�.
				m_Length++;	//���� ����
				break;
			}
			GetNextItem(CurItem);	//��������������
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
	m_CurPointer++;	// list pointer ����
	if(m_CurPointer == MAXSIZE)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

//id�� ��ġ�ϴ� item�� ã�Ƽ� ��ȯ��
template<class RecordType>
int ArrayList<RecordType>::Get(RecordType& data)
{
	RecordType CurItem;
	
	ResetList();	//iterator �ʱ�ȭ
	GetNextItem(CurItem);	//ù������ ������
	while(m_CurPointer<m_Length)	//ó������ ������
	{
		switch(CurItem.CompareByKey(data))	//�Է� �����۰� ���� �������� ��
		{
		case EQUAL:	//��ġ�ϸ�
			data=CurItem;	//data�� ���� �������� ��ȯ
			return 1;	//����(1)�� ����
			break;
		case GREATER:	//���� �������� id�� �� ũ��(���ĵ������Ƿ� �������� ã�°� ����)
			return 0;	//����(0)�� ����
			break;
		default:	//���� �������� id�� �� ������
			GetNextItem(CurItem);	//���� �������� �����´�.(��� Ž��)
			break;
		}
	}
	return 0; //���н�0
}


//id�� ��ġ�ϴ� item�� ã�Ƽ� ������
template<class RecordType>
int ArrayList<RecordType>::Delete(RecordType data)
{
	if(Get(data))	//id�� ��ġ�ϴ� item�� �߰��Ѵٸ�(1)
	{
		for(int i=m_CurPointer;i<m_Length;i++)	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
			m_Array[i]=m_Array[i+1];	//�迭 �ڿ��� ������ �ϳ��� ����
		m_Length--;	//������ ������ �ϳ� ����
		return 1;	//����(1)�� ����
	}
	return 0;	//id��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

// �ش� �ε����� ���ڵ带 ����
template<class RecordType>
void ArrayList<RecordType>::DeleteByIndex(int index) {
	
	for (int i = index; i < m_Length; i++) {	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
		m_Array[i] = m_Array[i + 1];		//�迭 �ڿ��� ������ �ϳ��� ����
	}
	m_Length--;	//������ ������ �ϳ� ����
}

//id�� ��ġ�ϴ� item�� ������ ��ü��Ŵ
template<class RecordType>
int ArrayList<RecordType>::Replace(RecordType data)
{
	RecordType tmp(data);	//�Է¹��� item�� ���

	if(Get(data))	//��ġ�ϴ� �������� ã�� ���
	{
		m_Array[m_CurPointer]=tmp;	//�迭���� ���������Ͱ� ����Ű�� ���� ����ߴ� ���������� ��ü��Ŵ
		return 1;	//����(1)�� ����
	}
	return 0;	//id��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

//id�� ��ġ�ϴ� item�� ����Ž������ �˻��ؼ� ��ȯ�Ѵ�.
template<class RecordType>
int ArrayList<RecordType>::GetBinarySearch(RecordType& data )
{
	if(m_Length==0)	//���� �迭�� ����ٸ�
		return 0;	//����(0)�� ����
	int currentPos=m_Length/2;	//�迭�� �߰����� ����
	while(1)
	{
		switch(m_Array[currentPos].CompareByKey(data))
		{
		case EQUAL:	//���� �����۰� �Է� �������� id�� ��ġ�Ѵٸ�
			data=m_Array[currentPos];	//data�� �߰��� ���� ����
			return 1;	//����(1)�� ����
			break;
		case GREATER:	//���� �������� id�� �Է� �������� id���� ũ�ٸ�
			if(currentPos==0)	//ó�� �迭�� ������ �������
				return 0;	//����(0)�� ����
			currentPos/=2;	//�� ������ �ε����� ���ݷ� �̵�
			break;
		case LESS:	//���� �������� id�� �Է� �������� id���� �۴ٸ�
			if(currentPos==m_Length-1)	//������ �迭�� ������ ū���
				return 0;	//����(0)�� ����
			currentPos=(currentPos+m_Length)/2;	//�� ū�� �ε����� �������� �̵�
			break;
		}
	}
	return 0;	//ȣ��� �� ���� ����(WARNING ������)
}

