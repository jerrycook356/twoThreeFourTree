#pragma once
#include "pch.h"
#include "QuadNode.h"


template<class ItemType>
class TwoThreeFourTree
{
private:
	QuadNode<ItemType>* rootPtr;

public:
	TwoThreeFourTree();
	bool add(const ItemType& newEntry);
	QuadNode<ItemType>* split(QuadNode<ItemType>* nodeToSplit);

};
#include "TwoThreeFourTree.cpp"