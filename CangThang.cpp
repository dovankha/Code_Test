#include <iostream>
using namespace std;

class HCN{
	protected:
		int dai;
		int rong;
	public:
		HCN(){
		};
		HCN(int cDai, int cRong){
			this->dai = cDai;
			this->rong = cRong;
		};
		void tinhChuVi(){
			cout << (dai + rong) * 2;
		}
		void tinhDienTich(){
			cout << dai * rong;
		}
};

class HV:public HCN{
	public:
		HV hinhVuong(int a){
			this->dai = this->rong = a;
		}
};

int main(){
	HV hv;
	int canh;
	cout << "Nhap vao canh hinh vuong: ";
	cin >> canh;
	hv.hinhVuong(canh);
	cout << "\nChu vi: ";
	hv.tinhChuVi();
	cout << "\nDien tich: ";
	hv.tinhDienTich();
	
	return 0;
}
