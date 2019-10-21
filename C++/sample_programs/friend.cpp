#include <iostream>

using namespace std;

class Test
{
	private:
		int x = 10;

	public:
		friend void display(Test obj)
		{
			cout << obj.x << endl;
		}
};

int main(void)
{
	Test obj;

	display(obj);

	return 0;
}
