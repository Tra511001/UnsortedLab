#pragma once
#include "ItemType.h"
#define UNSORTEDTYPE_H

struct NodeType{ // a struct containing the users datta as well as a pointer to the next node
	NodeType();
	ItemType data;
	NodeType* nextNode;
};

class UnsortedType {
public:
	UnsortedType();
	UnsortedType(int x);
	void MakeEmpty();
	bool IsFull() const;
	int GetLength() const;
	void PutItem(ItemType item);
	void DeleteItem(ItemType item);
	//void ResetList();
	//void Show();
	ItemType GetNextItem(ItemType item, bool&);
	
	//~UnsortedType();

private:
	int length;// length of the list
	NodeType* startPtr;
	NodeType* currentPos;// ceeps track of the current position during an iteration used for resetList and getNextMember
};