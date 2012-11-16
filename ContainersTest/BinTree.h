#pragma once

#include <iostream>
#include <map>
#include <queue>
#include <memory>
#include <algorithm>

//class BinTreePinter;

class BinNode
{
public:

	BinNode():_parent(0), _left(0), _right(0), _key(0), _value(0)
	{}
	
	BinNode(BinNode * parent, int key, int value):_parent(parent), _left(0), _right(0), _key(key), _value(value)
	{}

	//BinNode(const BinNode * parent, int key):_parent(parent), _left(0), _right(0), _key(key), _value(0)
	//{}

	BinNode * _parent;
	BinNode * _left;
	BinNode * _right;

	int _key;
	int _value;

};


class BinTree
{
	friend class BinTreePinter;

public:
	BinTree(void);
	~BinTree(void);

	void Add(int key, int value)
	{
		if(_root_node == 0)
			_root_node = new BinNode(0, key, value);
		else
			AddNewNodeToTreeIter(_root_node, key, value);
			//AddNewNodeToTreeReq(_root_node, key, value);
	}

	//find the level at which the tree is complete
	size_t GetCompleteTreeLevelIter()
	{
		size_t level = 0;

		std::queue<BinNode*> nodes;
		nodes.push(_root_node);

		BinNode * next_node = 0;
		std::auto_ptr<BinNode> delimiter_node(new BinNode());
		nodes.push(delimiter_node.get());

		while( !nodes.empty() )
		{
			next_node = nodes.front();
			nodes.pop();

			if(delimiter_node.get() == next_node)
			{
				++level;
				nodes.push(delimiter_node.get());
				continue;
			}

			if(!next_node || !next_node->_left || !next_node->_right)
				return level;

			nodes.push(next_node->_left);
			nodes.push(next_node->_right);
		
		}
	}


	size_t GetCompleteTreeLevelRec()
	{
		std::queue<BinNode> level_nodes;
		level_nodes.push(*_root_node);
		std::shared_ptr<BinNode> separator(new BinNode());
		level_nodes.push( BinNode(separator.get(), 0, 0));
		size_t level = 0;
		return GetCompleteTreeLevelRecImpl(level_nodes, BinNode(separator.get(), 0, 0), level);
	}


	BinNode * GetRootNode()
	{
		return _root_node;
	}

	size_t GetCompleteTreeLevelRecCC(BinNode * node)
	{
		if( !(node) || !(node->_left) || !(node->_right) )
			return 0;
		
		int l = GetCompleteTreeLevelRecCC(node->_left);
		int r = GetCompleteTreeLevelRecCC(node->_right);


		return 1 + std::min(l,r) ;
	}

private:

	size_t GetCompleteTreeLevelRecImpl(std::queue<BinNode> & level_nodes, const BinNode & delimiter_node, size_t level)
	{
		while(!level_nodes.empty())
		{
			BinNode node = level_nodes.front();
			level_nodes.pop();

			if(node._parent == delimiter_node._parent)
			{
				++level;
				if(!level_nodes.empty())
				{
					level_nodes.push(delimiter_node);
					return GetCompleteTreeLevelRecImpl(level_nodes, delimiter_node, level);
				}
			}

			if(node._left && node._right)
			{
				level_nodes.push(*(node._left));
				level_nodes.push(*(node._right));
			}
			else
				return level; 
		
		}
		
		return level;
	}


	BinNode * _root_node;

	BinNode * AddNewNodeToTreeReq(BinNode * node, int key, int value)
	{
		if(key > node->_key)
			if(node->_right != 0)
				return AddNewNodeToTreeReq(node->_right, key, value);
			else
			{
				node->_right = new BinNode(node, key, value);
				return node->_right;
			}

		if(node->_left != 0)
			return AddNewNodeToTreeReq(node->_left, key, value);
		else
		{
			node->_left = new BinNode(node, key, value);
			return node->_left;
		}

	}

	BinNode * AddNewNodeToTreeIter(BinNode * node, int key, int value)
	{
		BinNode * parent_node = node;
		while(node)
		{
			parent_node = node;
			if(key > node->_key)
				node = node->_right;
			else
				node = node->_left;
		}

		BinNode * new_node = new BinNode(parent_node, key, value);
		if(key > parent_node->_key)
			parent_node->_right = new_node;
		else
			parent_node->_left = new_node;

		return new_node;
	}


};
