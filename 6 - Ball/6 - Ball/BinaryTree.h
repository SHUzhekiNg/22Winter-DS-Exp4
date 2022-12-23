#ifndef __BINNARY_TREE_H__
#define __BINNARY_TREE_H__
#include "Assistance.h"
#include "Node.h"
#include "BinTreeNode.h"

template <class ElemType>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(const ElemType& e);
	~BinaryTree();
	BinaryTree(const BinaryTree<ElemType>& t);
	BinaryTree<ElemType>& operator=(const BinaryTree<ElemType>& t);
	BinTreeNode<ElemType>* Root();
	void SetRoot(BinTreeNode<ElemType>& Root);

private:
	BinTreeNode<ElemType>* CopyTree(BinTreeNode<ElemType>* t);
	void Destroy(BinTreeNode<ElemType>*& r);
	BinTreeNode<ElemType>* Parent(BinTreeNode<ElemType>* r, const BinTreeNode<ElemType>* p) const;

	BinTreeNode<ElemType>* root;
};

template <class ElemType>
void BinaryTree<ElemType>::SetRoot(BinTreeNode<ElemType> &Root) {
    this->root = &Root;
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree()
{
	root = NULL;
}

template <class ElemType>
BinaryTree<ElemType>::~BinaryTree()
{
	Destroy(root);
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType &e)
{
	root = new BinTreeNode<ElemType>(e);
}

template <class ElemType>
BinTreeNode<ElemType> * BinaryTree<ElemType>::Parent(BinTreeNode<ElemType> *r, const BinTreeNode<ElemType> *p) const
{
	if (r == NULL)
       return NULL;
	else if (r->leftChild == p || r->rightChild == p)
       return r;
	else
	{
		BinTreeNode<ElemType> *tmp;
		tmp = Parent(r->leftChild, p);
		if (tmp != NULL)
           return tmp;
  
		tmp = Parent(r->rightChild, p);
		if (tmp != NULL)
           return tmp;
		else
           return NULL;
	}
}

template <class ElemType>
void BinaryTree<ElemType>::Destroy(BinTreeNode<ElemType> *&r)
{
	if(r != NULL)
	{
		Destroy(r->leftChild);
		Destroy(r->rightChild);
		delete r;
		r = NULL;
	}
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::CopyTree(BinTreeNode<ElemType> *t)
{
	if (t == NULL)
		return NULL;
	else
	{
		BinTreeNode<ElemType> *lChild = CopyTree(t->leftChild);
		BinTreeNode<ElemType> *rChild = CopyTree(t->rightChild);
		BinTreeNode<ElemType> *r = new BinTreeNode<ElemType>(t->data, lChild, rChild);
		return r;
	}
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType> &t)
{
	root = CopyTree(t.root);
}

template <class ElemType>
BinaryTree<ElemType> &BinaryTree<ElemType>::operator=(const BinaryTree<ElemType> &t)
{
	if (&t != this)
	{
		Destroy(root);
		root = CopyTree(t.root);
	}
	return *this;
}

template<class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::Root() {
    return this->root;
}

#endif
