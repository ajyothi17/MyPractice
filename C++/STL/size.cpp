#include <iostream>
#include <array>

using namespace std;

int main(void)
{
	array<int, 0> arr1;
	array<int, 5> arr2;
	array<int, 5> arr3 = {10, 20, 30};
	array<int, 5> arr4 = {10, 20, 30, 40, 50};
	array<string, 3> arr5 = {"Ramu", "Somu", "Shyamu"};

	cout << "arr1 size = " << arr1.size() << endl;
	cout << "arr2 size = " << arr2.size() << endl;
	cout << "arr3 size = " << arr3.size() << endl;
	cout << "arr4 size = " << arr4.size() << endl;
	cout << "arr5 size = " << arr5.size() << endl;

	cout << "arr1 max_size = " << arr1.max_size() << endl;
	cout << "arr2 max_size = " << arr2.max_size() << endl;
	cout << "arr3 max_size = " << arr3.max_size() << endl;
	cout << "arr4 max_size = " << arr4.max_size() << endl;
	cout << "arr5 max_size = " << arr5.max_size() << endl;

	return 0;
}
