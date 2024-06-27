#include "account.h"


Account::Account(int ID, int money, char* cus_name) :AccountID(ID), balance(money) // 생성자
{
	Name = new char[strlen(cus_name) + 1]; // 메모리 동적 할당
	strcpy_s(Name, strlen(cus_name) + 1, cus_name); // 동적 할당된 메모리 초기화
}


Account::Account(const Account &Other) :AccountID(Other.AccountID), balance(Other.balance) // 복사 생성자 정의
{
	Name = new char[strlen(Other.Name) + 1];
	strcpy_s(Name, strlen(Other.Name) + 1, Other.Name);
}


Account::~Account() { delete[] Name; }; //파괴자


int Account::GetID() const { return AccountID; } // 계좌번호 확인


void Account::InputMoney(int money)  //입금
{
	balance += money;
}


int Account::outputMoney(int money)  //출금
{
	if (balance < money)
	{
		cout << "잔액이 부족합니다" << endl;
		return 0;
	}

	balance -= money;
	return balance;

}


void Account::showAccount() // 계좌정보 확인
{
	cout << "계좌 ID : " << AccountID << endl;
	cout << "이 름 : " << Name << endl;
	cout << "잔액 : " << balance << endl;
	cout << endl;
}