#include "ItemType.h"

ItemType::ItemType() {
	value = 0;
}
void ItemType::Initalize(int number) {
	value = number;
}
relationType ItemType::ComparedTo(ItemType item) {
	
	if (value < item.value) {
		return LESS;
	}
	else if (value > item.value) {
		return GREATER;
	}
	else return EQUAL;

}