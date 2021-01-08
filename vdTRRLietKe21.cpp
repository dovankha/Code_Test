#include <iostream>
using namespace std;
#define MAX 100
int n, X[MAX], OK = true, dem = 0;

void nhap(){
	cout << "n = ";
	cin >> n;
	for (int i = 0; i < n; i++){
		X[i] = 0;
	}
}

void ketQua(){
	cout << "\nKet qua buoc " << ++dem << " : ";
	for (int i = 1; i <= n; i++){
		cout << X[i] << " ";
	}
}

void xuLi(){
	int i = n;
	while(i>0 && X[i]!=0){
		X[i] = 0;
		i--;
	}
	if(i>0)
		X[i] = 1;
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
