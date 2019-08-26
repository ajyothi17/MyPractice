#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

void printVector(vector<int> v)
{
	for_each(v.begin(), v.end(), [](int i)
	{
		cout << i << endl;
	});
}

int main(void)
{
	vector<int> v {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	printVector(v);

	vector<int> :: iterator p = find_if(v.begin(), v.end(), [](int a)
	{
		return a > 4;
	});

	cout << "iterator p: " << *p << endl;

	sort(v.begin(), v.end(), [](const int &a, const int &b) -> bool
	{
		return a < b;
	});

	printVector(v);

	return 0;
}
