#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int arr[10];
	int key;

	for(int itr = 0; itr < 10; itr++)
		arr[itr] = rand() % 100;

	cout << "before sorting" << endl;
	for(auto itr : arr)
		cout << itr << endl;

	sort(arr, arr + 10);
	cout << "after sorting" << endl;
	for(auto itr : arr)
		cout << itr << endl;

	cout << "enter key element to be searched" << endl;
	cin >> key;

	if(binary_search(arr, arr+10, key))
		cout << key << " element found" << endl;

	else
		cout << key << " not found" << endl;

	return 0;
}
