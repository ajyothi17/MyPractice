#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main(void)
{
	array<int, 5> arr = {100, -20, 3, 40, -50};

	sort(arr.begin(), arr.end());

	cout << "ascending" << endl;
	for(auto x : arr)
		cout << x << endl;

	sort(arr.begin(), arr.end(), greater<int>());

	cout << "descending" << endl;
	for(auto x : arr)
		cout << x << endl;

	return 0;
}
