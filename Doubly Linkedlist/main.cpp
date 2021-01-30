#include<iostream>

#include "DoublyLinkList.h"

using namespace std;

int main(void)
{
	DoublyLinkList<int> list;
	cout << "Current List Size :" << list.getLength() << endl;
	list.insert(5);
	list.insert(8);
	list.insert(9);
	list.insert(7);
	list.insertFirst(1);
	list.insertFirst(12);
	list.insertLast(16);
	list.insertFirst(122);
	list.insertLast(89);
	list.deleteItem(8);
	list.deleteFirst();
	list.deleteLast();


    cout<<"Head is "<<list.getNext();

	return 0;
}
