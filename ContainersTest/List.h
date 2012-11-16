#pragma once

#include <list>

template<typename T>
class List
{
	class Node
	{
	public: 
		Node(const T & t):value(t),next_(NULL)
		{}
		Node * next_;
		T value;	
	};

public:
	class iterator
	{
	public:

	private:
		Node * node_;
	};
	

public:
	List(void):head_(NULL),tail_(NULL)
	{}
	~List(void){};

	T Front()
	{
		if(!head_)
			throw "Empty list";
		return head_->value;
	}

	T Back()
	{
		if(!tail_)
			throw "Empty list";
		return tail_->value;
	}

	void PushBack(const T & t)
	{
		if(!tail_)
			head_ = tail_ = new Node(t);
		else
		{
			Node * new_tail = new Node(t);
			tail_->next_ = new_tail;
			tail_ = new_tail ;
		}
	}

	void PushFront(const T & t)
	{
		if(!head_)
			head_ = tail_ = new Node(t);
		else
		{
			Node * new_head = new Node(t);
			new_head->next_ = head_;
			head_ = new_head;
		}
	}

	void PopFront()
	{
		if(!head_)
			throw std::exception("empty list");

		Node * tmp_head = head_;
		head_ = head_->next_;
		if(tmp_head == tail_)
			tail_ = 0;
		delete tmp_head;
	}

	void PopBack()
	{
		if(!tail_)
			throw std::exception("empty list");

		Node * tmp_tail = tail_;

		Node * previous_node = head_;
		while(previous_node)
		{	
			if(previous_node->next_ == tail_)
				break;
			previous_node = previous_node->next_;
		}
		
		if(previous_node)
		{
			previous_node->next_ = 0;
			tail_ = previous_node;
		}
		else
			head_ = tail_ = 0;
		delete tmp_tail;

	}

	bool IsEmpty()
	{
		return head_ == 0;
	}

	size_t Count()
	{
	
	}

private:
	Node * head_;
	Node * tail_;

};