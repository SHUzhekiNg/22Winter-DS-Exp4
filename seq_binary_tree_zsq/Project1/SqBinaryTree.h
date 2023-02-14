#ifndef __SQ_BINNARY_TREE_H__
#define __SQ_BINNARY_TREE_H__

#include "Assistance.h"
#include "LinkQueue.h"

template<class ElemType>
class SqBinaryTree {
private:
    int maxSize;
    int *tag;
    ElemType *elems;

    int NodeCount(int r) const;

    void SetNodeEmpty(int p);

    void Destroy(int r);

    void PreOrder(int r, void (*Visit)(const ElemType &)) const;

    void InOrder(int r, void (*Visit)(const ElemType &)) const;

    void PostOrder(int r, void (*Visit)(const ElemType &)) const;

    void First_Seq_Create(int index);

    void First_Seq_Create();

    void Show(int index);


public:
    SqBinaryTree(int size);

    SqBinaryTree(const ElemType &e, int size);   // 建立以e为根的二叉树
    SqBinaryTree(const SqBinaryTree<ElemType> &t);            // 复制构造函数
    SqBinaryTree(ElemType es[], int ta[], int size);

    ~SqBinaryTree();

    int GetRoot() const;                                // 求二叉树中根结点
    bool IsNodeEmpty(int p) const;                        // 判断结点p是否为空
    Status GetElem(int p, ElemType &e);                    // 返回结点p的元素值
    Status SetElem(int p, const ElemType &e);            // 将结点p的值置为e
    bool IsEmpty() const;                                // 判断二叉树是否为空
    void InOrder(void (*Visit)(const ElemType &)) const;// 中序遍历二叉树
    void PreOrder(void (*Visit)(const ElemType &)) const;// 先序遍历二叉树
    void PostOrder(void (*Visit)(const ElemType &)) const;// 后序遍历二叉树
    void LevelOrder(void (*Visit)(const ElemType &)) const;// 层次遍历二叉树
    int NodeCount() const;                                // 求二叉树的结点个数
    int LeftChild(const int p) const;                    // 求二叉树中结点p的左孩子
    int RightChild(const int p) const;                    // 求二叉树中结点p的右孩子
    int LeftSibling(const int p) const;                    // 求二叉树中结点p的左兄弟
    int RightSibling(const int p) const;                // 求二叉树中结点p的右兄弟
    int Parent(const int p) const;                        // 求二叉树中结点p的双亲
    int Find(const ElemType &e) const;                        // 查找二叉树中元素e
    Status InsertLeftChild(int p, const ElemType &e);    // 插入元素作为结点p左孩子
    Status InsertRightChild(int p, const ElemType &e);  // 插入元素作为结点p右孩子
    Status DeleteLeftChild(int p);                        // 删除二叉树中结点p左子树
    Status DeleteRightChild(int p);                        // 删除二叉树中结点p右子村
    int Height() const;

    int Height(int index) const;

    int Deepth(int r) const;

    void Show();

    SqBinaryTree<ElemType> &operator=(const SqBinaryTree<ElemType> &t);

    int FindParent(int i, int j);
};


template<class ElemType>
void DisplayBTWithTreeShape(int r, int level);

template<class ElemType>
void DisplayBTWithTreeShape(SqBinaryTree<ElemType> &bt);

template<class ElemType>
void CreateBinaryTree(ElemType es[], int ta[], int r, ElemType pre[], ElemType in[],
                      int preLeft, int preRight, int inLeft, int inRight);

template<class ElemType>
SqBinaryTree<ElemType> &CreateBinaryTree(ElemType pre[], ElemType in[], int n, int size = DEFAULT_SIZE);


template<class ElemType>
int SqBinaryTree<ElemType>::FindParent(int i, int j) {
    if (tag[i] != 0 && tag[j] != 0) {
        if (i == j) return (i - 1) / 2 > 0 ? (i - 1) / 2 : 0;
        while (i != j) {
            if (i > j) {
                i = (i - 1) / 2;
            } else {
                j = (j - 1) / 2;
            }
        }
        return i;
    } else {
        return -1;
    }
}

