#pragma once

#ifndef __ACCOUNT_HANDLER__
#define __ACCOUNT_HANDLER__

#include "account.h"

class AccountHandler
{
private:
	int Accnum;
	Account *Accarr[100]; // 계좌 저장을 위한 배열

public:
	AccountHandler() { Accnum = 0; }

	void makeAccount();
	void makeNormalAccount(int choice);
	void makeHighCreditAccount(int choice);
	void inputMoney();
	void outputMoney();
	void showAccount();
	int selectAccount(int choice);

	~AccountHandler()
	{
		for (int i = 0; i < Accnum; i++)
		{
			delete Accarr[Accnum];
		}
	}
};

#endif // !__ACCOUNT_HANDLER__
