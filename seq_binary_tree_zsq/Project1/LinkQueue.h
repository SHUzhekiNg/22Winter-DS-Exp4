#ifndef __LK_QUEUE_H__
#define __LK_QUEUE_H__

#include "Node.h"

template<class ElemType>
class LinkQueue {
public:
    LinkQueue();

    ~LinkQueue();

    int GetLength() const;

    bool IsEmpty() const;

    void Clear();

    void Traverse(void (*Visit)(const ElemType &)) const;

    Status DelQueue(ElemType &e);

    Status GetHead(ElemType &e) const;

    Status EnQueue(const ElemType e);

    LinkQueue(const LinkQueue<ElemType> &copy);

    LinkQueue<ElemType> &operator=(const LinkQueue<ElemType> &copy);

private:
    Node<ElemType> *front, *rear;
};


template<class ElemType>
LinkQueue<ElemType>::LinkQueue() {
    rear = front = new Node<ElemType>;
}

template<class ElemType>
LinkQueue<ElemType>::~LinkQueue() {
    Clear();
    delete front;
}

template<class ElemType>
int LinkQueue<ElemType>::GetLength() const {
    int count = 0;
    for (Node<ElemType> *p = front->next; p != NULL; p = p->next)
        count++;
    return count;
}

template<class ElemType>
bool LinkQueue<ElemType>::IsEmpty() const {
    return rear == front;
}

template<class ElemType>
void LinkQueue<ElemType>::Clear() {
    Node<ElemType> *p = front->next;
    while (p != NULL) {
        front->next = p->next;
        delete p;
        p = front->next;
    }
    rear = front;
}

template<class ElemType>
void LinkQueue<ElemType>::Traverse(void (*Visit)(const ElemType &)) const {
    for (Node<ElemType> *p = front->next; p != NULL; p = p->next)
        (*Visit)(p->data);
}


template<class ElemType>
Status LinkQueue<ElemType>::DelQueue(ElemType &e) {
    if (!IsEmpty()) {
        Node<ElemType> *p = front->next;
        e = p->data;
        front->next = p->next;
        if (rear == p)
            rear = front;
        delete p;
        return SUCCESS;
    } else
        return UNDER_FLOW;
}

template<class ElemType>
Status LinkQueue<ElemType>::GetHead(ElemType &e) const {
    if (!IsEmpty()) {
        e = front->next->data;
        return SUCCESS;
    } else
        return UNDER_FLOW;
}

template<class ElemType>
Status LinkQueue<ElemType>::EnQueue(const ElemType e) {
    Node<ElemType> *p;
    p = new Node<ElemType>(e);
    if (p) {
        rear->next = p;
        rear = rear->next;
        return SUCCESS;
    } else
        return OVER_FLOW;
}

template<class ElemType>
LinkQueue<ElemType>::LinkQueue(const LinkQueue<ElemType> &copy) {
    rear = front = new Node<ElemType>;
    for (Node<ElemType> *p = copy.front->next; p != NULL; p = p->next)
        EnQueue(p->data);
}

template<class ElemType>
LinkQueue<ElemType> &LinkQueue<ElemType>::operator=(const LinkQueue<ElemType> &copy) {
    if (&copy != this) {
        Clear();
        for (Node<ElemType> *p = copy.front->next; p != NULL; p = p->next)
            EnQueue(p->data);
    }
    return *this;
}

#endif
