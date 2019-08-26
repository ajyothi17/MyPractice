#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> v = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	cout << "before rotate" << endl;
	for(auto iter : v)
		cout << iter << "\t";
	cout << endl;

	rotate(v.begin(), v.begin() + 3, v.end());
	cout << "after rotate" << endl;
	for(auto iter : v)
		cout << iter << "\t";
	cout << endl;

	int arr[] = {1, 2, 3, 4, 5};
	rotate_copy(arr, arr+2, arr+5, v.begin());
	cout << "after rotate_copy" << endl;
	for(auto iter : v)
		cout << iter << "\t";
	cout << endl;

	return 0;
}
