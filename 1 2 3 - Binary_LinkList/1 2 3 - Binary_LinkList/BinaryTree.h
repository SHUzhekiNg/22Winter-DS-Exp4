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
// ���������ʵ�ֲ���

template <class ElemType>
BinaryTree<ElemType>::BinaryTree()
// �������������һ���ն�����
{
	root = NULL;
}

template <class ElemType>
BinaryTree<ElemType>::~BinaryTree()
// ���������ɾ��������--���캯��
{
	Destroy(root);
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::GetRoot() const
// ������������ض������ĸ�
{
	return root;
}

template <class ElemType>
bool BinaryTree<ElemType>::IsEmpty() const
// ����������ж϶������Ƿ�Ϊ��
{
	return root == NULL;
}

template <class ElemType>
Status BinaryTree<ElemType>::GetElem(BinTreeNode<ElemType> *p, ElemType &e) const
// �����������e���ؽ��pԪ��ֵ,��������ڽ��p,��������NOT_PRESENT,���򷵻�ENTRY_FOUND
{
	if (p == NULL)		// �����ڽ��p
		return NOT_PRESENT;			// ����NOT_PRESENT
	else	{	// ���ڽ��p
		e = p->data;				// ��e����Ԫ��ֵ
		return ENTRY_FOUND;			// ����ENTRY_FOUND
	}
}

template <class ElemType>
Status BinaryTree<ElemType>::SetElem(BinTreeNode<ElemType> *p, const ElemType &e)
// �����������������ڽ��p,�򷵻�FAIL,���򷵻�SUCCESS,�������p��ֵ����Ϊe
{
	if (p == NULL)		// �����ڽ��p
		return FAIL;				// ����FAIL
	else	{	// ���ڽ��p
		p->data = e;				// �����p��ֵ����Ϊe
		return SUCCESS;				// ����SUCCESS
	}
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType &e)
// ���������������eΪ���Ķ�����
{
	root = new BinTreeNode<ElemType>(e);
}


template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::LeftChild(const BinTreeNode<ElemType> *p) const
// ������������ض��������p������
{
	return p->leftChild;
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::RightChild(const BinTreeNode<ElemType> *p) const
// ������������ض��������p���Һ���
{
	return p->rightChild;
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::LeftSibling(const BinTreeNode<ElemType> *p) const
// ������������ض��������p�����ֵ� 
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
// ������������ض��������p�����ֵ�
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
// ���������������rΪ���Ķ�����, ���p��˫��
{
	if (r == NULL)
       return NULL;		// �ն�����
	else if (r->leftChild == p || r->rightChild == p)
       return r; // rΪp��˫��
	else	{	// ����������˫��
		BinTreeNode<ElemType> *tmp;
		tmp = Parent(r->leftChild, p);	// ������������p��˫��	
		if (tmp != NULL)
           return tmp;			        // ˫������������
  
		tmp = Parent(r->rightChild, p);	// ������������p��˫��	
		if (tmp != NULL)
           return tmp;			        // ˫������������
		else
           return NULL;				    // ��ʾp��˫��
	}
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::Parent(const BinTreeNode<ElemType> *p) const
// ������������ض��������p��˫��
{
	return Parent(root, p);
}

template <class ElemType>
void BinaryTree<ElemType>::InsertLeftChild(BinTreeNode<ElemType> *p, const ElemType &e)
// ��ʼ������p�ǿգ�
// �������������Ԫ��ֵΪe�Ľ��Ϊp�����ӣ����p�����ӷǿգ���pԭ����������Ϊe��������
{
	if (p == NULL)	// p�գ�����
		return;
	else 	{	// ��������
		BinTreeNode<ElemType> *child =  new BinTreeNode<ElemType>(e);// Ԫ��ֵΪe���
		if (p->leftChild != NULL)	// p�����ӷǿ�
			child->leftChild = p->leftChild;	// pԭ����������Ϊe��������
		p->leftChild = child;					// e��Ϊp������
		return;
	}
}

template <class ElemType>
void BinaryTree<ElemType>::InsertRightChild(BinTreeNode<ElemType> *p, const ElemType &e)
// ��ʼ������p�ǿ�
// �������������Ԫ��ֵΪe�Ľ��Ϊp���Һ��ӣ����p���Һ��ӷǿգ���pԭ����������Ϊe��������
{
	if (p == NULL)	// pΪ�գ�����
		return;
	else	{	// �����Һ���
		BinTreeNode<ElemType> *child =  new BinTreeNode<ElemType>(e);// Ԫ��ֵΪe���
		if (p->rightChild != NULL)	// p���Һ��ӷǿ�
			child->rightChild = p->rightChild;	// pԭ����������Ϊe��������
		p->rightChild = child;					// e��Ϊp���Һ���
		return;
	}
}

template <class ElemType>
void BinaryTree<ElemType>::DeleteLeftChild(BinTreeNode<ElemType> *p)
// ��ʼ������p�ǿ�
// ���������ɾ��p������
{
	if (p == NULL)	// pΪ��
		return;
	else	// p�ǿ�
		Destroy(p->leftChild);	// ɾ��p������
}

template <class ElemType>
void BinaryTree<ElemType>::DeleteRightChild(BinTreeNode<ElemType> *p)
// ��ʼ������p�ǿ�
// ���������ɾ��p������
{
	if (p == NULL)	// pΪ��
		return;
	else	// p�ǿ�
		Destroy(p->rightChild);	// ɾ��p������
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::Find(const ElemType &e) const
// ������������ض��������p��˫��
{
	LinkQueue<BinTreeNode<ElemType> *> q;	// �������q
	BinTreeNode<ElemType> *p;
	
	if (root != NULL) q.EnQueue(root);		// ������ǿ�,�����
	while (!q.IsEmpty())	{	            // q�ǿ�,˵�����н��δ����
		q.DelQueue(p);                      // ��ͷԪ�س��ӣ�������֮ 
		if (p->data == e)
			return p;
		if (p->leftChild != NULL)			// ��ͷԪ�����ӷǿ�
			q.EnQueue(p->leftChild);		// �������
		if (p->rightChild != NULL)			// ��ͷԪ���Һ��ӷǿ�
			q.EnQueue(p->rightChild);		// �Һ������
	}
	return NULL;
}


template <class ElemType>
void BinaryTree<ElemType>::Destroy(BinTreeNode<ElemType> *&r)
// ���������ɾ����r�Ķ�����
{
	if(r != NULL)	{	// r�ǿ�,ʵʩɾ��
		Destroy(r->leftChild);		// ɾ��������
		Destroy(r->rightChild);		// ɾ��������
		delete r;					// ɾ�������
		r = NULL;
	}
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::CopyTree(BinTreeNode<ElemType> *t)
// �������������tΪ���Ķ��������Ƴ��µĶ�����,�����¶������ĸ�
{
	if (t == NULL)	// ���ƿն�����
		return NULL;					// �ն�������Ϊ��	
	else	{	// ���Ʒǿն�����
		BinTreeNode<ElemType> *lChild = CopyTree(t->leftChild);	// ����������
		BinTreeNode<ElemType> *rChild = CopyTree(t->rightChild);	// ����������
		BinTreeNode<ElemType> *r = new BinTreeNode<ElemType>(t->data, lChild, rChild);
			// ���Ƹ����
		return r;
	}
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType> &t)
// �������������֪�����������¶������������ƹ��캯��
{
	root = CopyTree(t.root);	// ���ƶ�����
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree(BinTreeNode<ElemType> *r)
// ���������������rΪ���Ķ�����
{	
	root = r;	// ���ƶ�����
}

template <class ElemType>
BinaryTree<ElemType> &BinaryTree<ElemType>::operator=(const BinaryTree<ElemType> &t)
// �������������֪������t���Ƶ���ǰ������--��ֵ���������
{
	if (&t != this)	{
		Destroy(root);				// �ͷ�ԭ��������ռ�ÿռ�
		root = CopyTree(t.root);	// ���ƶ�����
	}
	return *this;
}

#endif
