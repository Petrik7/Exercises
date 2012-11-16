#pragma once
#include "BinTree.h"

class Summer
{
public:
	Summer(void);
	~Summer(void);

	static int SumValuesOfLeafs(BinNode * node)
	{
		if(node == 0)
			return 0;

		if(!node->_left && !node->_right)
			return node->_value;

		int sum = SumValuesOfLeafs(node->_left);
		sum += SumValuesOfLeafs(node->_right);
		return sum;
	}
};

