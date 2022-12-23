#ifndef __BINNARY_TREE_H__
#define __BINNARY_TREE_H__

#include "LinkQueue.h"
#include "BinTreeNode.h"

template <class ElemType>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(const ElemType &e);
	virtual ~BinaryTree();
	BinTreeNode<ElemType> *GetRoot() const;
	bool IsEmpty() const;
	Status GetElem(BinTreeNode<ElemType> *p, ElemType &e) const;
	Status SetElem(BinTreeNode<ElemType> *p, const ElemType &e);
	BinTreeNode<ElemType> *LeftChild(const BinTreeNode<ElemType> *p) const;
	BinTreeNode<ElemType> *RightChild(const BinTreeNode<ElemType> *p) const;
	BinTreeNode<ElemType> *LeftSibling(const BinTreeNode<ElemType> *p) const;
	BinTreeNode<ElemType>*RightSibling(const BinTreeNode<ElemType>*p) const;
	BinTreeNode<ElemType> *Parent(const BinTreeNode<ElemType> *p) const;
	BinTreeNode<ElemType> *Find(const ElemType &e) const;
	void InsertLeftChild(BinTreeNode<ElemType> *p, const ElemType &e);
	void InsertRightChild(BinTreeNode<ElemType> *p, const ElemType &e);
	void DeleteLeftChild(BinTreeNode<ElemType> *p);
	void DeleteRightChild(BinTreeNode<ElemType> *p);
	int	Height() const;	
	BinaryTree(const BinaryTree<ElemType> &t);
	BinaryTree(BinTreeNode<ElemType> *r);
	BinaryTree<ElemType> &operator=(const BinaryTree<ElemType>& t);
	BinTreeNode<ElemType>* Create();
	void show();
	void Sequence_traversal(BinTreeNode<ElemType>* b, ElemType* Level_Array, int i);
	void InOrder(void (*Visit)(const ElemType&)) const;
	void PreOrder(void (*Visit)(const ElemType&)) const;
	void PostOrder(void (*Visit)(const ElemType&)) const;
	int CountLeaf();
	void Revolut();
	int CountBreadth();
	void NonRecurringInOrder();

private:
	BinTreeNode<ElemType>* CopyTree(BinTreeNode<ElemType>* t);
	void PreOrder(BinTreeNode<ElemType>* r, void (*Visit)(const ElemType&)) const;
	void InOrder(BinTreeNode<ElemType>* r, void (*Visit)(const ElemType&)) const;
	void PostOrder(BinTreeNode<ElemType>* r, void (*Visit)(const ElemType&)) const;
	int Height(const BinTreeNode<ElemType>* r) const;
	void PostOrder2(BinTreeNode<ElemType>* r, int* v, int postion, int& count);
	void Destroy(BinTreeNode<ElemType>*& r);
	BinTreeNode<ElemType>* Parent(BinTreeNode<ElemType>* r,
	const BinTreeNode<ElemType>* p) const;

	BinTreeNode<ElemType>* root;
};
template<class ElemType>
void BinaryTree<ElemType>::NonRecurringInOrder()
{
	stack<BinTreeNode<ElemType>*> a;
	BinTreeNode<ElemType>* T = root;
	while (T != NULL || !a.empty()) 
	{
		while (T != NULL) {
			a.push(T);
			T = T->leftChild;
		}
		if (!a.empty()) {
			T = a.top();
			cout << T->data << " ";
			a.pop();
			T = T->rightChild;
		}
	}
}
template<class ElemType>
int BinaryTree<ElemType>::CountBreadth()
{
	LinkQueue<BinTreeNode<ElemType>*> a;
	BinTreeNode<ElemType>* T = root;
	a.EnQueue(root);
	int width = 0, size = 0;
	while (!a.IsEmpty())
	{
		size = a.GetLength();
		if (size > width) width = size;
		for (int i = 0; i < size; i++)
		{
			a.GetHead(T);
			if (T->leftChild != NULL)
			{
				a.EnQueue(T->leftChild);
			}
			if (T->rightChild != NULL)
			{
				a.EnQueue(T->rightChild);
			}
			a.DelQueue(T);
		}
	}
	return width;
}
template<class ElemType>
void BinaryTree<ElemType>::Revolut()
{
	BinTreeNode<ElemType>* T = root, * q;
	LinkQueue<BinTreeNode<ElemType>*> a;
	for (a.EnQueue(root); !a.IsEmpty(); a.DelQueue(T))
	{
		a.GetHead(T);
		if (T->leftChild != NULL)
		{
			a.EnQueue(T->leftChild);
		}
		if (T->rightChild != NULL)
		{
			a.EnQueue(T->rightChild);
		}
		q = T->leftChild;
		T->leftChild = T->rightChild;
		T->rightChild = q;
	}
}
template<class ElemType>
int BinaryTree<ElemType>::CountLeaf()
{
	BinTreeNode<ElemType>* T = root;
	LinkQueue<BinTreeNode<ElemType>*> a;
	int count = 0;
	for (a.EnQueue(root); !a.IsEmpty(); a.DelQueue(T))
	{
		a.GetHead(T);
		if (T->leftChild == NULL && T->rightChild == NULL)
		{
			count++;
			continue;
		}
		if (T->leftChild != NULL)
		{
			a.EnQueue(T->leftChild);
		}
		if (T->rightChild != NULL)
		{
			a.EnQueue(T->rightChild);
		}
	}
	return count;
}
template<class ElemType>
int BinaryTree<ElemType>::Height() const
{
	if (!root) return 0;
	int hl = Height(root->leftChild);
	int hr = Height(root->rightChild);
	if (hl > hr)
		return hl + 1;
	else
		return hr + 1;
	
}
template<class ElemType>
int BinaryTree<ElemType>::Height(const BinTreeNode<ElemType>* r) const
{
	if (!r) return 0;
	int hl = Height(r->leftChild);
	int hr = Height(r->rightChild);
	if (hl > hr)
		return hl + 1;
	else
		return hr + 1;
}

