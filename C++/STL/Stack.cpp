#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	stack<int> intStack;
	stack<string> strStack;

	intStack.push(10);
	intStack.push(20);
	intStack.push(30);
	intStack.push(40);
	intStack.push(50);

	strStack.push("Ramu");
	strStack.push("Somu");
	strStack.push("Shyamu");

	cout << "int stack size : " << intStack.size() << endl;
	cout << "string stack size : " << strStack.size() << endl;

	cout << "int stack" << endl;
	while(!(intStack.empty()))
	{
		cout << intStack.top() << " ";
		intStack.pop();
	}
	cout << endl;

	cout << "string stack" << endl;
	while(!(strStack.empty()))
	{
		cout << strStack.top() << " ";
		strStack.pop();
	}
	cout << endl;

	if(intStack.empty())
		cout << "int stack empty" << endl;

	if(strStack.empty())
		cout << "str stack empty" << endl;

	return 0;
}
