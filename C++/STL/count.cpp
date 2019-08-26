#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int arr[] = {1,1,1,2,3,2,1,2,3,4,1,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	vector<int> vect = {1,1,1,2,3,2,1,2,3,4};

	string str = "abradakabra";

	cout << "number of times 1 occur in array : " << count(arr, arr + size, 1) << endl;
	cout << "number of times 1 occur in vector : " << count(vect.begin(), vect.end(), 1) << endl;
	cout << "number of times a occur in string : " << count(str.begin(), str.end(), 'a') << endl;

	return 0;
}
