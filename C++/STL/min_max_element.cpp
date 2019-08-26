#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int arr[] = {10, 500, 20, -10, -100, 50};
	
	auto res = min_element((arr + 0), (arr + 6));
	cout << "min_ele = " << *res << endl;
	
	res = max_element((arr + 0), (arr + 6));
	cout << "max_ele = " << *res << endl;
	
	vector<int> vec = {10, 500, 20, -10, -100, 50};
	
	auto res2 = min_element(vec.begin(), vec.end());
	cout << "min_ele = " << *res2 << endl;
	
	res2 = max_element(vec.begin(), vec.end());
	cout << "max_ele = " << *res2 << endl;
	
	return 0;
}
