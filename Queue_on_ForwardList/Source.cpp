#include "TLQueue.h"
#include<iostream>

int main()
{
	TLQueue<int> q;
	//q.Push(1);
	if (q.empty())
	{
		std::cout << "empty,ok" << std::endl;
	}
	else
	{
		std::cout << " not empty" << std::endl;
	}
	
	q.Push(2);
	q.Push(3);

	q.output();
	
}