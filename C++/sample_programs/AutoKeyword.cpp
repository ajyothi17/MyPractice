#include <iostream>

using namespace std;

template <typename T>
auto func(T x) -> decltype(x)
{
	return x;
}

int main(void)
{
	cout << func('a') << endl;
	cout << func("Jyothi") << endl;
	cout << func(10) << endl;
	cout << func(20.5) << endl;

	return 0;
}
