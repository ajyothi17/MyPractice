#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int row;
	int col;

	cout << "enter row size : " << endl;
	cin >> row;

	cout << "enter col size : " << endl;
	cin >> col;

	vector<vector<int>> v2D(row, vector<int>(col, 0));

	cout << "vector elements : " << endl;
	for(int rowIndex = 0; rowIndex < row; rowIndex++)
	{
		for(int colIndex = 0; colIndex < col; colIndex++)
			cin >> v2D[rowIndex][colIndex];
	}
	
	for(int rowIndex = 0; rowIndex < row; rowIndex++)
	{
		for(int colIndex = 0; colIndex < col; colIndex++)
			cout << v2D[rowIndex][colIndex] << " ";

		cout << endl;
	}

	return 0;
}
