#pragma once

#ifndef __ACCOUNT_H__
#define __ACCOUTN_H__

#include <iostream>

using namespace std;

class Account
{
protected:
	int AccountID; // °èÁÂ¹øÈ£
	int balance; // ÀÜ¾×
	char* Name; // ÀÌ¸§

public:
	Account(int ID, int money, char* cus_name);
	Account(const Account &Other);
	
	int GetID() const;
	virtual void InputMoney(int money);
	int outputMoney(int money);
	void showAccount();
	~Account();
};

#endif // !__ACCOUNT_H__
