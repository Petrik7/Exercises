// ContainersTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stack>
#include <assert.h>
#include <limits>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

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
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	std::vector<int> :: iterator it = v.begin();
	++it;
	std:: cout << *it << " - 2" << std::endl;
	++it;
	if(it == v.end())
		std:: cout << " - end" << std::endl;

	unsigned int a = std::numeric_limits<unsigned int>::max()/2;
	unsigned int b = a + 1000000;
	unsigned int res = a + b;

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
		assert(11 == *(list.Begin()));
	list.PopFront();
		assert(list.IsEmpty());

	list.PushBack(99);
		assert(99 == *(list.Begin()));
	list.PopBack();
		assert(list.IsEmpty());

	list.PushFront(22);
	list.PushBack(33);
	list.PushBack(44);
	list.PushFront(11);

	assert(11 == *(list.Begin()));

	list.Rotate();

	assert(44 == *(list.Begin()));
	
	List<int> :: iterator i = list.Begin();
	int first_value = *i;
	std::cout << "Printing list containt: " << std::endl;
	for(; i != list.End(); ++i)
	{
		std::cout << *i << std::endl;
	}

	//List<int> :: iterator<int> iter_second = ++iter_first;
	//int second_value = *iter_second;

	BinTreeTests binTreeTests;
	binTreeTests.Execute();

	return 0;
}

