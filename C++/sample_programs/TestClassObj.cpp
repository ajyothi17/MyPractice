#include <iostream>

using namespace std;

class Test
{
	private:
		int num1;
		int num2;
		int res;

	public:

		void setNum(int num1, int num2)
		{
			this->num1 = num1;
			this->num2 = num2;
		}

		void addNums(void)
		{
			this->res = this->num1 + this->num2;
		}

		int getResult(void)
		{
			return this->res;
		}
		
		void display(void);
};

void Test :: display(void)
{
	cout << "Test class" << endl;
}

int main(void)
{
	Test obj;

	obj.display();

	obj.setNum(10, 20);
	obj.addNums();
	cout << "sum of 2 nums = " << obj.getResult() << endl;

	return 0;
}
