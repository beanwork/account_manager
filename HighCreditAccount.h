#pragma once

#ifndef __HIGH_CREDIT_ACCOUNT__
#define __HIGH_CREDIT_ACCOUNT__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int Credit;
	int add;

public:
	HighCreditAccount(int ID, int money, char* cus_name, int rate, int credit) : NormalAccount(ID, money, cus_name, rate), Credit(credit), add(0)
	{
		switch (credit)
		{
		case 1:
			add = 2;
			break;
		case 2:
			add = 4;
			break;
		case 3:
			add = 7;
			break;
		default:
			cout << "유효하지 않은 접근입니다" << endl;
			cout << endl;
			break;
		}
		add += rate;
	}


	virtual void InputMoney(int money) // 입금
	{
		Account::InputMoney(static_cast<int>(money*(1 + 0.01*(add))));
	}

};


#endif // !__HIGH_CREDIT_ACCOUNT__

