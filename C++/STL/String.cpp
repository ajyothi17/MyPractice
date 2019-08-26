#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void)
{
	string str1 = "Hello";
	string str2 = "World";

	cout << "Given String1 : " << str1 << endl;
	cout << "Given String2 : " << str2 << endl;

	cout << "concat strings : " << str1 + str2 << endl;
	
	cout << "length of str1 : " << str1.length() << endl;
	cout << "length of str2 : " << str2.length() << endl;
	cout << "length of str1 + str2 : " << (str1 + str2).length() << endl;

	cout << "char at 0 in str1 - " << str1[0] << endl;
	cout << "char at 2 in str1 - " << str1[2] << endl;
	cout << "char at 3 in str1 - " << str1[3] << endl;

//	str2 = str1;

	if(str1 == str2)
		cout << "strings are equal" << endl;

	else if(str1 > str2)
		cout << str1 << " is lexicografically greater" << endl;

	else
		cout << str2 << " is lexicografically greater" << endl;

	string str3;
	string str4;

	str3.assign(str1);
	cout << "str3.assign(str1) - " << str3 <<  endl;

	str3.assign(str2, 1, 3);
	cout << "str3.assign(str2, 1, 3) - " << str3 << endl;

	str3.assign("Hi");
	cout << "str3.assign(\"Hi\") - " << str3 << endl;

	str3.assign("HiHello", 4);
	cout << "str3.assign(\"Hi\", 4) - " << str3 << endl;

	str3.assign(4, 'a');
	cout << "str3.assign(4, 'a') - " << str3 << endl;

	cout << "int value 1234 to string - " << to_string (1234) << endl;
	cout << "float value 12.34 to string - " << to_string(12.34f) << endl;
	cout << "double value 12.34 to string - " << to_string(12.34) << endl;
	cout << "to_string(10+20+30+40) - " << to_string(10+20+30+40) << endl;
	cout << "to_string(10+20+12.34) - " << to_string(10+20+12.34) << endl;
	cout << "to_string(10/20+30*2) - " << to_string(10/20+30*2) << endl;

	string str = "Hello";

	str.append("world");
	cout << str << endl;

	str1 = "Jyothi";

	str.append(str1.begin()+2, str1.end()-2);
	cout << str << endl;

	str = "c++ programming";

	cout << str.substr(4, 10) << endl;

	str1 = "hello";
	str2 = "hiworld";
	str3 = "world";
	str4 = "helloworld";

	if(0 == str1.compare(str2))
		cout << "string are equal" << endl;

	else
		cout << "string are not equal" << endl;

	if(0 == (str4.compare(5, 5, str3)))
		cout << "strings are equal" << endl;

	else
		cout << "strings are not equal" << endl;

	if(0 == (str2.compare(2, 5, str4, 5, 5)))
		cout << "strings are equal" << endl;

	else
		cout << "strings are not equal" << endl;

	char c = 'j';

	string s(3, c);

	cout << "char to str : " << s << endl;

	cout << "int to str : " << to_string(1234) << endl;

	cout << "hex string to int using stoi()" << stoi("FF", 0, 16) << endl;
	cout << "oct string to int using stoi()" << stoi("377", 0, 8) << endl;
	cout << "binary string to int using stoi()" << stoi("11111111", 0, 2) << endl;

	str1 = "HelloWorld";

	set <char> sObj(begin(str1), end(str1));

	cout << "string to set using set const" << endl;
	for(auto itr : sObj)
		cout << itr << " ";
	cout << endl;

	set <char> sObj1;

	for(auto i : str1)
		sObj1.insert(i);

	cout << "string to set using insert()" << endl;
	for(auto itr : sObj1)
		cout << itr << " ";
	cout << endl;

	return 0;
}
