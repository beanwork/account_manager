#include "HighCreditAccount.h"
#include "AccountHandler.h"


const int Name_LEN = 20; // 이름 길이 상한


int AccountHandler::selectAccount(int choice)
{
	int interest; //이자율

	switch (choice)
	{
	case 1:
		cout << "[보통예금계좌 개설]" << endl;
		interest = 3;
		break;
	case 2:
		cout << "[신용신뢰계좌 개설]" << endl;
		interest = 9;
		break;
	default:
		cout << "유효하지 않은 접근입니다" << endl;
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

	cout << "계좌 ID : ";
	cin >> id;

	cout << endl;
	cout << "이 름 : ";
	cin >> cus_name;

	cout << endl;
	cout << "입금액 : ";
	cin >> money;

	interest = AccountHandler::selectAccount(choice);
	cout << endl;
	cout << "이자율 : " << interest << endl;
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
	int credit; //신용등급

	interest = AccountHandler::selectAccount(choice);

	cout << "계좌 ID : ";
	cin >> id;

	cout << "이 름 : ";
	cin >> cus_name;

	cout << "입금액 : ";
	cin >> money;

	cout << "이자율 : " << interest << endl;


	cout << "신용등급(1toA, 2toB, 3toC): ";
	cin >> credit;
	cout << endl;

	Accarr[Accnum] = new HighCreditAccount(id, money, cus_name, interest, credit);

	Accnum++;
}


void AccountHandler::makeAccount()
{
	int money, id, choice, interest;
	char cus_name[Name_LEN]; // 이름

	cout << "[계좌개설]" << endl;
	cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
	cout << "선택 : ";
	cin >> choice;
	cout << endl;

	if (choice == 2) { AccountHandler::makeHighCreditAccount(choice); }
	else { AccountHandler::makeNormalAccount(choice); }
}


void AccountHandler::inputMoney()
{
	int id;
	int money;

	cout << "[입    금]" << endl;
	cout << "계좌 ID : ";
	cin >> id;

	for (int i = 0; i < Accnum; i++) // 계좌가 등록되어있는지 확인
	{
		if (Accarr[i]->GetID() == id)
		{
			cout << "입금액 : ";
			cin >> money;

			Accarr[i]->InputMoney(money);
			cout << "입금 완료" << endl;

			return;
		}
	}

	cout << "보유하신 계좌가 없습니다" << endl;
}


void AccountHandler::outputMoney()
{
	int id;
	int money;

	cout << "[출    금]" << endl;
	cout << "계좌 ID : ";
	cin >> id;

	for (int i = 0; i < Accnum; i++) // 계좌가 등록되어있는지 확인
	{
		if (Accarr[i]->GetID() == id)
		{
			cout << "출금액 : ";
			cin >> money;

			Accarr[i]->outputMoney(money);

			return;
		}
	}

	cout << "보유하신 계좌가 없습니다" << endl;
	cout << "------------------------" << endl;
}

void AccountHandler::showAccount()
{
	for (int i = 0; i < Accnum; i++)
	{
		Accarr[i]->showAccount();
	}
}