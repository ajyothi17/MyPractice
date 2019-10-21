#include <iostream>

using namespace std;

inline int add(int num1, int num2)
{
	return num1 + num2;
}

class Test
{
	private:
		int res;

	public:
		void sum(int num1, int num2);
		int getResult(void)
		{
			return this->res;
		}
};

inline void Test :: sum(int num1, int num2)
{
	cout << num1 << " " << num2 << endl;
	this->res = num1 + num2;
}

int main(void)
{
	cout << add(10, 20) << endl;

	Test obj;

	obj.sum(100, 200);
	cout << obj.getResult() << endl;

	return 0;
}
