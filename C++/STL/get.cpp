#include <iostream>
#include <array>

using namespace std;

int main(void)
{
	array<int, 5> arr = {1, 2, 3, 4, 5};

	cout << "get<0>(arr) = " << get<0>(arr) << endl;
	cout << "get<1>(arr) = " << get<1>(arr) << endl;
	cout << "get<2>(arr) = " << get<2>(arr) << endl;
	cout << "get<3>(arr) = " << get<3>(arr) << endl;
	cout << "get<4>(arr) = " << get<4>(arr) << endl;

	return 0;
}
