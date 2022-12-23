#include "BinaryTree.h"

BinTreeNode<int> * BuildFullTree(int h){        // 根据层数n构建满二叉树，并返回根节点的值 当结点数值域为0是则代表关闭，为1时则代表开启
    auto * BinNodeArr = new BinTreeNode<int>[ int( pow(2,h) ) - 1 ];
    for (int i = 0; i < pow(2,h) - 1; ++i) {
        BinNodeArr[i].data = 0;
        if ( 2 * i + 1 < pow(2,h) - 1 )
            BinNodeArr[i].leftChild = &BinNodeArr[2 * i + 1];
        if (2 * i + 2 < pow(2,h) - 1 )
            BinNodeArr[i].rightChild = &BinNodeArr[2 * i + 2];
    }
    auto * Tree = new BinaryTree<int>;
    Tree->SetRoot(BinNodeArr[0]);
    return Tree->Root();
}

int Ball(BinTreeNode<int> * node){
    long i = 0;
    while (node->leftChild != nullptr && node->rightChild != nullptr){
        if (node->data == 0)
        {
            i = 2 * i + 1;
            node->data = 1;
            node = node->leftChild;
        }
        else
        {
            i = 2 * i + 2;
            node->data = 0;
            node = node->rightChild;
        }
    }
    return i;
}

int GoBall(BinTreeNode<int> *Root,int n){
    long num;
    for (int i = 0; i < n; ++i) {
        num = Ball(Root);
    }
    return num + 1;
}

int main() {
    while (1)
    {
        int h, n;  // 满二叉树的层数    放入小球个数
        cin >> h >> n;
        BinTreeNode<int> *Root = BuildFullTree(h);
        cout << GoBall(Root, n) << endl;
    }
}
