#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

void print(int a, int b, int c)
{
	cout << "a = " << a << " b = " << b << " c = " << c << endl;
}

int main(void)
{
	auto x = bind(print, 1, 2, 3);

	x();

	auto y = bind(print, _2, _3, _1);

	y(10, 20, 30);

	auto p = bind(print, _1, 10, 20);

	p(30);

	auto q = bind(print, _1, _2, 10);

	q(20, 30);

	auto r = bind(print, 20, _2, _1);

	r(10, 30);

	return 0;
}
