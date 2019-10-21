#include <iostream>

using namespace std;

int num = 10;
string str = "global str";

int main(void)
{
	int num = 20;
	string str = "local str";

	cout << "num -> " << num << endl;
	cout << "::num -> " << ::num << endl;

	cout << "str -> " << str << endl;
	cout << "::str -> " << ::str << endl;

	return 0;
}
