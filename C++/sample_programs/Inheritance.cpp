#include <iostream>

using namespace std;

#if 0 
class Base
{
	public:
		void displayBase(void)
		{
			cout << "in base" << endl;
		}
};

class Derived : public Base
{
	public:
		void displayDerived(void)
		{
			cout << "in derived" << endl;
		}
};

int main(void)
{
	Derived obj;
	
	obj.displayBase();
	obj.displayDerived();

	return 0;
}
#endif

#if 0
class Base1
{
	private:
		int num1;

	public:
		void setNum1(int num1)
		{
			this->num1 = num1;
		}

		int getNum1(void)
		{
			return this->num1;
		}
};

class Base2
{
	private:
		int num2;

	public:
		void setNum2(int num2)
		{
			this->num2 = num2;
		}

		int getNum2(void)
		{
			return this->num2;
		}
};

class Derived : public Base1, public Base2
{
	int res;

	public:
		void computeRes(void)
		{
			this->res = this->getNum1() + this->getNum2();
		}

		int getRes(void)
		{
			return this->res;
		}
};

int main(void)
{
	Derived obj;

	obj.setNum1(10);
	obj.setNum2(20);

	obj.computeRes();

	cout << obj.getRes() << endl;

	return 0;
}
#endif

#if 0
class TestA
{
	public:
		void displayA(void)
		{
			cout << "in TestA" << endl;
		}
};

class TestB : public TestA
{
	public:
		void displayB(void)
		{
			cout << "in TestB" << endl;
		}
};

class TestC : public TestB
{
	public:
		void displayC(void)
		{
			cout << "in TestC" << endl;
		}
};

int main(void)
{
	TestC obj;

	obj.displayA();
	obj.displayB();
	obj.displayC();
	
	return 0;
}
#endif

#if 0 
class Base
{
	private:
		int num1 = 10;
		int num2 = 20;

	public:
		int getNum1(void)
		{
			return num1;
		}
		int getNum2(void)
		{
			return num2;
		}
};

class Derived1 : public Base
{
	public:
		void displayDerived1()
		{
			cout << "Derived1 " << this->getNum1() + this->getNum2() << endl;
		}
};

class Derived2 : public Base
{
	public:
		void displayDerived2()
		{
			cout << "Derived2 " << this->getNum1() * this->getNum2() << endl;
		}
};

int main(void)
{
	Derived1 obj1;
	Derived2 obj2;
	
	obj1.displayDerived1();
	obj2.displayDerived2();
	
	return 0;
}
#endif

#if 0
class TestA
{
	public:
		void displayA(void)
		{
			cout << "in TestA" << endl;
		}
};

class TestB : public TestA
{
	public:
		void displayB(void)
		{
			cout << "in TestB" << endl;
		}
};

class TestC
{
	public:
		void displayC(void)
		{
			cout << "in TestC" << endl;
		}
};

class TestD : public TestC, public TestB
{
	public:
		void displayD(void)
		{
			cout << "in TestD" << endl;
		}
};

int main(void)
{
	TestD obj;

	obj.displayA();
	obj.displayB();
	obj.displayC();
	obj.displayD();

	return 0;
}
#endif

#if 1
class Base
{
	private:
		int num1 = 10;
		int num2 = 20;

	public:
		int getNum1(void)
		{
			return num1;
		}
		int getNum2(void)
		{
			return num2;
		}
};

class Derived1 : public virtual Base
{
	public:
		void displayDerived1()
		{
			cout << "Derived1 " << this->getNum1() + this->getNum2() << endl;
		}
};

class Derived2 : public virtual Base
{
	public:
		void displayDerived2()
		{
			cout << "Derived2 " << this->getNum1() * this->getNum2() << endl;
		}
};

class Derived3 : public Derived1, public Derived2
{
	public:
		void displayDerived3()
		{
			cout << "Derived3 " << this->getNum1() - this->getNum2() << endl;
		}
};

int main(void)
{
	Derived3 obj;

	obj.displayDerived1();
	obj.displayDerived2();
	obj.displayDerived3();

	return 0;
}
#endif
