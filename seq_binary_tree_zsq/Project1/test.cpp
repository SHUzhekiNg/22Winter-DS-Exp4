#include "SqBinaryTree.h"

using namespace std;

int main() {
    cout << "请输入先序构造序列(-1表示空节点):" << endl;
    /*int v[100], t[100], c = 1, size, p, q;
    cout << "输入树的大小" << endl;
    cin >> size;
    for (int i = 0; i < size; i++) {
        v[i] = i + 1;
        if (v[i] != 0)
            t[i] = 1;
        else
            t[i] = 0;
    }
    SqBinaryTree<int> a(v, t, size);*/
    SqBinaryTree<int> a(100);
    int c = 1, p, q,e;
    cout << "构筑完成" << endl;
    while (c) {
        cout << "请选择测试操作:" << endl;
        cout << endl << "1. 显示树";
        cout << endl << "2. 求根节点";
        cout << endl << "3. 先序遍历";
        cout << endl << "4. 中序遍历";
        cout << endl << "5. 后序遍历";
        cout << endl << "6. 层次遍历";
        cout << endl << "7. 求树的高度";
        cout << endl << "8. 求两个结点所共有的根";
        cout << endl << "9. 结点的双亲";
        cout << endl << "0. 退出";
        cout << endl << "选择功能 (0~9):";
        cin >> c;
        switch (c) {
            case 1:
                a.Show();
                break;
            case 2:
                cout << "根节点是：" << a.GetRoot() << endl;
                break;
            case 3:
                a.PreOrder(Write);
                cout << endl;
                break;
            case 4:
                a.InOrder(Write);
                cout << endl;
                break;
            case 5:
                a.PostOrder(Write);
                cout << endl;
                break;
            case 6:
                a.LevelOrder(Write);
                cout << endl;
                break;
            case 7:
                cout << a.Height();
                cout << endl;
                break;
            case 8:
                cout << "请输入要查询的两个数值";
                cin >> p >> q;
                cout << "数组下标：" << a.FindParent(a.Find(p),a.Find(q)) << endl;
                 a.GetElem(a.FindParent(a.Find(p), a.Find(q)),e);
                cout << "元素值:" << e << endl;
                break;
            case 9:
                cout << "输入查询的结点的数据";
                cin >> p;
                a.GetElem(a.Parent(a.Find(p)),e);
                cout << "数组下标:" << a.Find(e) << endl;
                cout << "元素值:" << e << endl;
                break;
            default:
                break;
        }
    }
    system("pause");

    return 0;
}