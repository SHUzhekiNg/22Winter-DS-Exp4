#include "SqBinaryTree.h"
using namespace std;
int main()
{
	int v[100], t[100], c = 1, size, p, q;
	cout << "�������Ĵ�С" << endl;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		v[i] = i+1;
		if (v[i] != 0)
			t[i] = 1;
		else
			t[i] = 0;
	}
	SqBinaryTree<int> a(v, t, size);
	cout << "�������" <<endl;
	while (c) 
	{
		cout << "��ѡ����Բ���:" << endl;
		cout << endl << "1. ��ʾ��";
		cout << endl << "2. ����ڵ�";
		cout << endl << "3. �������";
		cout << endl << "4. �������";
		cout << endl << "5. �������";
		cout << endl << "6. ��α���";
		cout << endl << "7. �����ĸ߶�";
		cout << endl << "8. ��������������еĸ�";
		cout << endl << "9. ����˫��";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ���� (0~9):";
		cin >> c;
		switch (c) {
		case 1:
			DisplayBTWithTreeShape(a);
			break;
		case 2:
			cout << "���ڵ��ǣ�" << a.GetRoot() << endl;
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
			cout << "������Ҫ��ѯ���������";
			cin >> p >> q;
			cout << a.FindParent(p, q);
			cout << endl;
			break;
		case 9:
			cout << "�����ѯ�Ľ��";
			cin >> p;
			cout << a.Parent(p);
			cout << endl;
			break;
		default:
			break;
		}
	}
	system("pause");

	return 0;
}