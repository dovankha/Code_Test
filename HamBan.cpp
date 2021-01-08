#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

class sinhVien
{
	private:
		int ID;
		char name[30];
		float diem;
	public:
		void nhap();
		void show()
		{
			cout << ID << ", " << name << ", " << diem << endl;
		}
		friend void sapXep(sinhVien[], int);
};

void sinhVien::nhap()
{
	cout << "ID = ";
	cin >> ID;
	cout << "Name = ";
	cin >> name;
	do
	{
		cout << "Diem = ";
		cin >> diem;
	} while (diem < 0 || diem > 10);
}

void nhapDS(sinhVien a[], int &n)
{
	cout << "n = ";
	cin >> n;
	for (int i = 0; i < n; i++)
		a[i].nhap();
}

void showDS(sinhVien a[], int n)
{
	for (int i = 0; i < n; i++)
		a[i].show();
}

void hoanVi(sinhVien &a, sinhVien &b)
{
	sinhVien temp;
	temp = a;
	a = b;
	b = temp;
}

void sapXep(sinhVien a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].diem < a[j].diem)
			{
				hoanVi(a[i], a[j]);
			}
		}
	}
}

int main()
{
	sinhVien sv[100];
	int n;
	
	nhapDS(sv, n);
	cout << "Danh sach vua nhap: \n"; 
	showDS(sv, n);
	cout << "Danh sach sau khi sap xep: \n"; 
	sapXep(sv, n);
	showDS(sv, n);
	getch();
	return 0;
}
