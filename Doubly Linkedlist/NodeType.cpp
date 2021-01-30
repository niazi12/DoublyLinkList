#include "NodeType.h"
#include <iostream>

template class NodeType<int>;
template class NodeType<char>;

template<class ItemType>
NodeType<ItemType>::NodeType()
{
	this->data = ItemType();
	this->next = nullptr;
	this->previous = nullptr;
}

template<class ItemType>
NodeType<ItemType>::NodeType(ItemType data)
{
	this->data = data;
	this->next = nullptr;
	this->previous = nullptr;
}

template<class ItemType>
NodeType<ItemType>::~NodeType()
{
}

template<class ItemType>
void NodeType<ItemType>::setData(ItemType data)
{
	this->data = data;
}

template<class ItemType>
ItemType NodeType<ItemType>::getData()
{
	return this->data;
}

template<class ItemType>
void NodeType<ItemType>::setNext(NodeType * next)
{
	this->next = next;
}

template<class ItemType>
void NodeType<ItemType>::setPrevious(NodeType * previous)
{
	this->previous = previous;
}

template<class ItemType>
NodeType<ItemType>* NodeType<ItemType>::getNext()
{
	return this->next;
}

template<class ItemType>
NodeType<ItemType>* NodeType<ItemType>::getLast()
{
	return this->previous;
}
