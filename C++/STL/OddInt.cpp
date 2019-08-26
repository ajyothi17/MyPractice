#include <iostream>
#include <array>

using namespace std;

int oddInt(array<int, 5> arr)
{
	for(unsigned int itr = 0; itr < arr.size(); itr++)
	{
		if(0 != (arr[itr] % 2))
			return arr[itr];
	}

	return -1;
}

int main(void)
{
	array<int, 5> arr;
	int res = -1;

	cout << "enter 5 array elements:" << endl;
	for(auto itr = 0; itr < 5; itr++)
		cin >> arr[itr];

	if(-1 == (res = oddInt(arr)))
		cout << "no odd int in given array" << endl;

	else
		cout << "Odd num in given array:" << res << endl;

	return 0;
}
