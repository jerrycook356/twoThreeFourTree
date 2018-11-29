/**@file QuadNode.h*/

#pragma once
#include"pch.h"

template<class ItemType>
class QuadNode
{
private:
	ItemType smallItem;
	ItemType middleItem;
	ItemType largeItem;
	QuadNode<ItemType>* leftChildPtr;
	QuadNode<ItemType>* leftMidChildPtr;
	QuadNode<ItemType>* rightMidChildPtr;
	QuadNode<ItemType>* rightChildPtr;


public:

	//constructors
	QuadNode<ItemType>(const ItemType& newItem);
	QuadNode<ItemType>(const ItemType& newSmallItem,const ItemType& newMiddleItem,
		const ItemType& largeItemType,QuadNode<ItemType>* leftChildPtr, QuadNode<ItemType>* leftMidChildPtr,
		QuadNode<ItemType>* rightMidChildPtr, QuadNode<ItemType>* rightChildPtr);
	

	//set Items methods
	void setSmallItem(const ItemType& newSmallItem);
	void setMiddleItem(const ItemType& newMiddleItem);
	void setLargeItem(const ItemType& newLargeItem);

	//return Item methods
	ItemType getSmallItem();
	ItemType getMiddleItem();
	ItemType getLargeItem();

	//set Child pointer methods
	void setLeftChildPtr(const QuadNode<ItemType>* newLeftChildPtr);
	void setLeftMidChildPtr(const QuadNode<ItemType>* newLeftMidChildPtr);
	void setRightMidChildPtr(const QuadNode<ItemType>* newRightMidChildPtr);
	void setRightChildPtr(const QuadNode<ItemType>* newRightChildPtr);

	//return child pointer methods
	QuadNode<ItemType>* getLeftChildPtr();
	QuadNode<ItemType>* getLeftMidChildPtr();
	QuadNode<ItemType>* getRightMidChildPtr();
	QuadNode<ItemType>* getRightChildPtr();

	//check methods
	bool isLeaf(); //no children, can have one,two or three data items.
	bool isTwoNode(); //two node has two children and one data item
	bool isThreeNode(); //three node has three children and two data items
	bool isFourNode(); //four node has four children and three data item.




};
#include "QuadNode.cpp"