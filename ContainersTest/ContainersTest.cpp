// ContainersTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stack>
#include <assert.h>

#include "Stack.h"
#include "List.h"

#include "BinTreeTests.h"


int GCD(int a, int b)
{
   if (b==0) 
	   return a;
   int ost = a%b;
   return GCD(b, ost);
}

int _tmain(int argc, _TCHAR* argv[])
{

	int g = GCD(252, 105);
	g = GCD(105, 252);
	g = GCD(1989, 867);

	std::stack<int> ss;
	ss.push(11);
	
	
	Stack<int> stack;
	
	stack.Push(11);
	stack.Push(22);
	stack.Push(333);

	while(!stack.IsEmpty())
	{
		int i = stack.Top();
		std::cout << i << std::endl;
		stack.Pop();
	}

	List<int> list;
	list.PushFront(11);
		assert(11 == list.Front());
		assert(11 == list.Back());
	list.PopFront();
		assert(list.IsEmpty());

	list.PushBack(99);
		assert(99 == list.Front());
		assert(99 == list.Back());
	list.PopBack();
		assert(list.IsEmpty());

	list.PushFront(22);
	list.PushBack(33);
	list.PushBack(44);
	list.PushFront(11);

	assert(11 == list.Front());
	assert(44 == list.Back());


	BinTreeTests binTreeTests;
	binTreeTests.Execute();

	return 0;
}

