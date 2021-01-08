#include <iostream>
#include <conio.h>
using namespace std;

class PhanSo
{
	private:
		int tuSo;
		int mauSo;
	public:
		void nhap();
		void showPS()
		{
			cout << tuSo << "/" << mauSo << endl;
		}
		PhanSo operator+(PhanSo); // kq = this + thamso
};

void PhanSo::nhap()
{
	cout << "Tu so: ";
	cin >> tuSo;
	cout << "Mau so: ";
	cin >> mauSo;
}

PhanSo PhanSo::operator+(PhanSo p)
{
	PhanSo temp;
	temp.tuSo = this->tuSo * p.mauSo + p.tuSo * this->mauSo;
	temp.mauSo = this->mauSo * p.mauSo;
	return temp;
}

int main()
{
	PhanSo ps, ps1, kq;
	ps.nhap();
	ps1.nhap();
	ps.showPS();
	ps1.showPS();
	kq = ps + ps1;
	cout << "Ket qua = ";
	kq.showPS();
	for (int i = 0; i < 5; ++i)
	{
		cout << "Kha dep trai!" << endl;
	}
	
	getch();
	return 0;
}