template<class ElemType>
bool SqBinaryTree<ElemType>::IsNodeEmpty(int p) const {
    if (p < 0 || p >= maxSize || tag[p] == 0)
        return true;
    else
        return false;
}

template<class ElemType>
Status SqBinaryTree<ElemType>::GetElem(int p, ElemType &e) {
    if (IsNodeEmpty(p))
        return FAIL;
    else {
        e = elems[p];
        return SUCCESS;
    }
}

template<class ElemType>
Status SqBinaryTree<ElemType>::SetElem(int p, const ElemType &e) {
    if (IsNodeEmpty(p))
        return FAIL;
    else {
        elems[p] = e;
        return SUCCESS;
    }
}

template<class ElemType>
void SqBinaryTree<ElemType>::SetNodeEmpty(int p) {
    if (p >= 0 && p < maxSize && (2 * p + 1 >= maxSize || tag[2 * p + 1] == 0)
        && (2 * p + 2 >= maxSize || tag[2 * p + 2] == 0))
        tag[p] = 0;
}

template<class ElemType>
SqBinaryTree<ElemType>::~SqBinaryTree() {
    delete[]elems;
    delete[]tag;
}

template<class ElemType>
int SqBinaryTree<ElemType>::GetRoot() const {
    if (tag[0] == 1)
        return elems[0];
    else
        return -1;
}

template<class ElemType>
bool SqBinaryTree<ElemType>::IsEmpty() const {
    return IsNodeEmpty(0);
}

template<class ElemType>
void SqBinaryTree<ElemType>::PreOrder(int r, void (*Visit)(const ElemType &)) const {
    if (!IsNodeEmpty(r)) {
        (*Visit)(elems[r]);
        PreOrder(LeftChild(r), Visit);
        PreOrder(RightChild(r), Visit);
    }
}

template<class ElemType>
void SqBinaryTree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const {
    PreOrder(0, Visit);
}

template<class ElemType>
void SqBinaryTree<ElemType>::InOrder(int r, void (*Visit)(const ElemType &)) const {
    if (!IsNodeEmpty(r)) {
        InOrder(LeftChild(r), Visit);
        (*Visit)(elems[r]);
        InOrder(RightChild(r), Visit);
    }
}

template<class ElemType>
void SqBinaryTree<ElemType>::InOrder(void (*Visit)(const ElemType &)) const {
    InOrder(0, Visit);
}

template<class ElemType>
void SqBinaryTree<ElemType>::PostOrder(int r, void (*Visit)(const ElemType &)) const {
    if (!IsNodeEmpty(r)) {
        PostOrder(LeftChild(r), Visit);
        PostOrder(RightChild(r), Visit);
        (*Visit)(elems[r]);
    }
}

template<class ElemType>
void SqBinaryTree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const {
    PostOrder(0, Visit);
}

template<class ElemType>
void SqBinaryTree<ElemType>::LevelOrder(void (*Visit)(const ElemType &)) const {
    LinkQueue<int> q;
    int t = 0;

    if (!IsNodeEmpty(t))
        q.EnQueue(t);
    while (!q.IsEmpty()) {
        q.DelQueue(t);
        (*Visit)(elems[t]);
        if (!IsNodeEmpty(LeftChild(t)))
            q.EnQueue(LeftChild(t));
        if (!IsNodeEmpty(RightChild(t)))
            q.EnQueue(RightChild(t));
    }
}

template<class ElemType>
void SqBinaryTree<ElemType>::First_Seq_Create() {
    First_Seq_Create(0);
}

template<class ElemType>
void SqBinaryTree<ElemType>::First_Seq_Create(int index) {
    if (index > maxSize - 1) return;
    else {
        ElemType a;
        cin >> a;
        if (a == -1) {
            tag[index] = 0;
            return;
        }
        elems[index] = a;
        tag[index] = 1;
        First_Seq_Create(index * 2 + 1);
        First_Seq_Create(index * 2 + 2);
    }
}

template<class ElemType>
void SqBinaryTree<ElemType>::Show() {
    Show(0);
}

template<class ElemType>
void SqBinaryTree<ElemType>::Show(int index) {
    if (index >= maxSize) return;
    else {
        if (tag[index] == 1) {
            Show(2 * index + 2);
            int d = Deepth(index);
            for (int i = 0; i < d; ++i) cout << "  ";
            ElemType e;
            GetElem(index, e);
            cout << e << endl;
            Show(2 * index + 1);
        } else {
            return;
        }
    }
}

