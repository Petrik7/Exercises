#include "StdAfx.h"

#include "BinTreePinter.h"
#include "BinTree.h"

BinTreePinter::BinTreePinter(void)
{
}

BinTreePinter::~BinTreePinter(void)
{
}

void BinTreePinter::PrintTreeByLevels(const BinTree & bin_tree)
{
	_nodes_queue.push(*(bin_tree._root_node));
	BinNode * separator_node = new BinNode();
	_nodes_queue.push(BinNode(separator_node, 111, 111));
	PrintTreeNodes(_nodes_queue, RootNodeLeftPadding, separator_node);

	delete separator_node;
}
	

void BinTreePinter::PrintTreeNodes(std::queue<BinNode> & nodes_queue, size_t left_padding, BinNode * separator_node)
{
	if(nodes_queue.empty())
		return;

	bool all_nodes_are_empty = true;
	int node_num = 1;
	int PaddingStep = left_padding;
	BinNode node = nodes_queue.front();
	nodes_queue.pop();

	while(!IsSeparator(&node, separator_node))
	{
		all_nodes_are_empty = IsEmpty(node);

		ShiftRightFromCurrent(left_padding);
		std::cout << node._value;
		++node_num;
		if(!(node_num & 1))
			ShiftRightFromCurrent(left_padding);

		if(node._left)
			nodes_queue.push(*(node._left));
		else 
			nodes_queue.push(BinNode(0, 0, 0));

		if(node._right)
			nodes_queue.push(*(node._right));
		else
			nodes_queue.push(BinNode(0, 0, 0));

		node = nodes_queue.front();
		nodes_queue.pop();
	}

	std::cout << std::endl;

	if(all_nodes_are_empty)
		return;

	nodes_queue.push(BinNode(separator_node, 111, 111));
	PrintTreeNodes(nodes_queue, left_padding / 2, separator_node);
}

void BinTreePinter::ShiftRightFromCurrent(size_t number_positions)
{
	char space = ' ';
	std::string str(number_positions, space);
	std::cout << str;
}

bool BinTreePinter::IsSeparator(const BinNode * node, const BinNode * separator_node)
{
	return (node->_parent == separator_node) && (node->_key == 111);
}

bool BinTreePinter::IsEmpty(const BinNode & node)
{
	return (node._parent == 0) && (node._key == 0);
}