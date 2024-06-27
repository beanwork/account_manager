#pragma once
#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "account.h"

class NormalAccount : public Account
{
private:
	int Interest;

public:
	NormalAccount(int ID, int money, char* cus_name, int rate) : Account(ID, money, cus_name), Interest(rate)
	{ }

	virtual void InputMoney(int money)
	{
		Account::InputMoney(static_cast<int>(money*(1 + 0.01*Interest)));
	}

	int Getinterest() { return Interest; }
};


#endif // !__NORMAL_ACCOUNT_H__
