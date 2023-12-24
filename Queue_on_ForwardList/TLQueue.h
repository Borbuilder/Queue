#pragma once
#include<iostream>
#include <algorithm>

template <class T>
struct TNode
{
	T value;
	TNode<T>* pNext;
	TNode() { pNext = nullptr; }
};

template <class T>
class TLQueue
{
private:
	TNode<T>* pFirst, * pLast;
	
public:
	TLQueue() { pFirst = nullptr; pLast = nullptr; };         //Конструктор по умолчанию
	~TLQueue() { ClearQueue(); };                             //Деструктор
	TLQueue(const TLQueue<T>& queue_object);                  //Конструктор копирования

	TLQueue<T>& operator=(const TLQueue<T>& queue_object);    //Оператор присваивания
	bool operator==(const TLQueue<T>& queue_object);          //Оператор сравнения
	bool operator != (const TLQueue<T>&queue_object);         //Оператор обратного сравнения

	bool empty();                                             //Проверка на пустоту
	void Push(const T& element);                              //Вставка элеменнта в конец
	T Pop();                                                  //Получить значение из начала очереди с его удалением
	T Front();                                                //Получить значение из начала очереди без его удалением
	T Back();                                                 //Получить значение с конца очереди
	int ElementsNumber();                                     //Количество элементов в очереди
	void ClearQueue();                                        //Очистить очередь
	void output();                                            //Вывести очередь на экран
};    

template<class T>
inline TLQueue<T>::TLQueue(const TLQueue<T>& object)
{
	TNode<T>* tmp = object.pFirst,*current;
	pFirst = pLast = nullptr;
	while (tmp != nullptr)
	{
		current = new TNode<T>;
		current->value = tmp->value;
		if (pFirst == nullptr)
		{
			pFirst = current;
			pLast = current;
		}
		else
		{
			pLast->pNext = current;
			pLast = current;
		}
		tmp = tmp->pNext;
	}
}

template<class T>
inline TLQueue<T>& TLQueue<T>::operator=(const TLQueue<T>& object)
{
	if (object.pFirst == nullptr)
	{
		ClearQueue();
	}
	else
	{
		//ClearQueue();
		TNode<T>* tmp = object.pFirst, * current;
		while (tmp != nullptr)
		{
			current = new TNode<T>;
			current->value = tmp->value;
			if (pFirst == nullptr)
			{
				pFirst = current;
				pLast = current;
			}
			else
			{
				pLast->pNext = current;
				pLast = current;
			}
			tmp = tmp->pNext;
		}
	}
	return *this;
}

template<class T>
inline bool TLQueue<T>::operator==(const TLQueue<T>& object)
{   
	TLQueue<T> current_queue(*this);
	TLQueue<T> another_queue(object);

	if (ElementsNumber() != another_queue.ElementsNumber())
	{
		return false;
	}
	if (pFirst == nullptr && object.pFirst == nullptr )
	{
		return true;
	}
	while (!current_queue.empty())
	{
		if (current_queue.Pop() != another_queue.Pop())
		{
			return false;
		}
	}
	return true;
}

template<class T>
inline bool TLQueue<T>::operator!=(const TLQueue<T>& object)
{
	return !(*this == object);
}

template<class T>
inline bool TLQueue<T>::empty()
{
	if (pFirst == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
inline T TLQueue<T>::Pop()
{
	if (empty())
	{
		throw "Queue is empty, you can't pop";
	}

	TNode<T> *tmp = pFirst;
	T result = pFirst->value;
	pFirst = pFirst->pNext;
	delete tmp;
	return result;
}

template<class T>
inline void TLQueue<T>::Push(const T& element)
{
	TNode<T>* tmp = new TNode<T>;
	tmp->value = element;
	tmp->pNext = nullptr;
	if (empty())
	{
		pFirst = tmp;
		pLast = tmp;
	}
	else
	{
		pLast->pNext = tmp;
		pLast = tmp;
	}
}

template<class T>
inline T TLQueue<T>::Front()
{
	if (empty())
	{
		throw "Queue is empty, you can't get front";
	}
	return pFirst->value;
}

template<class T>
inline T TLQueue<T>::Back()
{
	if (empty())
	{
		throw "Queue is empty, you can't get back";
	}
	return pLast->value;
}

template<class T>
inline int TLQueue<T>::ElementsNumber()
{
	TNode<T>* tmp = pFirst;
	int i = 0;
	while (tmp != nullptr)
	{
		i++;
		tmp = tmp->pNext;
	}
	return i;
}

template<class T>
inline void TLQueue<T>::ClearQueue()
{
	while (!empty())
	{
		Pop();
	}
	pFirst = nullptr;
	pLast = nullptr;
}

template<class T>
inline void TLQueue<T>::output()
{
	if (empty())
	{
		std::cout << "( )";
	}
	else
	{
		TLQueue<T> current(*this);
		std::cout << "( ";
		while (!current.empty())
		{
			std::cout << current.Pop() << " ";
		}
		std::cout << ")" << std::endl;
	}
}