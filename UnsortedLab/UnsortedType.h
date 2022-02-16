#pragma once
#include "NodeType.h"

class UnsortedType {
public:
	UnsortedType();
	void MakeEmpty();
	bool IsFull() const;
	int GetLength() const;
	NodeType GetItem(NodeType item, bool& found);
	void PutItem(int item);
	void DeleteItem(int item);
	void ResetList();
	NodeType GetNextItem();
	void Show();
	~UnsortedType();

private:
	int length;
	NodeType* startPtr;
};