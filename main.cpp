/*
구현할 기능
1. 계좌 개설
2. 입 금
3. 출 금
4. 전체고객 잔액조회

// 통장의 계좌번호는 중복되지 아니한다.
// 입금 및 출금액은 무조건 0보다 크다
// 고객의 계좌정보는 계좌번호, 고객이름, 고객의 잔액 이렇게 3가지만 저장 및 관리한다.
// 둘 이상의 고객 정보 저장을 위해서 배열을 사용한다.
// 계좌번호는 정수의 형태이다.
*/

#include <iostream>
#include "AccountHandler.h"

using namespace std;

void main()
{
	int choice(0);
	AccountHandler Ah; // 컨트롤 클래스

	while (choice != 5)
	{
		cout << "----Menu----" << endl;
		cout << "1. 계좌 개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌 정보 전체 출력" << endl;
		cout << "5.프로그램 종료" << endl;
		//
		cout << "선택 : ";
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
			cout << "프로그램이 종료되었습니다" << endl;
			break;
		}
	}

}












