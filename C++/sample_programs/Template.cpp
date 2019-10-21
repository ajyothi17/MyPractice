#include <iostream>

using namespace std;

#if 0
template <typename T>
T addNum(T num1, T num2)
{
	return num1 + num2;
}

int main(void)
{
	cout << addNum(10, 20) << endl;
	cout << addNum(11.2, 12.3) << endl;

	return 0;
}
#endif

#if 1
template <typename T>
class Test
{
	private:
		T num1;
		T num2;

	public:
		Test(T num1, T num2)
		{
			this->num1 = num1;
			this->num2 = num2;
		}

		T addNum(void)
		{
    		return this->num1 + this->num2;
		}
};

int main(void)
{
	Test<int> intObj(10, 20);
	Test<float> floatObj(11.2, 12.3);

	cout << intObj.addNum() << endl;
	cout << floatObj.addNum() << endl;

	return 0;
}
#endif
