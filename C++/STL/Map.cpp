#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	map<int, string> mapObj;

	if(mapObj.empty())
		cout << "Map empty" << endl;
	
	else
		cout << "Map not empty" << endl;

	mapObj.insert(pair<int, string> (10, "Ramu"));
	mapObj.insert(pair<int, string> (20, "Somu"));
	mapObj.insert(pair<int, string> (30, "Shyamu"));
	mapObj.insert(pair<int, string> (40, "Tom"));
	mapObj.insert(pair<int, string> (50, "Jerry"));

	cout << "size of map : " << mapObj.size() << endl;
	cout << "max_size of map : " << mapObj.max_size() << endl;

	map<int, string> :: iterator itr = mapObj.begin();
	cout << itr->first << " " << itr->second << endl;
 
	itr = --mapObj.end();
	cout << itr->first << " " << itr->second << endl;

	cout << "after insert" << endl;
	for(auto itr : mapObj)
		cout << "<key = " << itr.first << " value = " << itr.second << ">" << endl;

	mapObj.erase(10);
	cout << "after erase" << endl;
	for(auto itr : mapObj)
		cout << "<key = " << itr.first << " value = " << itr.second << ">" << endl;

	mapObj.clear();
	cout << "after clear" << endl;
	for(auto itr : mapObj)
		cout << "<key = " << itr.first << " value = " << itr.second << ">" << endl;

	return 0;
}
