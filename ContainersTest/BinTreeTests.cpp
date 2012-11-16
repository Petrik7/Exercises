#include "StdAfx.h"
#include "BinTreeTests.h"

#include "BinTree.h"
#include "BinTreePinter.h"
#include "Summer.h"

BinTreeTests::BinTreeTests(void)
{
}

BinTreeTests::~BinTreeTests(void)
{
}

void BinTreeTests::Execute()
{
	BinTree tree;
	tree.Add(10, 10);
	tree.Add(20, 20);
	tree.Add(5, 5);
	tree.Add(30, 30);
	tree.Add(15, 15);
	tree.Add(7, 7);
	tree.Add(9, 9);
	tree.Add(3, 3);
	tree.Add(2, 2);
	tree.Add(4, 4);
	tree.Add(6, 6);


	BinTreePinter treePinter;
	treePinter.PrintTreeByLevels(tree);

	size_t li = tree.GetCompleteTreeLevelIter();
	size_t lr = tree.GetCompleteTreeLevelRec();
	size_t lo = tree.GetCompleteTreeLevelRecCC(tree.GetRootNode());


	int sum = Summer::SumValuesOfLeafs(tree.GetRootNode());
}