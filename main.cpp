/*
������ ���
1. ���� ����
2. �� ��
3. �� ��
4. ��ü�� �ܾ���ȸ

// ������ ���¹�ȣ�� �ߺ����� �ƴ��Ѵ�.
// �Ա� �� ��ݾ��� ������ 0���� ũ��
// ���� ���������� ���¹�ȣ, ���̸�, ���� �ܾ� �̷��� 3������ ���� �� �����Ѵ�.
// �� �̻��� �� ���� ������ ���ؼ� �迭�� ����Ѵ�.
// ���¹�ȣ�� ������ �����̴�.
*/

#include <iostream>
#include "AccountHandler.h"

using namespace std;

void main()
{
	int choice(0);
	AccountHandler Ah; // ��Ʈ�� Ŭ����

	while (choice != 5)
	{
		cout << "----Menu----" << endl;
		cout << "1. ���� ����" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. ���� ���� ��ü ���" << endl;
		cout << "5.���α׷� ����" << endl;
		//
		cout << "���� : ";
		cin >> choice;
		cout << endl;
		
		switch (choice)
		{
		case 1:
			Ah.makeAccount();
			break;
		case 2:
			Ah.inputMoney();
			break;
		case 3:
			Ah.outputMoney();
			break;
		case 4:
			Ah.showAccount();
			break;
		default:
			cout << " " << endl;
			cout << "���α׷��� ����Ǿ����ϴ�" << endl;
			break;
		}
	}

}