template<class ElemType>
int SqBinaryTree<ElemType>::Deepth(int index) const {
    if (tag[index] == 0) return -1;
    else {
        int deepth = 0;
        while (index > 0) {
            index = Parent(index);
            ++deepth;
        }
        return deepth;
    }
}

template<class ElemType>
int SqBinaryTree<ElemType>::Height() const {
    return Height(0);
}

template<class ElemType>
int SqBinaryTree<ElemType>::Height(int index) const {
    if (tag[index] == 0) return 0;
    else {
        int lheight = Height(index * 2 + 1);
        int rheight = Height(index * 2 + 2);
        return lheight > rheight ? lheight + 1 : rheight + 1;
    }
}

template<class ElemType>
int SqBinaryTree<ElemType>::NodeCount(int r) const {
    if (IsNodeEmpty(r))
        return 0;
    else
        return 1 + NodeCount(LeftChild(r)) + NodeCount(RightChild(r));
}

template<class ElemType>
int SqBinaryTree<ElemType>::NodeCount() const {
    return NodeCount(0);
}

template<class ElemType>
int SqBinaryTree<ElemType>::LeftChild(const int p) const {
    if (2 * p + 1 < maxSize && tag[2 * p + 1] == 1)
        return 2 * p + 1;
    else
        return -1;
}

template<class ElemType>
int SqBinaryTree<ElemType>::RightChild(const int p) const {
    if (2 * p + 2 < maxSize && tag[2 * p + 2] == 1)
        return 2 * p + 2;
    else
        return -1;
}

template<class ElemType>
int SqBinaryTree<ElemType>::LeftSibling(const int p) const {
    if (p % 2 == 1 || p == 0 || tag[p - 1] == 0)
        return -1;
    else
        return p - 1;
}

template<class ElemType>
int SqBinaryTree<ElemType>::RightSibling(const int p) const {
    if (p % 2 == 0 || p + 1 >= maxSize || tag[p + 1] == 0)
        return -1;
    else
        return p + 1;
}

template<class ElemType>
int SqBinaryTree<ElemType>::Parent(const int p) const {
    return (p - 1) / 2;
}

template<class ElemType>
int SqBinaryTree<ElemType>::Find(const ElemType &e) const {
    LinkQueue<int> q;
    int t = 0;

    if (!IsNodeEmpty(t))
        q.EnQueue(t);
    while (!q.IsEmpty()) {
        q.DelQueue(t);
        if (elems[t] == e)
            return t;
        if (!IsNodeEmpty(LeftChild(t)))
            q.EnQueue(LeftChild(t));
        if (!IsNodeEmpty(RightChild(t)))
            q.EnQueue(RightChild(t));
    }
    return -1;
}


template<class ElemType>
Status SqBinaryTree<ElemType>::InsertLeftChild(int p, const ElemType &e) {
    if (IsNodeEmpty(p))
        return FAIL;
    else {
        if (2 * p + 1 < maxSize && 2 * p + 1 > 0 && tag[2 * p + 1] == 0) {
            elems[2 * p + 1] = e;
            tag[2 * p + 1] = 1;
            return SUCCESS;
        } else
            return FAIL;
    }
}

template<class ElemType>
Status SqBinaryTree<ElemType>::InsertRightChild(int p, const ElemType &e) {
    if (IsNodeEmpty(p))
        return FAIL;
    else {
        if (2 * p + 2 < maxSize && 2 * p + 2 > 0 && tag[2 * p + 2] == 0) {
            elems[2 * p + 2] = e;
            tag[2 * p + 2] = 1;
            return SUCCESS;
        } else
            return FAIL;
    }
}

template<class ElemType>
Status SqBinaryTree<ElemType>::DeleteLeftChild(int p) {
    if (IsNodeEmpty(p))
        return FAIL;
    else {
        Destroy(LeftChild(p));
        return SUCCESS;
    }
}

template<class ElemType>
Status SqBinaryTree<ElemType>::DeleteRightChild(int p) {
    if (IsNodeEmpty(p))
        return FAIL;
    else {
        Destroy(RightChild(p));
        return SUCCESS;
    }
}

