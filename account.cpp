#include "account.h"


Account::Account(int ID, int money, char* cus_name) :AccountID(ID), balance(money) // ������
{
	Name = new char[strlen(cus_name) + 1]; // �޸� ���� �Ҵ�
	strcpy_s(Name, strlen(cus_name) + 1, cus_name); // ���� �Ҵ�� �޸� �ʱ�ȭ
}


Account::Account(const Account &Other) :AccountID(Other.AccountID), balance(Other.balance) // ���� ������ ����
{
	Name = new char[strlen(Other.Name) + 1];
	strcpy_s(Name, strlen(Other.Name) + 1, Other.Name);
}


Account::~Account() { delete[] Name; }; //�ı���


int Account::GetID() const { return AccountID; } // ���¹�ȣ Ȯ��


void Account::InputMoney(int money)  //�Ա�
{
	balance += money;
}


int Account::outputMoney(int money)  //���
{
	if (balance < money)
	{
		cout << "�ܾ��� �����մϴ�" << endl;
		return 0;
	}

	balance -= money;
	return balance;

}


void Account::showAccount() // �������� Ȯ��
{
	cout << "���� ID : " << AccountID << endl;
	cout << "�� �� : " << Name << endl;
	cout << "�ܾ� : " << balance << endl;
	cout << endl;
}