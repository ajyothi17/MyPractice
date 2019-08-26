#include <iostream>
#include <array>

using namespace std;

int main(void)
{
	array<int, 5> arr = {10, 20, 30, 40, 50};

	if(arr.empty())
		cout << "array is empty" << endl;

	else
		cout << "array is not empty" << endl;

	cout << "size : " << arr.size() << endl;
	cout << "first_element : " << arr.front() << endl;
	cout << "last_element : " << arr.back() << endl;
	cout << "0th element : " << arr.at(0) << endl;
	cout << "3rd element : " << arr.at(3) << endl;

	cout << "printing array elements:" << endl;
	for(auto itr = arr.begin(); itr < arr.end(); itr++)
		cout << *itr << " ";

	cout << endl;

	return 0;
}
