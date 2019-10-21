#include <iostream>

using namespace std;

class Test
{
	private:
		int x;

	public:
		Test()
		{
			cout << "Default constructor" << endl;
		}

		Test(int x)
		{
			this->x = x;
			cout << "parameterised const : " << x << endl;
		}

		Test(Test &obj)
		{
			this -> x = obj.x;
			cout << "copy const" << endl;
		}

		~Test()
		{
			cout << "Default destructor" << endl;
		}
};

int main(void)
{
	Test obj;

	Test *obj1 = new Test();
	Test obj2(10);
	Test *obj3 = new Test(20);

	Test obj4(*obj3);
	Test obj5(obj2);
	Test obj6(obj);

	delete obj1;
	delete obj3;

	return 0;
}
