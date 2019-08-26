#include <iostream>
#include <array>

using namespace std;

int main(void)
{
	array<int, 5> arr = {10, 20, 30, 40, 50};

	cout << "array elements" << endl;
	for(auto i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;

	arr[1] = 200;
	arr[4] = 500;

	cout << "array elements" << endl;
	for(auto i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;

	return 0;
}
