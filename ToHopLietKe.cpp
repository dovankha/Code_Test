#include <iostream>
using namespace std;
#define MAX 100
int  n, k, A[MAX], X[MAX], OK = true, dem = 0, M;

void nhap(){
	cout << "n = ";
	cin >> n;
	for (int i=1; i<= n; i++){
		cout << "\nPhan tu " << i << " : ";
		cin >>A[i];
	}
	cout << "\nk = ";
	cin >> k;
	for (int i = 1; i <= k; i++){
		X[i] = i;
	}
	cout << "\nM = ";
	cin >> M;
}

void ketQua(){
	int sum=0;
	for (int i=1; i<=k; i++)
		sum += A[X[i]];
	if (sum == M){
	cout << "\nKet qua buoc: " << ++dem << " : ";
	for (int i = 1; i <=k; i++){
		cout << A[X[i]] << " ";
	}
	}
}

void xuLi(){
	int i = k;
	while (i>0 && X[i] == n-k+i){
		i--;
	}
	if (i > 0){
		X[i] = X[i] + 1;
		for (int j = i + 1; j <= k; j++){
			X[j] = X[i] + j - i;
		}
	}
	else
		OK = false;
}

int main()
{
	nhap();
	while(OK){
		ketQua();
		xuLi();
	}
	return 0;
}
