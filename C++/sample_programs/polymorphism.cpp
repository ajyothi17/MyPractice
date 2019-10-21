#include <iostream>

using namespace std;

#if 1
class Test
{
	int a = 10;
	public:
		void display()
		{
			cout << "In Test" << endl;
		}

		void display(int x)
		{
			cout << x << endl;
		}

		int operator++()
		{
			this->a += 1;
			return this->a;
		}

		int operator-(Test obj)
		{	
			cout << "in operator-" << endl;
			return this->a - obj.a;
		}

		bool operator<(Test obj)
		{
			if(this->a < obj.a)
				return true;

			return false;
		}

		friend int operator+(Test obj1, Test obj2);
		friend int operator--(Test obj);
};

int operator+(Test obj1, Test obj2)
{
	cout << "in friend operator+" << endl;

	return obj1.a + obj2.a;
}

int operator--(Test obj)
{
	cout << "in friend --" << endl;

	obj.a -= 1;

	return obj.a;
}

int main(void)
{
	Test obj;

	obj.display();
	obj.display(10);

	cout << "operator++ " << ++obj << endl;
	cout << "operator-- " << --obj << endl;

	Test obj2;

	cout << "operator+ " << obj + obj2 << endl;
	cout << "operator- " << obj - obj2 << endl;

	if(obj < obj2)
		cout << "obj1 < obj2" << endl;

	else
		cout << "obj2 < obj1" << endl;

	return 0;
}
#endif
