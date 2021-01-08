#include <iostream>
using namespace std;

int a[100], dem = 0, n;

void Init()
{
	cout << "\nNhap n = ";
	cin >> n;
}

bool kiemTra()
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0 && a[i + 1] == 0)
			return false;
	}
}

void result()
{
	for (int i = 1; i <= n; i++)
	{
		cout << a[i];
	}
}

void try1(int i)
{
	for (int j = 0; j <= 1; j++)
	{
		a[i] = j;
		if (i == n)
		{
			if (kiemTra())
			{
				cout << ++dem << " : ";
				result();
				cout << endl;
			}
		}
		else
			try1(i + 1);
	}
}

int main()
{
	Init();
	try1(1);
	return 0;
}