template<class ElemType>
void BinaryTree<ElemType>::PreOrder(void (*Visit)(const ElemType&)) const
{
	PreOrder(this->GetRoot(), Visit);
}
template<class ElemType>
void BinaryTree<ElemType>::PreOrder(BinTreeNode<ElemType>* r, void (*Visit)(const ElemType&)) const
{
	if (r != NULL)
	{
		(*Visit)(r->data);
		PreOrder(r->leftChild,Visit);
		PreOrder(r->rightChild, Visit);
	}
}
template<class ElemType>
void BinaryTree<ElemType>::InOrder(void (*Visit)(const ElemType&)) const
{
	InOrder(this->GetRoot(), Visit);
}
template<class ElemType>
void BinaryTree<ElemType>::InOrder(BinTreeNode<ElemType>* r, void (*Visit)(const ElemType&)) const
{
	if (r != NULL)
	{
		InOrder(r->leftChild, Visit);
		(*Visit)(r->data);
		InOrder(r->rightChild, Visit);
	}
}
template<class ElemType>
void BinaryTree<ElemType>::PostOrder(void (*Visit)(const ElemType&)) const
{
	PreOrder(this->GetRoot(), Visit);
}
template<class ElemType>
void BinaryTree<ElemType>::PostOrder(BinTreeNode<ElemType>* r, void (*Visit)(const ElemType&)) const
{
	if (r != NULL)
	{
		PostOrder(r->leftChild, Visit);
		PostOrder(r->rightChild, Visit);
		(*Visit)(r->data);
	}
}

template<class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::Create()
{
	ElemType a;
	BinTreeNode<ElemType> *T;
	cin >> a;
	if (a == 0)
	{
		T = NULL;
	}
	else {
		T = new BinTreeNode<ElemType>;
		T->data = a;
		T->leftChild = Create();
		T->rightChild = Create();
	}
	root = T;
	return T;
}
template<class ElemType>
void BinaryTree<ElemType>::Sequence_traversal(BinTreeNode<ElemType>* b, ElemType* Level_Array, int i)
{
	if (b->leftChild != NULL)      Sequence_traversal(b->leftChild, Level_Array, 2 * i + 1);
	if (b->rightChild != NULL)      Sequence_traversal(b->rightChild, Level_Array, 2 * i + 2);
	*(Level_Array + i) = b->data;
}
template<class ElemType>
void BinaryTree<ElemType>::PostOrder2(BinTreeNode<ElemType>* r, int *v, int position, int& count)
{
	if (r != NULL)
	{
		//cout << len(r->data);
		PostOrder2(r->rightChild, v, position + 2*len(r->data), count);
		v[count] = position;
		if (position != 0) cout << setw(position) << " ";// << "position" << position;
		cout << r->data << endl;
		PostOrder2(r->leftChild, v, position + 2*len(r->data), count);
	}
	else
	{
		v[count] = position;
		count++;
	}
	
}
template<class ElemType>
void BinaryTree<ElemType>::show()
{
	int v[100];
	int count = 0;
	PostOrder2(root, v, 0, count);
	
	/*ElemType v[100] = {NULL};
	int height = Height(root);
	cout << height << endl;
	Sequence_traversal(root, v, 0);
	BinTreeNode<ElemType>* T = root, q;
	LinkQueue<BinTreeNode<ElemType>*> a;
	for (int i = 0; i < height; i++)
	{
		int a = pow(2, height - i - 1) - 1;
		if (a != 0) cout << setw(a) << " ";
		int b = pow(2, height - i) - 1;
		for (int k = pow(2, i) - 1; k < pow(2, i + 1) - 1; k++)
		{
			if (k == pow(2, i + 1) - 2)
			{
				if (v[k] != NULL)
				{
					cout << v[k];
				}
				cout << endl;
				break;
			}
			if (v[k] != NULL)
				cout << v[k];
			else
				cout << " ";
			cout << setw(b) << " ";
		}
	}
	for (a.EnQueue(root); !a.IsEmpty(); a.DelQueue(T))
	{
		a.GetHead(T);
		cout << T->data;
		if (T->leftChild != NULL)
		{
			a.EnQueue(T->leftChild);
		}
		if (T->rightChild != NULL)
		{
			a.EnQueue(T->rightChild);
		}
	}*/
}
// 二叉树类的实现部分

