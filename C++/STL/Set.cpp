#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	set<int> sObj;

	if(sObj.empty())
		cout << "set empty" << endl;

	else
		cout << "set not empty" << endl;

	sObj.insert(10);
	sObj.insert(20);
	sObj.insert(30);
	sObj.insert(40);
	sObj.insert(50);

	for(auto itr : sObj)
		cout << itr << " ";
	cout << endl;

	sObj.erase(20);	

	for(auto itr : sObj)
		cout << itr << " ";
	cout << endl;

	set<int> :: iterator sItr = sObj.find(40);

	if(sItr != sObj.end())
		cout << *sItr << " element found" << endl;

	else
		cout << "element not found" << endl;

	cout << "size of set : " << sObj.size() << endl;

	sObj.clear();
	if(sObj.empty())
		cout << "set empty" << endl;

	else
		cout << "set not empty" << endl;

	sObj.insert(10);
	sObj.insert(20);
	sObj.insert(30);
	sObj.insert(40);
	sObj.insert(50);

	cout << "lower_bound(0) element : " << *(sObj.lower_bound(0)) << endl;
	cout << "lower_bound(5) element : " << *(sObj.lower_bound(5)) << endl;
	cout << "lower_bound(11) element : " << *(sObj.lower_bound(11)) << endl;
	cout << "lower_bound(15) element : " << *(sObj.lower_bound(15)) << endl;
	cout << "lower_bound(21) element : " << *(sObj.lower_bound(21)) << endl;
	cout << "lower_bound(25) element : " << *(sObj.lower_bound(25)) << endl;
	cout << "lower_bound(31) element : " << *(sObj.lower_bound(31)) << endl;
	cout << "lower_bound(25) element : " << *(sObj.lower_bound(35)) << endl;

	cout << "upper_bound(0) element : " << *(sObj.upper_bound(0)) << endl;
	cout << "upper_bound(5) element : " << *(sObj.upper_bound(5)) << endl;
	cout << "upper_bound(11) element : " << *(sObj.upper_bound(11)) << endl;
	cout << "upper_bound(15) element : " << *(sObj.upper_bound(15)) << endl;
	cout << "upper_bound(21) element : " << *(sObj.upper_bound(21)) << endl;
	cout << "upper_bound(25) element : " << *(sObj.upper_bound(25)) << endl;
	cout << "upper_bound(31) element : " << *(sObj.upper_bound(31)) << endl;
	cout << "upper_bound(35) element : " << *(sObj.upper_bound(35)) << endl;

	sObj.emplace(60);
	for(auto itr : sObj)
		cout << itr << " ";
	cout << endl;

	sObj.emplace(10);
	for(auto itr : sObj)
		cout << itr << " ";
	cout << endl;

	return 0;
}
