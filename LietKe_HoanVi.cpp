#include <iostream>
using namespace std;
#define MAX 100

int n, X[MAX], OK = true, dem = 0;
void nhap()
{
	cout << "n = ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		X[i] = i;
	}
}

void ketQua()
{
	cout << "\nKet qua buoc " << ++dem << " : ";
	for (int i = 1; i <= n; i++)
	{
		cout << X[i] << " ";
	}
}

void xuLi()
{
	int j = n - 1;
	while(j > 0 && X[j] > X[j+1])
		j--;
	if (j>0)
	{
		int k = n;
		while(X[j]>X[k])
			k--;
		int t = X[j];
		X[j] = X[k];
		X[k] = t;
		int r = j+1, s=n;
		while(r<=s) // lat nguoc doan tu j+1 den n
		{
			t=X[r]; 
			X[r]=X[s];
			X[s]=t;
			r++;
			s--;
		}
	}
	else
		OK = false;
}
int main()
{
	nhap();
	while(OK)
	{
		ketQua();
		xuLi();
	}
	return 0;
}
