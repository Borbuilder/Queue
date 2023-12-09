#pragma once
#include<iostream>

template <class T>
class TQueue
{
private:
	T *pMem;
	int size;
	int finish, start;
	int count;

public:

	TQueue(int _size);                       //����������� �� ���������
	~TQueue();                               //����������
	TQueue(const TQueue& object);            //����������� �����������
	bool empty();                            //�������� �� �������
	bool full();                             //�������� �� �������

	void Push(const T& element);             //������� � ����� �������
	T Pop();                                 //���������� �� ������ �������
	T front();                               //��������� ��������, ������� ����� � ������ �������
	T back();                                //��������� ��������, ������� ����� � ������ �������

	void operator = (const TQueue& object);  //�������� ������������
	void operator == (const TQueue& object); //�������� ����������
};

template<class T>
inline TQueue<T>::TQueue(int _size)
{
	size = _size;
	pMem = new T[size];
	start = 0;
	finish = -1;
	count = 0;
}

template<class T>
inline TQueue<T>::~TQueue()
{
	delete[] pMem;
	start = 0;
	finish = -1;
	count = 0;
}

template<class T>
inline TQueue<T>::TQueue(const TQueue& object)
{
	delete[] pMem;
	size = object.size;
	pMem = new T[size];
	std::copy(object.pMem, object.pMem + size, pMem);
	start = object.start;
	finish = object.finish;
	count = object.count;
}

template<class T>
inline bool TQueue<T>::empty()
{
	if (count == 0)
	{
		return true;
	}
	else
	{
        return false;
	}	
}

template<class T>
inline bool TQueue<T>::full()
{
	if (count == size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
inline void TQueue<T>::Push(const T& element)
{
	if (full())
	{
		throw std::exception();
	}
	finish++;
	finish = finish % size;
	pMem[finish] = element;
	count++;
}

template<class T>
inline T TQueue<T>::Pop()
{
	if (empty())
	{
		throw std::exception();
	}
	T element = pMem[start];
	start++;
	start = start % size;
	count--;
	return element;
}

template<class T>
inline T TQueue<T>::front()
{
	return pMem[start];
}

template<class T>
inline T TQueue<T>::back()
{
	return pMem[finish];
}

template<class T>
void TQueue<T>::operator=(const TQueue& object)
{
	start = object.start;
	finish = object.finish;
	count = object.count;
	if (size == object.size)
	{
		std::copy(object.pMem, object.pMem + size, pMem);
	}
	else
	{
		delete[] pMem;
		size = object.size;
		pMem = new T[size];
		std::copy(object.pMem, object.pMem + size, pMem);
	}
}

template<class T>
void TQueue<T>::operator==(const TQueue& object)
{
	if (size != object.size)
	{
		std::exception();
	}

	TQueue this_tmp = *this;
	TQueue obj_tmp = *object;
	while (!this_tmp.empty()) 
	{
		if (this_tmp.front() != obj_tmp.front()) 
		{
			return false;
		}
		this_tmp.pop();
		obj_tmp.pop();
	}

	return true;
}