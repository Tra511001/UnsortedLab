#pragma once
#define ITEMTYPE_H
#include "UnsortedType.h"
using namespace std;

int const MAX_ITEMS = 100;
enum relationType{LESS, GREATER, EQUAL};

class ItemType {
public:
	ItemType();
	void Initalize(int number);
	relationType ComparedTo(ItemType item);
	int value;
};