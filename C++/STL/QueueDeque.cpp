#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main(void)
{
	queue<int> qObj;

	if(qObj.empty())
		cout << "queue empty" << endl;

	else
		cout << "queue not empty" << endl;

	qObj.push(10);
	qObj.push(20);
	qObj.push(30);
	qObj.push(40);
	qObj.push(50);

	cout << "size of queue : " << qObj.size() << endl;
	cout << "front element : " << qObj.front() << endl;
	cout << "back element : " << qObj.back() << endl;

	while(!(qObj.empty()))
	{
		cout << qObj.front() << " ";
		qObj.pop();
	}
	cout << endl;

	cout << "size of queue : " << qObj.size() << endl;
	cout << "front element : " << qObj.front() << endl;
	cout << "back element : " << qObj.back() << endl;

	deque<int> dqObj;

	for(int i = 100; i < 500; i += 100)
	{
		dqObj.push_back(i);
	}

	for(auto itr : dqObj)
		cout << itr << " ";
	cout << endl;

	return 0;
}
