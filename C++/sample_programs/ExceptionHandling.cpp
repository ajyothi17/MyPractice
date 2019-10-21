#include <iostream>

using namespace std;

int divide(int num1, int num2)
{
	try
	{
		if(num2 == 0)
			throw num2;
		
		return num1/num2;	
	}

	catch(int x)
	{
		cout << "caught exp in divide()" << endl;
		throw;
	}
}

int main(void)
{
	int num1 = 10;
	int num2 = 0;
	int ch;

	try
	{
//		if(num2 == 0)
//			throw num2;

		cout << divide(num1,num2) << endl;

		cout << "enter a num" << endl;
		cin >> ch;

		if(1 == ch)
			throw 'x';

		else if(2 == ch)
			throw ch;

		else
			throw 1.0;

	}
/*
	catch(char c)
	{
		cout << "char catch" << endl;
	}

	catch(int x)
	{
		cout << "cannot divide by zero " << x << endl;
	}

	catch(double c)
	{
		cout << "double catch" << endl;
	}
*/

	catch(...)
	{
		cout << "caught exception" << endl;
	}

	return 0;
}
