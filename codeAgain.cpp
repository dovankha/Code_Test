#include <iostream>
#include <string>
#include <vector>

using namespace std;

void xuatMang(vector<int> arr)
{
	for (int i=0; i<arr.size(); i++)
		cout << "\nPhan tu thu " << i << " la: " << arr.at(i) << endl;
}

int main(int argc, char const *argv[])
{
	vector<int> arr;
	arr.resize(5);
	// xuatMang(arr);

	// arr.resize(3);
	// xuatMang(arr);

	// arr.resize(10);
	// xuatMang(arr);

	for (int i=0; i<5; i++)
	{
		arr.push_back(i);
	}
	xuatMang(arr);
	
	return 0;
}
