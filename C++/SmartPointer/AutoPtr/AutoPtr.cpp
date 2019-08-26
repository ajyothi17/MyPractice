#include <iostream>
#include <memory>

using namespace std;

class Person
{
	public:
		int a;
		void myFunc(void)	
		{
			cout << "in myfunc()" << endl;
		}
};
int main(void)
{
	auto_ptr<Person> obj1(new Person);

	obj1->myFunc();
	obj1->a = 10;

	cout << static_cast<void*>(&obj1) << endl;

	auto_ptr<Person> obj2(obj1);

	obj1->a = 100;
	obj1->myFunc();
	obj2->myFunc();

	cout << static_cast<void*>(&obj1) << endl;
	cout << static_cast<void*>(&obj2) << endl;

	return 0;
}
