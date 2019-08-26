#include <iostream>
#include <array>

using namespace std;

int main(void)
{
	array<int, 5> arr;

	cout << "before fill" << endl;
	for(auto x : arr)
		cout << x << endl;

	arr.fill(-1);

	cout << "after fill(-1)" << endl;
	for(auto x : arr)
		cout << x << endl;

	arr.fill(100);

	cout << "after fill(100)" << endl;
	for(auto x : arr)
		cout << x << endl;

	return 0;
}
