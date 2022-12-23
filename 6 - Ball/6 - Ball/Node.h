#ifndef __NODE_H__
#define __NODE_H__

template <class ElemType>
struct Node 
{
	Node();
	Node(ElemType item, Node<ElemType>* link = NULL);

	ElemType data;
	Node<ElemType> *next;
};

template<class ElemType>
Node<ElemType>::Node()
{
	next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType> *link)
{
	data = item;
	next = link;
}

#endif
