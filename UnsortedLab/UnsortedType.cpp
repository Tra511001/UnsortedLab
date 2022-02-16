#include "UnsortedType.h"
#include<iostream>

using namespace std;

UnsortedType::UnsortedType() {
	length = 0;
	startPtr = NULL;
}
void UnsortedType::PutItem(int item) {
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
void UnsortedType::MakeEmpty() {
	NodeType* temp;
	while (startPtr != NULL) {
		temp = startPtr;//temp points to the node that the starting pointer is currently pointing
		startPtr = startPtr->nextNode;//start points at the next node
		delete temp;
	}
	length = 0;
}
UnsortedType::~UnsortedType() {
	MakeEmpty();
}
int UnsortedType::GetLength() const {
	return length;
}
void UnsortedType::Show() {
	NodeType* temp = startPtr;
	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->nextNode;
	}
}
void UnsortedType::DeleteItem(int item) {
	if (startPtr !=NULL) {
		NodeType* temp = startPtr;
		if (item == startPtr->data) {
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
				temp->nextNode = target->nextNode;
				delete target;
				length--;
			}
		}
	}
}
 
