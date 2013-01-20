#pragma once

#include <list>

template<typename T>
class List
{
	class Node
	{
	public: 
		Node(const T & t):value(t),next_(NULL) {}
		Node * next_;
		T value;	
	};

public:

	class iterator
	{
	public:
		iterator(Node * node):node_(node) {}

		T & operator * ()
		{
			return node_->value;
		}

		iterator & operator ++ ()
		{
			node_ = node_->next_;
			return *this;
		}

		bool operator != (iterator const & other)
		{
			return node_ != other.node_;
		}

	private:
		Node * node_;
	};
	

public:
	List(void):head_(0),tail_(0)
	{}
	~List(void){};

	iterator Begin()
	{
		iterator iter(head_);
		return iter;
	}

	iterator End()
	{
		iterator iter(0);
		return iter;
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

	void MakeAnLoop()
	{
		//TODO
	}

	void Rotate()
	{
		if(!head_)
			return;
		
		Node * previous = head_;
		Node * node_to_rotate = head_->next_;
		head_->next_ = 0;
		
		head_ = tail_ ;
		tail_ = previous ;

		while(node_to_rotate)
		{
			Node * next = node_to_rotate->next_;
			node_to_rotate->next_ = previous;
			previous = node_to_rotate;
			node_to_rotate = next;
		}
	}

private:
	Node * head_;
	Node * tail_;
};
