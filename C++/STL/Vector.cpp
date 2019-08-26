#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> vObj;

	for(int itr = 0; itr < 5; itr++)
		vObj.push_back(rand()%100);

	cout << "size of vector : " << vObj.size() << endl;
	cout << "element at 0 : " << vObj.at(0) << endl;
	cout << "vObj.front() : " << vObj.front() << endl;
	cout << "vObj.back() : " << vObj.back() << endl;

	cout << "using []" << endl;
	for(auto itr = 0; itr < vObj.size(); itr++)
		cout << vObj[itr] << " ";
	cout << endl;

	cout << "using data()" << endl;
	int *ptr = vObj.data();
	for(auto itr = 0; itr < vObj.size(); itr++)
	{
		cout << *ptr << " ";
		ptr++;
	}
	cout << endl;

	vObj.pop_back();
	for(auto itr : vObj)
		cout << itr << " ";
	cout << endl;
	
	cout << "begin() and end()" << endl;
	for(auto itr = vObj.begin(); itr != vObj.end(); itr++)
		cout << *itr << " ";
	cout << endl;

	cout << "rbegin() and rend()" << endl;
	for(auto itr = vObj.rbegin(); itr != vObj.rend(); itr++)
		cout << *itr << " ";
	cout << endl;

	cout << "cbegin() and cend()" << endl;
	for(auto itr = vObj.cbegin(); itr != vObj.cend(); itr++)
		cout << *itr << " ";
	cout << endl;

	cout << "crbegin() and crend()" << endl;
	for(auto itr = vObj.crbegin(); itr != vObj.crend(); itr++)
		cout << *itr << " ";
	cout << endl;

	vObj.clear();

	if(vObj.empty())		
		cout << "vector empty" << endl;

	vector<int> v1;
	vector<int> v2;

	v1.assign(5, 100);
	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	int arr[] = {10, 20, 30, 40, 50};
	v1.assign(arr, arr+5);
	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	v2.assign(v1.begin(), v1.end());
	for(auto itr : v2)
		cout << itr << " ";
	cout << endl;

	v1.insert(v1.begin(), 100);
	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	v1.insert(v1.begin() + 1, 2, 200);
	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	v1.insert(v1.begin() + 1, v2.begin(), v2.end());
	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	v1.insert(v1.begin() + 2, arr, arr+2);
	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	v1.erase(v1.begin() + 2);
	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	v1.erase(v1.begin(), v1.begin() + 5);
	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	v1.swap(v2);

	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	for(auto itr : v2)
		cout << itr << " ";
	cout << endl;

	cout << "max_size() of vector : " << v1.max_size() << endl;
	cout << "max_size() of vector : " << v2.max_size() << endl;

	cout << "before resize()" << endl;
	cout << "size() of vector : " << v1.size() << endl;
	cout << "size() of vector : " << v2.size() << endl;

	v1.resize(10);
	v2.resize(5);

	cout << "after resize()" << endl;
	cout << "size() of vector : " << v1.size() << endl;
	cout << "size() of vector : " << v2.size() << endl;

	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	for(auto itr : v2)
		cout << itr << " ";
	cout << endl;

	cout << "capacity() of vector1 : " << v1.capacity() << endl;
	cout << "capacity() of vector2 : " << v2.capacity() << endl;

	v1.reserve(20);
	v2.reserve(25);

	cout << "capacity() of vector1 : " << v1.capacity() << endl;
	cout << "capacity() of vector2 : " << v2.capacity() << endl;

	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	for(auto itr : v2)
		cout << itr << " ";
	cout << endl;

	v1.shrink_to_fit();
	v2.shrink_to_fit();

	cout << "capacity() of vector1 : " << v1.capacity() << endl;
	cout << "capacity() of vector2 : " << v2.capacity() << endl;

	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	for(auto itr : v2)
		cout << itr << " ";
	cout << endl;

	for(int itr = 0; itr < v1.size(); itr++)
		v1[itr] = rand() % 100;

	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	v1.insert(v1.end(), v2.begin(), v2.end());

	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	sort(v1.begin(), v1.end());
	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	cout << "max_element : " << *(max_element(v1.begin(), v1.end())) << endl;
	cout << "min_element : " << *(min_element(v1.begin(), v1.end())) << endl;

	reverse(v1.begin(), v1.end());
	for(auto itr : v1)
		cout << itr << " ";
	cout << endl;

	int sum = 0;

	sum = accumulate(v1.begin(), v1.end(), sum);

	cout << "sum : " << sum << endl;

	vector<int> v3(v1.size() + v2.size());

	vector<int> :: iterator end, itr;

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	end = set_union(
		  			v1.begin(), v1.end(),
					v2.begin(), v2.end(),
					v3.begin());

	for(auto itr : v3)
		cout << itr << " ";
	cout << endl;

	vector<int> v4(v1.size() + v2.size());

	end = set_intersection(
		  			v1.begin(), v1.end(),
					v2.begin(), v2.end(),
					v4.begin());

	for(itr = v4.begin(); itr != end; itr++)
		cout << *itr << " ";
	cout << endl;

	itr = find(v4.begin(), v4.end(), 10);
	if(itr != v4.end())
		cout << *itr << " element found" << endl;
	else
		cout << "element not found" << endl;
	
	itr = find(v4.begin(), v4.end(), 100);
	if(itr != v4.end())
		cout << *itr << "found" << endl;
	else
		cout << "element not found" << endl;
	
	return 0;
}
