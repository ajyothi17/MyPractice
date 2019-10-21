#include <iostream>

using namespace std;

class Test
{
	static int count;
	int a = 0;

	public:

		void incrementCount(void)
		{
			this->count++;
		}

		void incrementA(void)
		{
			a++;
		}

		static void displayCount(void)
		{
			cout << "count : " << count << endl;
		}

		void displayA(void)
		{
			cout << "a : " << a << endl;
		}
};

int Test :: count = 0;

int main(void)
{
	Test obj1;
	Test obj2;
	Test obj3;

	Test :: displayCount();
	obj1.displayA();

	Test :: displayCount();
	obj2.displayA();

	Test :: displayCount();
	obj3.displayA();

	obj1.incrementCount();
	obj1.incrementA();
	Test :: displayCount();
	obj1.displayA();

	obj2.incrementCount();
	obj2.incrementA();
	Test :: displayCount();
	obj2.displayA();

	obj3.incrementCount();
	obj3.incrementA();
	Test :: displayCount();
	obj3.displayA();

	return 0;
}
