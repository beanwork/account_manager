#include <iostream>

class Parent

{

public:

	virtual void PrintMe() { printf("I am Parent\n"); }

};



class Child : public Parent

{

private:

	int num;



public:

	Child(int anum = 1234) : num(anum) { }

	virtual void PrintMe() { printf("I am Child\n"); }

	void PrintNum() { printf("Hello Child=%d\n", num); }

};



void main()

{

	Parent P, *pP, *pP2;

	Child C, *pC, *pC2;

	pP = &P;

	pC = &C;



	pP2 = dynamic_cast<Parent *>(pC);       // 업 캐스팅-항상 안전하다.

	pC2 = dynamic_cast<Child *>(pP2);        // 다운 캐스팅-경우에 따라 다르다.

	printf("pC2 = %p\n", pC2);

	pC2 = dynamic_cast<Child *>(pP);         // 캐스팅 불가능

	printf("pC2 = %p\n", pC2);

}