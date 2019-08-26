#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	cout << "max(10, 50) : " << max(10, 50) << endl;
	cout << "max(21.24, 12.80) : " << max(21.24, 12.80) << endl;
	cout << "max(20.2f, 15.8f) : " << max(20.2f, 15.8f) << endl;
	cout << "max('A', 'a') : "  << max('A', 'a') << endl;
	cout << "max('z', 'a') : "  << max('z', 'a') << endl;
	cout << "max('A', 'Z') : "  << max('A', 'Z') << endl;
	cout << "max(\"Ramu\", \"Somu\") : " << max("Ramu", "Somu") << endl;
	cout << "max(\"Shyamu\", \"Somuuu\") : " << max("Shyamu", "Somuuu") << endl;

	return 0;
}
