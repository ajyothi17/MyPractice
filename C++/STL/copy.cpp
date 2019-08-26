#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int arr[] = {10, 500, 20, -10, -100, 50};
	
	vector<int> vec1(5);
	
	copy(arr, arr + 5, vec1.begin());

	cout << "copy" << endl;
	for(auto x : vec1)
		cout << x << endl;

	vector<int> vec2(5);
	
	copy_n(arr, 5, vec2.begin());

	cout << "copy_n" << endl;
	for(auto x : vec2)
		cout << x << endl;

	vector<int> vec3(5);
	
	copy_if(arr, arr + 5, vec3.begin(), [](int i){ return (i >= 0); });

	cout << "copy_if" << endl;
	for(auto x : vec3)
		cout << x << endl;

	return 0;
}
