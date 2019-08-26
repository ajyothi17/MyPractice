#include <iostream>
#include <unordered_map>

using namespace std;

void findRepeat(int arr[], int arr_size)
{
	unordered_map<int, int> hash;

	for(int itr = 0; itr < arr_size; itr++)
		hash[arr[itr]]++;

	for(auto itr = hash.begin(); itr != hash.end(); itr++)
	{
		if((itr->second) > 1)
			cout << "element " << itr->first << " repeats " << itr->second << " times" << endl;
	}
}

void findNonRepeat(int arr[], int arr_size)
{
	unordered_map<int, int> hash;

	for(int itr = 0; itr < arr_size; itr++)
		hash[arr[itr]]++;

	for(auto itr = hash.begin(); itr != hash.end(); itr++)
	{
		if((itr->second) == 1)
			cout << "element " << itr->first << " repeats " << itr->second << " time" << endl;
	}
}

int main(void)
{
	int arr[] = {1, 2, 1, 1, 3, 3, 4, 4, 2, 2, 5};

	cout << "Repeating elements" << endl;
	findRepeat(arr, 11);
	cout << "Non - Repeating elements" << endl;
	findNonRepeat(arr, 11);

	return 0;
}
