#include "HighCreditAccount.h"
#include "AccountHandler.h"


const int Name_LEN = 20; // �̸� ���� ����


int AccountHandler::selectAccount(int choice)
{
	int interest; //������

	switch (choice)
	{
	case 1:
		cout << "[���뿹�ݰ��� ����]" << endl;
		interest = 3;
		break;
	case 2:
		cout << "[�ſ�ŷڰ��� ����]" << endl;
		interest = 9;
		break;
	default:
		cout << "��ȿ���� ���� �����Դϴ�" << endl;
		cout << endl;
		break;
	}

	return interest;
}


void AccountHandler::makeNormalAccount(int choice)
{
	int id;
	int money;
	char cus_name[Name_LEN];
	int interest;

	cout << "���� ID : ";
	cin >> id;

	cout << endl;
	cout << "�� �� : ";
	cin >> cus_name;

	cout << endl;
	cout << "�Աݾ� : ";
	cin >> money;

	interest = AccountHandler::selectAccount(choice);
	cout << endl;
	cout << "������ : " << interest << endl;
	cout << endl;

	Accarr[Accnum] = new NormalAccount(id, money, cus_name, interest);

	Accnum++;
}


void AccountHandler::makeHighCreditAccount(int choice)
{
	int id;
	int money;
	char cus_name[Name_LEN];
	int interest;
	int credit; //�ſ���

	interest = AccountHandler::selectAccount(choice);

	cout << "���� ID : ";
	cin >> id;

	cout << "�� �� : ";
	cin >> cus_name;

	cout << "�Աݾ� : ";
	cin >> money;

	cout << "������ : " << interest << endl;


	cout << "�ſ���(1toA, 2toB, 3toC): ";
	cin >> credit;
	cout << endl;

	Accarr[Accnum] = new HighCreditAccount(id, money, cus_name, interest, credit);

	Accnum++;
}


void AccountHandler::makeAccount()
{
	int money, id, choice, interest;
	char cus_name[Name_LEN]; // �̸�

	cout << "[���°���]" << endl;
	cout << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl;
	cout << "���� : ";
	cin >> choice;
	cout << endl;

	if (choice == 2) { AccountHandler::makeHighCreditAccount(choice); }
	else { AccountHandler::makeNormalAccount(choice); }
}


void AccountHandler::inputMoney()
{
	int id;
	int money;

	cout << "[��    ��]" << endl;
	cout << "���� ID : ";
	cin >> id;

	for (int i = 0; i < Accnum; i++) // ���°� ��ϵǾ��ִ��� Ȯ��
	{
		if (Accarr[i]->GetID() == id)
		{
			cout << "�Աݾ� : ";
			cin >> money;

			Accarr[i]->InputMoney(money);
			cout << "�Ա� �Ϸ�" << endl;

			return;
		}
	}

	cout << "�����Ͻ� ���°� �����ϴ�" << endl;
}


void AccountHandler::outputMoney()
{
	int id;
	int money;

	cout << "[��    ��]" << endl;
	cout << "���� ID : ";
	cin >> id;

	for (int i = 0; i < Accnum; i++) // ���°� ��ϵǾ��ִ��� Ȯ��
	{
		if (Accarr[i]->GetID() == id)
		{
			cout << "��ݾ� : ";
			cin >> money;

			Accarr[i]->outputMoney(money);

			return;
		}
	}

	cout << "�����Ͻ� ���°� �����ϴ�" << endl;
	cout << "------------------------" << endl;
}

void AccountHandler::showAccount()
{
	for (int i = 0; i < Accnum; i++)
	{
		Accarr[i]->showAccount();
	}
}