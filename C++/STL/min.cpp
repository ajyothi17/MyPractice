#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	cout << "min(10, 50) : " << min(10, 50) << endl;
	cout << "min(21.24, 12.80) : " << min(21.24, 12.80) << endl;
	cout << "min(20.2f, 15.8f) : " << min(20.2f, 15.8f) << endl;
	cout << "min('A', 'a') : "  << min('A', 'a') << endl;
	cout << "min('z', 'a') : "  << min('z', 'a') << endl;
	cout << "min('A', 'Z') : "  << min('A', 'Z') << endl;
	cout << "min(\"Ramu\", \"Somu\") : " << min("Ramu", "Somu") << endl;
	cout << "min(\"Shyamu\", \"Somuuu\") : " << min("Shyamu", "Somuuu") << endl;

	return 0;
}
