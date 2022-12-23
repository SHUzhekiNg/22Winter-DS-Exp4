#ifndef __BIN_TREE_NODE_H__
#define __BIN_TREE_NODE_H__

template <class ElemType>
struct BinTreeNode
{
	ElemType data;
	BinTreeNode<ElemType>* leftChild;
	BinTreeNode<ElemType>  *rightChild;

	BinTreeNode();
	BinTreeNode(const ElemType &d,
		BinTreeNode<ElemType> *lChild = NULL, 
		BinTreeNode<ElemType> *rChild = NULL);
};

template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode()
{
	leftChild = rightChild = NULL;
}

template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode(const ElemType &d, 
	BinTreeNode<ElemType> *lChild, BinTreeNode<ElemType> *rChild)
{	
	data = d;
	leftChild = lChild;
	rightChild = rChild;
}

#endif

