#include <iostream>
using namespace std;

int n, chuaXet[100], dem=0, X[100];

void nhap()
{
	cout << "Nhap n = ";
	cin >> n;
	for (int i =1; i<=n; i++)
	{
		chuaXet[i] = true;
	}
}

void ketQua()
{
	cout << "\nKet qua buoc " << ++dem << " : ";
	for (int i=1; i<=n; i++)
	{
		cout << X[i] << " ";
	}
}

void xuLi(int i)
{
	for (int j=1; j<=n; j++)
	{
		if (chuaXet[j])
		{
			X[i]=j;
			chuaXet[j]=false;
			if(i==n)
				ketQua();
			else
				xuLi(i+1);
			chuaXet[j]=true;
		}
	}
}
int main()
{
	nhap();
	xuLi(1);
	return 0;
}
