#ifndef NODETYPE_H
#define NODETYPE_H

template<class ItemType>
class NodeType
{
public:
	NodeType();
	NodeType(ItemType data);
	~NodeType();

	ItemType getData();
	NodeType<ItemType>* getNext();
	NodeType<ItemType>* getLast();

	void setData(ItemType data);
	void setNext(NodeType* next);
	void setPrevious(NodeType* previous);

private:
	ItemType data;
	NodeType<ItemType>* next;
	NodeType<ItemType>* previous;
};

#endif //NODETYPE_H
