#include <iostream>
#include <list>

using namespace std;

int main(void)
{
	list <int> iList;

	if(iList.empty())
		cout << "list empty" << endl;

	else
		cout << "list not empty" << endl;

	iList.push_front(10);
	iList.push_front(20);
	iList.push_front(30);
	iList.push_front(40);

	for(auto itr : iList)
		cout << itr << " ";
	cout << endl;

	iList.push_back(100);
	iList.push_back(200);
	iList.push_back(300);
	iList.push_back(400);

	for(auto itr : iList)
		cout << itr << " ";
	cout << endl;

	cout << "size of list : " << iList.size() << endl;

	iList.sort();

	for(auto itr : iList)
		cout << itr << " ";
	cout << endl;

	iList.reverse();

	for(auto itr : iList)
		cout << itr << " ";
	cout << endl;

	iList.remove_if([](int num) { return (num >= 100);});

	for(auto itr : iList)
		cout << itr << " ";
	cout << endl;

	cout << "front() : " << iList.front() << endl;
	cout << "back() : " << iList.back() << endl;

	iList.pop_front();
	cout << "after pop_front()" << endl;
	for(auto itr : iList)
		cout << itr << " ";
	cout << endl;

	iList.pop_back();
	cout << "after pop_back()" << endl;
	for(auto itr : iList)
		cout << itr << " ";
	cout << endl;

	iList.insert(iList.begin(), 10);
	iList.insert(iList.begin(), 2, 40);
	for(auto itr : iList)
		cout << itr << " ";
	cout << endl;

	cout << "begin and end : " << endl;
	for(auto itr = iList.begin(); itr != iList.end(); itr++)
		cout << *itr << " ";
	cout << endl;

	cout << "rbegin and rend : " << endl;
	for(auto itr = iList.rbegin(); itr != iList.rend(); itr++)
		cout << *itr << " ";
	cout << endl;

	iList.assign(3, 50);
	for(auto itr : iList)
		cout << itr << " ";
	cout << endl;

	list <int> iList2 = {1, 2, 3, 4, 5};

	iList.merge(iList2);
	cout << "list1 after merge : " << endl;
	for(auto itr : iList)
		cout << itr << " ";
	cout << endl;
	cout << "list2 after merge : " << endl;
	for(auto itr : iList2)
		cout << itr << " ";
	cout << endl;

	iList.unique();
	for(auto itr : iList)
		cout << itr << " ";
	cout << endl;

	iList.erase(iList.begin());
	for(auto itr : iList)
		cout << itr << " ";
	cout << endl;

	iList.erase(--iList.end());
	for(auto itr : iList)
		cout << itr << " ";
	cout << endl;

	list<string> sList;
	string str;

	while(true)
	{
		cout << "enter string (exit/EXIT to quit) : " << endl;
		cin >> str;

		if((str == "exit") || (str == "EXIT"))
			break;

		sList.push_back(str);
	}

	for(auto itr : sList)
		cout << itr << " ";
	cout << endl;

	list<char> clist;

	for(char c = 'A'; c <= 'Z'; c++)
		clist.push_back(c);

	list <char> :: const_iterator citr;
	for(citr = clist.begin(); citr != clist.end(); citr++)
		cout << *citr << " ";
	cout << endl;

	return 0;
}
