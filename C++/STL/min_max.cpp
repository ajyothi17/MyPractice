#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	auto val1_int = 10;
	auto val2_int = 20;

	auto res1 = minmax(val1_int, val2_int);
	cout << "result, min = " << res1.first << ", max = " << res1.second << endl;

	auto val1_float = 12.5f;
	auto val2_float = 20.12f;

	auto res2 = minmax(val1_float, val2_float);
	cout << "result, min = " << res2.first << ", max = " << res2.second << endl;

	auto val1_char = 'A';
	auto val2_char = 'a';

	auto res3 = minmax(val1_char, val2_char);
	cout << "result, min = " << res3.first << ", max = " << res3.second << endl;

	val1_char = 'A';
	val2_char = 'Z';

	auto res4 = minmax(val1_char, val2_char);
	cout << "result, min = " << res4.first << ", max = " << res4.second << endl;

	val1_char = 'z';
	val2_char = 'a';

	auto res5 = minmax(val1_char, val2_char);
	cout << "result, min = " << res5.first << ", max = " << res5.second << endl;

	auto str1 = "Ramu";
	auto str2 = "Somu";

	auto res6 = minmax(str1, str2);
	cout << "result, min = " << res6.first << ", max = " << res6.second << endl;

	return 0;
}
