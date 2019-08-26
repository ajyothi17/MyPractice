#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isEven(int num)
{
	if(0 == (num%2))
		return 1;

	return 0;
}

int main(void)
{
	vector<int> v = {10, 20, 10, 20, 10, 30, 40, 50, 60, 70};

	cout << "before" << endl;
	for(auto x : v)
		cout << x << "\t";

	replace(v.begin(), v.end(), 10, 55);
	cout << "\nafter replace" << endl;
	for(auto x : v)
		cout << x << "\t";

	replace_if(v.begin(), v.end(), isEven, 2);
	cout << "\nafter replace_if" << endl;
	for(auto x : v)
		cout << x << "\t";

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	replace_copy(arr, arr + 5, v.begin(), 2, 20);
	cout << "\nafter replace_copy" << endl;
	for(auto x : v)
		cout << x << "\t";

	replace_copy_if(arr, arr + 5, v.begin(), isEven, -2);
	cout << "\nafter replace_copy_if" << endl;
	for(auto x : v)
		cout << x << "\t";

	cout << endl;

	return 0;
}