template <class ElemType>
BinaryTree<ElemType>::BinaryTree()
// 操作结果：构造一个空二叉树
{
	root = NULL;
}

template <class ElemType>
BinaryTree<ElemType>::~BinaryTree()
// 操作结果：删除二叉树--析造函数
{
	Destroy(root);
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::GetRoot() const
// 操作结果：返回二叉树的根
{
	return root;
}

template <class ElemType>
bool BinaryTree<ElemType>::IsEmpty() const
// 操作结果：判断二叉树是否为空
{
	return root == NULL;
}

template <class ElemType>
Status BinaryTree<ElemType>::GetElem(BinTreeNode<ElemType> *p, ElemType &e) const
// 操作结果：用e返回结点p元素值,如果不存在结点p,函数返回NOT_PRESENT,否则返回ENTRY_FOUND
{
	if (p == NULL)		// 不存在结点p
		return NOT_PRESENT;			// 返回NOT_PRESENT
	else	{	// 存在结点p
		e = p->data;				// 用e返回元素值
		return ENTRY_FOUND;			// 返回ENTRY_FOUND
	}
}

template <class ElemType>
Status BinaryTree<ElemType>::SetElem(BinTreeNode<ElemType> *p, const ElemType &e)
// 操作结果：如果不存在结点p,则返回FAIL,否则返回SUCCESS,并将结点p的值设置为e
{
	if (p == NULL)		// 不存在结点p
		return FAIL;				// 返回FAIL
	else	{	// 存在结点p
		p->data = e;				// 将结点p的值设置为e
		return SUCCESS;				// 返回SUCCESS
	}
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType &e)
// 操作结果：建立以e为根的二叉树
{
	root = new BinTreeNode<ElemType>(e);
}


template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::LeftChild(const BinTreeNode<ElemType> *p) const
// 操作结果：返回二叉树结点p的左孩子
{
	return p->leftChild;
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::RightChild(const BinTreeNode<ElemType> *p) const
// 操作结果：返回二叉树结点p的右孩子
{
	return p->rightChild;
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::LeftSibling(const BinTreeNode<ElemType> *p) const
// 操作结果：返回二叉树结点p的左兄弟 
{
    BinTreeNode<ElemType> *r = Parent(root, p);
    if (r == NULL)
       return NULL;
    else if (r->rightChild == p)
	   return r->leftChild;
    else 
       return NULL;
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::RightSibling(const BinTreeNode<ElemType> *p) const
// 操作结果：返回二叉树结点p的左兄弟
{
    BinTreeNode<ElemType> *r = Parent(root, p);
    if (r == NULL)
       return NULL;
    else if (r->leftChild == p)
	   return r->rightChild;
    else 
       return NULL;
}


template <class ElemType>
BinTreeNode<ElemType> * BinaryTree<ElemType>::Parent(BinTreeNode<ElemType> *r, const BinTreeNode<ElemType> *p) const
// 操作结果：返回以r为根的二叉树, 结点p的双亲
{
	if (r == NULL)
       return NULL;		// 空二叉树
	else if (r->leftChild == p || r->rightChild == p)
       return r; // r为p的双亲
	else	{	// 在子树上求双亲
		BinTreeNode<ElemType> *tmp;
		tmp = Parent(r->leftChild, p);	// 在左子树上求p的双亲	
		if (tmp != NULL)
           return tmp;			        // 双亲在左子树上
  
		tmp = Parent(r->rightChild, p);	// 在右子树上求p的双亲	
		if (tmp != NULL)
           return tmp;			        // 双亲在右子树上
		else
           return NULL;				    // 表示p无双亲
	}
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::Parent(const BinTreeNode<ElemType> *p) const
// 操作结果：返回二叉树结点p的双亲
{
	return Parent(root, p);
}

template <class ElemType>
void BinaryTree<ElemType>::InsertLeftChild(BinTreeNode<ElemType> *p, const ElemType &e)
// 初始条件：p非空，
// 操作结果：插入元素值为e的结点为p的左孩子，如果p的左孩子非空，则p原有左子树成为e的左子树
{
	if (p == NULL)	// p空，返回
		return;
	else 	{	// 插入左孩子
		BinTreeNode<ElemType> *child =  new BinTreeNode<ElemType>(e);// 元素值为e结点
		if (p->leftChild != NULL)	// p的左孩子非空
			child->leftChild = p->leftChild;	// p原有左子树成为e的左子树
		p->leftChild = child;					// e成为p的左孩子
		return;
	}
}

template <class ElemType>
void BinaryTree<ElemType>::InsertRightChild(BinTreeNode<ElemType> *p, const ElemType &e)
// 初始条件：p非空
// 操作结果：插入元素值为e的结点为p的右孩子，如果p的右孩子非空，则p原有右子树成为e的右子树
{
	if (p == NULL)	// p为空，返回
		return;
	else	{	// 插入右孩子
		BinTreeNode<ElemType> *child =  new BinTreeNode<ElemType>(e);// 元素值为e结点
		if (p->rightChild != NULL)	// p的右孩子非空
			child->rightChild = p->rightChild;	// p原有右子树成为e的右子树
		p->rightChild = child;					// e成为p的右孩子
		return;
	}
}

template <class ElemType>
void BinaryTree<ElemType>::DeleteLeftChild(BinTreeNode<ElemType> *p)
// 初始条件：p非空
// 操作结果：删除p左子树
{
	if (p == NULL)	// p为空
		return;
	else	// p非空
		Destroy(p->leftChild);	// 删除p左子树
}

template <class ElemType>
void BinaryTree<ElemType>::DeleteRightChild(BinTreeNode<ElemType> *p)
// 初始条件：p非空
// 操作结果：删除p右子树
{
	if (p == NULL)	// p为空
		return;
	else	// p非空
		Destroy(p->rightChild);	// 删除p右子树
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::Find(const ElemType &e) const
// 操作结果：返回二叉树结点p的双亲
{
	LinkQueue<BinTreeNode<ElemType> *> q;	// 定义队列q
	BinTreeNode<ElemType> *p;
	
	if (root != NULL) q.EnQueue(root);		// 如果根非空,则入队
	while (!q.IsEmpty())	{	            // q非空,说明还有结点未访问
		q.DelQueue(p);                      // 队头元素出队，并访问之 
		if (p->data == e)
			return p;
		if (p->leftChild != NULL)			// 队头元素左孩子非空
			q.EnQueue(p->leftChild);		// 左孩子入队
		if (p->rightChild != NULL)			// 队头元素右孩子非空
			q.EnQueue(p->rightChild);		// 右孩子入队
	}
	return NULL;
}


template <class ElemType>
void BinaryTree<ElemType>::Destroy(BinTreeNode<ElemType> *&r)
// 操作结果：删除以r的二叉树
{
	if(r != NULL)	{	// r非空,实施删除
		Destroy(r->leftChild);		// 删除左子树
		Destroy(r->rightChild);		// 删除右子树
		delete r;					// 删除根结点
		r = NULL;
	}
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::CopyTree(BinTreeNode<ElemType> *t)
// 操作结果：将以t为根的二叉树复制成新的二叉树,返回新二叉树的根
{
	if (t == NULL)	// 复制空二叉树
		return NULL;					// 空二叉树根为空	
	else	{	// 复制非空二叉树
		BinTreeNode<ElemType> *lChild = CopyTree(t->leftChild);	// 复制左子树
		BinTreeNode<ElemType> *rChild = CopyTree(t->rightChild);	// 复制右子树
		BinTreeNode<ElemType> *r = new BinTreeNode<ElemType>(t->data, lChild, rChild);
			// 复制根结点
		return r;
	}
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType> &t)
// 操作结果：由已知二叉树构造新二叉树——复制构造函数
{
	root = CopyTree(t.root);	// 复制二叉树
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree(BinTreeNode<ElemType> *r)
// 操作结果：建立以r为根的二叉树
{	
	root = r;	// 复制二叉树
}

template <class ElemType>
BinaryTree<ElemType> &BinaryTree<ElemType>::operator=(const BinaryTree<ElemType> &t)
// 操作结果：由已知二叉树t复制到当前二叉树--赋值运算符重载
{
	if (&t != this)	{
		Destroy(root);				// 释放原二叉树所占用空间
		root = CopyTree(t.root);	// 复制二叉树
	}
	return *this;
}

#endif
