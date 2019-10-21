#include <iostream>

using namespace std;

class Base
{
	public:
		virtual void display()
		{
			cout << "base" << endl;
		}
};

class Derived : public Base
{
	public:
		void display()
		{
			cout << "derived" << endl;
		}
};

int main(void)
{
	Derived dObj;
	Base *bObj1 = &dObj;
	Base *bObj2 = new Derived();

	bObj1->display();
	bObj2->display();

	return 0;
}
