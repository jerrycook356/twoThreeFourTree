#include "pch.h"
#include "TwoThreeFourTree.h"


template<class ItemType>
TwoThreeFourTree<ItemType>::TwoThreeFourTree()
{
	rootPtr = nullptr;
}

template<class ItemType>
bool TwoThreeFourTree<ItemType>::add(const ItemType& newEntry)
{
	QuadNode<ItemType>* tempNode = rootPtr;
	QuadNode<ItemType>* newNodePtr(newEntry);

	//locate the leaf node the newEntry belongs in
	if (tempNode == nullptr)  //tree is empty
	{
		
		rootPtr = newNodePtr;
	}
	if (rootPtr->isLeaf()) //tree not empty only rootPtr
	{
		if (rootPtr->getSmallItem() == -1) // no items in root
		{
			rootPtr->setSmallItem(newEntry);
		}
		else if ((rootPtr->getSmallItem() != -1) && (rootPtr->getMiddleItem == -1)&& 
			(rootPtr->getLargeItem() == -1)) //only small item in root
		{
			if (newEntry < rootPtr->getSmallItem())
			{
				rootPtr->setlargeItem(rootPtr->getSmallItem());
			}
			else
			{
				rootPtr->setLargeItem(newEntry);
			}
		}
		//two data items in root small item and large item
		else if ((rootPtr->getSmallItem() != -1) && (rootPtr->getLargeItem() != -1) && (rootPtr->getMiddleItem() == -1))
		{
			if (newEntry < rootPtr->getSmallItem())
			{
				rootPtr->setMiddleItem(rootPtr->getSmallItem());
				rootPtr->setSmallItem(newEntry);
			}
			if (newEntry > rootPtr->getSmallItem())
			{
				if (newEntry < rootPtr->getLargeItem())
				{
					rootPtr->setMiddleItem(newEntry);
				}
				else
				{
					rootPtr->setMiddleItem(rootPtr->getLargeItem());
					rootPtr->setLargeItem(newEntry);
				}
			}
		}
		else //root already contains three item, place item in correct spot then split 
		{
	     	TwoThreeFourTree<ItemType>::split(QuadeNode<ItemType>* rootPtr,ItemType& newEntry);

		}

	}


	
}

template<class ItemType>
QuadNode<ItemType>* TwoThreeFourTree<ItemType>::split(QuadNode<ItemType>* nodeToSplit)
{
	if (nodeToSplit == rootPtr)
	{
		QuadNode<ItemType>* newRootPtr(newEntry);
		QuadNode<ItemType>* newLeftChildPtr(rootPtr->getSmallItem());
		newLeftChildPtr->setLargeItem(rootPtr->getMiddleItem());
		QuadNode<Itemtype>* newRightChildPtr(rootPtr->getLargeItem());

		rootPtr = newRootPtr;
		rootPtr->setLeftChildPtr(newLeftChildPtr);
		rootPtr->setRightChildPtr(newRightChildPtr);
	}
	else
	{
		QuadNode<ItemType>* newLeftChild(nodeToSplit->getSmallItem());
		QuadNode<ItemType>* newRightChild(nodeToSplit->getLargeItem());
		QuadNode<ItemType>* newNodeAfterSplit(nodeToSplit->getMiddleItem());
		newNodeAfterSplit->setLeftChildPtr(newLeftChild);
		newNodeAfterSplit->setRightChildPtr(newRightChild);
		return newNodeAfterSplit;

	}
}
