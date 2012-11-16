#pragma once

#include <iostream>
#include <string>
#include <queue>

#include "BinTree.h"

//class BinTree;
//class BinNode;

class BinTreePinter
{
public:
	BinTreePinter(void);
	~BinTreePinter(void);
	static const size_t RootNodeLeftPadding = 30;
	//static const size_t PaddingStep = 3;

	std::queue<BinNode> _nodes_queue;

	void PrintTreeByLevels(const BinTree & bin_tree);

private:

	void PrintTreeNodes(std::queue<BinNode> & nodes_queue, size_t left_padding, BinNode * separator_node);
	void ShiftRightFromCurrent(size_t number_positions);
	bool IsSeparator(const BinNode * node, const BinNode * separator_node);
	bool IsEmpty(const BinNode & node);

};
