#pragma once

#include <deque>

using std::deque;


template <typename T, class Container = deque<T> > class Stack
{
public:
	Stack(void){};
	~Stack(void){};

	void Push(const T & element)
	{
		elements_.push_back(element);
	}

	T Top()
	{
		return elements_.back();
	}

	void Pop()
	{
		elements_.erase(elements_.end() - 1);
	}

	bool IsEmpty()
	{
		return elements_.empty();
	}


private:
	Container elements_;
};
