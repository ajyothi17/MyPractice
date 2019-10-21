#include <iostream>

using namespace std;

class Base
{
	public:
		virtual void display(void) = 0;
};

class Derived : public Base
{
	public:
		void display(void)
		{
			cout << "In derived" << endl;
		}
};

int main(void)
{
	Base *bPtr = new Derived();

	bPtr->display();

	return 0;
}
