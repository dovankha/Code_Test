#include <iostream>
using namespace std;
#define MAX 100
int n, k, M, X[MAX], A[MAX], dem = 0;

void nhap()
{
	cout << "n = ";
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cout << "Nhap phan tu thu " << i << " : ";
		cin >> A[i];
	}
	cout << "\nk (k<n) = ";
	cin >> k;
	cout << "\nM = ";
	cin >> M;
}

void xuLi(int i)
{
	for (int j=X[i-1]+1; j<=n-k+i; j++)
	{
		X[i]=j;
		if (i==k)
		{
			int sum=0;
			for (int j=1; j<=k; j++)
				sum += A[X[j]];
			if (sum == M)
			{
				cout << "\nDay con thu " << ++dem << " : ";
				for (int j=1; j<=k; j++)
					cout << A[X[j]] << " ";
			}
		}
		else
			xuLi(i + 1);
	}
}

int main()
{
	nhap();
	xuLi(1);
	return 0;
}