template<class ElemType>
void SqBinaryTree<ElemType>::Destroy(int r) {
    if (r >= 0 && r < maxSize && !IsNodeEmpty(r)) {
        Destroy(LeftChild(r));
        Destroy(RightChild(r));
        tag[r] = 0;
    }
}

template<class ElemType>
SqBinaryTree<ElemType>::SqBinaryTree(const ElemType &e, int size) {
    maxSize = size;
    elems = new ElemType[maxSize];
    tag = new int[maxSize];
    for (int i = 1; i < maxSize; i++)
        tag[i] = 0;
    tag[0] = 1;
    elems[0] = e;
}


template<class ElemType>
SqBinaryTree<ElemType>::SqBinaryTree(const SqBinaryTree<ElemType> &t) {
    maxSize = t.maxSize;
    elems = new ElemType[maxSize];
    tag = new int[maxSize];
    for (int i = 0; i < maxSize; i++) {
        elems[i] = t.elems[i];
        tag[i] = t.tag[i];
    }
}

template<class ElemType>
SqBinaryTree<ElemType>::SqBinaryTree(ElemType es[], int ta[], int size) {
    maxSize = size;
    elems = new ElemType[maxSize];
    tag = new int[maxSize];
    for (int i = 0; i < maxSize; i++) {
        elems[i] = es[i];
        tag[i] = ta[i];
    }
}

template<class ElemType>
SqBinaryTree<ElemType>::SqBinaryTree(int size) {
    maxSize = size;
    elems = new ElemType[size]();
    tag = new int[size]();
    First_Seq_Create();
}

template<class ElemType>
SqBinaryTree<ElemType> &SqBinaryTree<ElemType>::operator=(const SqBinaryTree<ElemType> &t) {
    if (&t != this) {
        delete[]elems;
        maxSize = t.maxSize;
        elems = new ElemType[maxSize];
        tag = new int[maxSize];

        for (int i = 0; i < maxSize; i++) {
            elems[i] = t.elems[i];
            tag[i] = t.tag[i];
        }
    }
    return *this;
}

template<class ElemType>
void DisplayBTWithTreeShape(SqBinaryTree<ElemType> &bt, int r, int level) {
    if (!bt.IsNodeEmpty(r)) {
        DisplayBTWithTreeShape<ElemType>(bt, bt.RightChild(r), level + 1);
        cout << endl;
        for (int i = 0; i < level - 1; i++)
            cout << "  ";
        ElemType e;
        bt.GetElem(r, e);
        cout << e;
        DisplayBTWithTreeShape<ElemType>(bt, bt.LeftChild(r), level + 1);
    }
}

template<class ElemType>
void DisplayBTWithTreeShape(SqBinaryTree<ElemType> &bt) {
    DisplayBTWithTreeShape<ElemType>(bt, 0, 1);
    cout << endl;
}
/*
template<class ElemType>
void CreateBinaryTree(ElemType es[], int ta[], int r, ElemType pre[], ElemType in[],
                      int preLeft, int preRight, int inLeft, int inRight) {
    if (inLeft <= inRight) {
        es[r] = pre[preLeft];
        ta[r] = 1;
        int mid = inLeft;
        while (in[mid] != pre[preLeft])
            mid++;
        CreateBinaryTree(es, ta, 2 * r + 1, pre, in, preLeft + 1, preLeft + mid - inLeft, inLeft, mid - 1);
        CreateBinaryTree(es, ta, 2 * r + 2, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1, inRight);
    }
}

template<class ElemType>
SqBinaryTree<ElemType> &CreateBinaryTree(ElemType pre[], ElemType in[], int n, int size) {
    ElemType *es = new ElemType[size];
    int *ta = new int[size];
    int r = 0;
    for (int i = 0; i < size; i++)
        ta[i] = 0;
    CreateBinaryTree<ElemType>(es, ta, r, pre, in, 0, n - 1, 0, n - 1);
    SqBinaryTree<ElemType> *bt = new SqBinaryTree<ElemType>(es, ta, size);
    delete[]es;
    delete[]ta;
    return *bt;
}
*/
#endif
