#include <iostream>
#include <algorithm>

using namespace std;

int compare(int num1, int num2)
{
	if(num1 < num2)
		return 0;

	return 1;
}

int main(void)
{
	int arr[] = {1, 14, 2, 6, 12};

	make_heap(arr, arr+5);
	cout << "max_heap : " << arr[0] << endl;

	make_heap(arr, arr+5, compare);
	cout << "min_heap : " << arr[0] << endl;

	return 0;
}
