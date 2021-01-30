#ifndef DOUBLY_LINK_LIST
#define DOUBLY_LINK_LIST

#include "NodeType.h"

template<class ItemType>
class DoublyLinkList
{
public:
	DoublyLinkList();
	~DoublyLinkList();

	bool isEmpty();
	bool isFull();
	void makeEmpty();
	int getLength();



	bool hasNext();
	bool hasPrevious();
	ItemType getNext();
	ItemType getLast();

	bool insert(ItemType item);
	bool insertFirst(ItemType item);
	bool insertLast(ItemType item);

	bool deleteItem(ItemType item);
	bool deleteFirst();
	bool deleteLast();

	void printContent();

private:
	NodeType<ItemType>* head;
	NodeType<ItemType>* tail;
	int length;
	NodeType<ItemType>* iterator;
};

#endif //UNSORTED_DOUBLY_LLIST
