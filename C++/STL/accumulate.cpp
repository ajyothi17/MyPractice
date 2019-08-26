#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> v = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int sum = 0;

	sum = accumulate(v.begin(), v.end(), sum);
	cout << "sum = " << sum << endl;

	sum = accumulate(v.begin(), v.end(), sum, minus<int>());
	cout << "sum = " << sum << endl;

	return 0;
}
