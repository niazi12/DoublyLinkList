#include "DoublyLinkList.h"

#include <exception>
#include <iostream>

using namespace std;

template class DoublyLinkList<int>;
template class DoublyLinkList<char>;


template<class ItemType>
DoublyLinkList<ItemType>::DoublyLinkList()
{
	head = nullptr;
	tail = head;
	length = 0;
	iterator = nullptr;
}

template<class ItemType>
DoublyLinkList<ItemType>::~DoublyLinkList()
{
	makeEmpty();
}

template<class ItemType>
bool DoublyLinkList<ItemType>::isEmpty()
{
	return (length == 0);
}

template<class ItemType>
bool DoublyLinkList<ItemType>::isFull()
{
	try
	{
		NodeType<ItemType>* newNode = new NodeType<ItemType>(ItemType());
		delete newNode;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
		return true;
	}

	return false;
}

template<class ItemType>
void DoublyLinkList<ItemType>::makeEmpty()
{
	NodeType<ItemType> * tempPtr;


	while(head!= nullptr)
    {
        tempPtr = head;
        head = head->getNext();
        delete tempPtr;
    }

    length = 0;
    iterator = 0;
}

template<class ItemType>
int DoublyLinkList<ItemType>::getLength()
{
	return length;
}

template<class ItemType>
bool DoublyLinkList<ItemType>::hasNext()
{
	//Check if iterator's has reached tail.
	return (iterator != this->tail);
}

template<class ItemType>
bool DoublyLinkList<ItemType>::hasPrevious()
{
	//Check if iterator's is at begining.
	return (iterator != this->head);
}

template<class ItemType>
ItemType DoublyLinkList<ItemType>::getNext()
{

	if (hasNext())
	{
	    if (iterator == 0)
        {
            iterator = head;
        }
        else
        {
           iterator = iterator->getNext();
        }

		return (iterator->getData());
	}

	else
        cout << "No valid GetNext calls can be made." << endl;

	return 0;
}

template<class ItemType>
ItemType DoublyLinkList<ItemType>::getLast()
{

	if (hasPrevious())
	{
        if (iterator == 0)
        {
            iterator = tail;
        }
        else
        {
           iterator = iterator->getLast();
        }

		return (iterator->getData());

	}

	cout << "No valid GetPrevious calls can be made." << endl;
	return 0;
}

template<class ItemType>
bool DoublyLinkList<ItemType>::insert(ItemType item)
{
	if (isFull())
	{
		printContent();
		return false;
	}
	else
        insertFirst(item);

	return true;
}

template<class ItemType>
bool DoublyLinkList<ItemType>::insertFirst(ItemType item)
{
	if (isFull())
	{
		printContent();
		return false;
	}
	else
    {
        NodeType<ItemType>*newNode = new NodeType<ItemType>;
        newNode->setData(item);

        if(head == 0)
        {
            newNode->setNext(nullptr);
            newNode->setPrevious(nullptr);
            head = newNode;
            tail = newNode;
        }
        else
            newNode->setNext(head);
            head->setPrevious(newNode);
            head= newNode;


    }
	length ++;
    printContent();
    return true;
}

template<class ItemType>
bool DoublyLinkList<ItemType>::insertLast(ItemType item)
{
	if (isFull())
	{
		printContent();
		return false;
	}
	else
    {
        NodeType<ItemType>*newNode = new NodeType<ItemType>;
        newNode->setData(item);

        if(tail == 0)
        {
            newNode->setNext(nullptr);
            newNode->setPrevious(nullptr);
            head = newNode;
            tail = newNode;
        }
        else
            newNode->setNext(nullptr);
            newNode->setPrevious(tail);
            tail->setNext(newNode) ;
            tail= newNode;




    }

    length ++;
    printContent();
	return true;
}

template<class ItemType>
bool DoublyLinkList<ItemType>::deleteItem(ItemType item)
{
    bool found = false;

	if (isEmpty())
	{
		printContent();
		return false;
	}


	else
    {
        NodeType<ItemType>*location = head;
        NodeType<ItemType>*templocation;
        if(item==head->getData())
        {
            found= true;
            deleteFirst();

        }

        else if (item == tail->getData())
        {
            found= true;
            deleteLast();
        }

        else
        {
            while(!found)
            {
                if(item != (location->getNext()->getData()))
                {
                    location = location->getNext();
                    templocation = location ->getNext();

                }
                else
                    found = true;
            }

            if(found)
            {
                location ->setNext((location->getNext()->getNext()));
                (templocation->getNext())->setPrevious(location);

                if(iterator==location)
                {
                    iterator = iterator->getLast();
                }
                else
                    iterator = iterator;

            }
            else
                cout << "Item is not in the List"<< endl;

             delete templocation;
        }


    }

    length--;
	printContent();
	return found;
}

template<class ItemType>
bool DoublyLinkList<ItemType>::deleteFirst()
{
	if (isEmpty())
	{
		printContent();
		return false;
	}


    else
    {

        if(iterator == head)
        {
            iterator = iterator->getNext();
        }
        else
        {
           iterator= iterator;
        }

        NodeType<ItemType>*templocation=head;
        head = head->getNext();

        delete templocation;

        length--;

    }
    printContent();
    return true;
}




template<class ItemType>
bool DoublyLinkList<ItemType>::deleteLast()
{
	if (isEmpty())
	{
		printContent();
		return false;
	}



	else
    {
        if(iterator==tail)
        {
            iterator = iterator->getLast();
        }

        NodeType<ItemType>*templocation=tail;
        tail = tail->getLast();
        tail->setNext(nullptr);

        delete templocation;

    }

    length--;

	printContent();
	return true;
}

template<class ItemType>
void DoublyLinkList<ItemType>::printContent()
{
	NodeType<ItemType>* current = head;
	while (current)
	{
		cout << current->getData() << " ";
		current = current->getNext();
	}
	cout << endl;

}
