#include <iostream>
#include <array>

using namespace std;

int main(void)
{
	array<int, 5> arr = {1, 2, 3, 4, 5};

	cout << "array elements" << endl;
	for(auto itr = arr.begin(); itr < arr.end(); itr++)
		cout << *itr << endl;

	cout << "array elements, rbegin, rend" << endl;
	for(auto itr = arr.rbegin(); itr < arr.rend(); itr++)
		cout << *itr << endl;

	return 0;
}
