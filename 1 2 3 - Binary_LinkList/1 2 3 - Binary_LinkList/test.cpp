#include "BinaryTree.h"
int main()
{
	//初始化一个二叉树
	BinaryTree<int> test;
	test.Create();
	cout << "二叉树显示" << endl;
	test.show();
	cout << endl;
	cout << "先序遍历:" << endl;
	test.PreOrder(Write);
	cout << endl;
	cout << "中序遍历:" << endl;
	test.InOrder(Write);
	cout << endl;
	cout << "后序遍历:" << endl;
	test.PostOrder(Write);
	cout << endl;
	cout << "左右子树交换" << endl;
	test.Revolut();
	test.show();
	cout << endl;
	cout << "宽度为：" << test.CountBreadth() << endl;
	cout << "非递归中序遍历" << endl;
	test.NonRecurringInOrder();
	cout << endl;
	cout << "叶子结点个数：" << test.CountLeaf() << endl;
	
}
