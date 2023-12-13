#pragma once
#include<iostream>

template <class T>
class TQueue
{
private:
	T* pMem;
	int size;
	int finish, start;
	int count;

public:

	TQueue(int _size);                       //Конструктор по умолчанию
	~TQueue();                               //Деструктор
	TQueue(const TQueue& object);            //Конструктор копирования
	bool empty();                            //Проверка на пустоту
	bool full();                             //Проверка на полноту

	void Push(const T& element);             //Вставка в конец очереди
	T Pop();                                 //Возвращаем из начала очереди
	T front();                               //Возращает значение, которое лежит в начале очереди
	T back();                                //Возращает значение, которое лежит в начале очереди

	void operator = (const TQueue& object);  //Оператор присваивания
	bool operator ==(const TQueue& object);  //Оператор сравненияя
	bool operator !=(const TQueue& object);  //Оператор сравнения

	void output();                           //Вывод
};

template<class T>
inline TQueue<T>::TQueue(int _size)
{
	if (_size < 1)
	{
		throw std::exception();
	}
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
	if (this->empty())
	{
		throw std::exception();
	}
	return pMem[start];
}

template<class T>
inline T TQueue<T>::back()
{
	if (this->empty())
	{
		throw std::exception();
	}
	return pMem[finish];
}

template<class T>
void TQueue<T>::operator=(const TQueue& object)
{
	start = object.start;
	finish = object.finish;
	count = object.count;
	if (count == object.count)
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
bool TQueue<T>::operator==(const TQueue& object)
{
	if (count != object.count)
	{
		return false;
	}
	else
	{
		TQueue this_tmp = *this;
		TQueue obj_tmp = object;
		while (!this_tmp.empty())
		{
			if (this_tmp.front() != obj_tmp.front())
			{
				return false;
			}
			this_tmp.Pop();
			obj_tmp.Pop();
		}
	}
	return true;
}

template<class T>
inline bool TQueue<T>::operator!=(const TQueue& object)
{
	return !(*this == object);
}

template<class T>
inline void TQueue<T>::output()
{
	if (this->empty())
	{
		throw std::exception();
	}
	TQueue<T> this_tmp(*this);
	std::cout << "(";
	while (!(this_tmp.empty()))
	{
		std::cout <<" "<< this_tmp.Pop();
		
	}
	std::cout << " )";
	std::cout << std::endl;
}