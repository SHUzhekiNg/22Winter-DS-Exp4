#include "BinaryTree.h"
int main()
{
	//��ʼ��һ��������
	BinaryTree<int> test;
	test.Create();
	cout << "��������ʾ" << endl;
	test.show();
	cout << endl;
	cout << "�������:" << endl;
	test.PreOrder(Write);
	cout << endl;
	cout << "�������:" << endl;
	test.InOrder(Write);
	cout << endl;
	cout << "�������:" << endl;
	test.PostOrder(Write);
	cout << endl;
	cout << "������������" << endl;
	test.Revolut();
	test.show();
	cout << endl;
	cout << "���Ϊ��" << test.CountBreadth() << endl;
	cout << "�ǵݹ��������" << endl;
	test.NonRecurringInOrder();
	cout << endl;
	cout << "Ҷ�ӽ�������" << test.CountLeaf() << endl;
	
}
