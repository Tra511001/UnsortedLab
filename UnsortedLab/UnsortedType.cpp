#include "UnsortedType.h"

#include<iostream>

using namespace std;

UnsortedType::UnsortedType() {
	length = 0;
	startPtr = NULL;
	currentPos = NULL;
}
UnsortedType::UnsortedType(int theLength) {
	length = theLength;
	startPtr = NULL;
	currentPos = NULL;
}
void UnsortedType::PutItem(ItemType item) {
	NodeType* temp = new NodeType;
	temp->data = item;
	temp->nextNode = startPtr; //the new node points to null
	startPtr = temp; //the starting node is pointing to the new node

	length++;

}

bool UnsortedType::IsFull() const {
	NodeType* location;
	try {
		location = new NodeType;
		delete location;
		return false;
	}
	catch(std::bad_alloc exception){
		return true;
	}
	 
}
int UnsortedType::GetLength() const {
	return length;
}

void UnsortedType::MakeEmpty(){
	NodeType* temp;
	while (startPtr != NULL) {
		temp = startPtr;//temp points to the node that the starting pointer is currently pointing
		startPtr = startPtr->nextNode;//start points at the next node
		delete temp;
	}
	length = 0;
}
ItemType UnsortedType::GetNextItem(ItemType item, bool& found) {
	NodeType* temp = startPtr;
	found = false;
	bool moreToSearch = (temp != NULL);
	while (moreToSearch && !found) {
		switch (item.ComparedTo(temp->data))
		{
		case LESS:
		case GREATER: temp = temp->nextNode;
			moreToSearch = (temp != NULL);
				break;
		case EQUAL: found = true;
			temp = temp->nextNode;
			moreToSearch = (temp != NULL);
			if (!moreToSearch) {
				cout << "ITEM IS NULL";
				item = temp->data;
			}
			else
				item = temp->data;
			break;
		}
	}
	return item;
}

void UnsortedType::DeleteItem(ItemType item) {// Deleting the first node must be a special case
	if (startPtr != NULL) {
		NodeType* temp = startPtr;
		if (item.ComparedTo(temp->data) == EQUAL) {// first case
			startPtr = startPtr->nextNode;
			delete temp;
			length--;
		}
		else {//second case
			while (temp->nextNode != NULL && (item.ComparedTo(temp->nextNode->data)) != EQUAL) {//while the next item is not the target
				temp = temp->nextNode;
			}
			NodeType* target = temp->nextNode;
			if (target != NULL) {
				temp->nextNode = target->nextNode;//skipping the node that gets deleted. Temp points to targets next node
				delete target;
				length--;
			}
		}
	}
}
/*
UnsortedType::~UnsortedType() {
	MakeEmpty();
}
/*void UnsortedType::Show() {
	NodeType* temp = startPtr;
	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->nextNode;
	}
}

void UnsortedType::DeleteItem(ItemType item) {
	if (startPtr !=NULL) {
		NodeType* temp = startPtr;
		if ( == startPtr->data) {
			startPtr = startPtr->nextNode;
			delete temp;
			length--;
		}
		else {
			while (temp->nextNode !=NULL && (!(item ==temp->nextNode->data))) {//while the next item is not the target
				temp = temp->nextNode;
			}
			NodeType* target = temp->nextNode;
			if (target != NULL) {
				temp->nextNode = target->nextNode;//skipping the node that gets deleted. Temp points to targets next node
				delete target;
				length--;
			}
		}
	}
}
void UnsortedType::ResetList() {
	
	while (startPtr != NULL) {
		DeleteItem(startPtr->data);
	}
}
 */