#include <iostream>

using namespace std;

class Test
{
	public:
		int x;
		mutable int y;

		Test()
		{
			x = 10;
			y = 20;
		}
};

int main(void)
{
	const Test obj;

//	obj.x = 100;
	obj.y = 200;

	cout << obj.x << " " << obj.y << endl;
	
	return 0;
}
