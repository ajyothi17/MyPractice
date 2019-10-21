#include <iostream>
#include <fstream>

using namespace std;

#if 0
int main(void)
{
	string name;

	ofstream oFile;

	oFile.open("sample.txt");
	oFile << "Jyothi";
	oFile.close();

	ifstream iFile;

	iFile.open("sample.txt");
	iFile >> name;
	cout << name << endl;
	iFile.close();

	return 0;
}
#endif

#if 0
int main(void)
{
	int count = 0;
	string line;

	ifstream file;

	file.open("Inheritance.cpp");

	while(getline(file, line))
	{
		count++;
	}

	cout << "no. of lines : " << count << endl;

	return 0;
}
#endif

#if 0
int main(void)
{
	int count = 0;
	string line;

	ifstream file;

	file.open("Inheritance.cpp");

	while(getline(file, line))
	{
		for(int i = 0; i < line.length(); i++)
		{
			if(((line[i] >= 'a') && (line[i] <= 'z')) || ((line[i] >= 'A') && (line[i] <= 'Z')))
				count++;
		}
	}

	cout << "no. of alphabets : " << count << endl;

	return 0;
}
#endif

#if 0
int main(void)
{
	int count = 0;
	string line;

	ifstream file;

	file.open("Inheritance.cpp");

	while(getline(file, line))
	{
		for(int i = 0; i < line.length(); i++)
		{
			if((line[i] >= '0') && (line[i] <= '9'))
				count++;
		}
	}

	cout << "no. of digits : " << count << endl;

	return 0;
}
#endif

#if 0
int main(void)
{
	int count = 0;
	string line;

	ifstream file;

	file.open("Inheritance.cpp");

	while(getline(file, line))
	{
		for(int i = 0; i < line.length(); i++)
		{
			if((line[i] == ' ') || (line[i] == '\n') || (line[i] == '\t'))
				count++;
		}
	}

	cout << "no. of spaces : " << count << endl;

	return 0;
}
#endif

#if 0
int main(void)
{
	int count = 0;
	string line;

	ifstream file;

	file.open("Inheritance.cpp");

	while(getline(file, line))
	{
		for(int i = 0; i < line.length(); i++)
		{
			switch(line[i])
			{
				case 'a':
				case 'A':
				case 'e':
				case 'E':
				case 'i':
				case 'I':
				case 'o':
				case 'O':
				case 'u':
				case 'U': count++;
						  break;
			}
		}
	}

	cout << "no. of vowels : " << count << endl;

	return 0;
}
#endif

#if 1
int main(void)
{
	int count = 0;
	string line;

	cout << "enter sentence" << endl;
	getline(cin, line);
	for(int i = 0; i < line.length(); i++)
	{
		if(line[i] == ' ')
			count++;
	}

	cout << "no. of words : " << count << endl;

	return 0;
}
#endif

