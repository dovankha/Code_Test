#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

class NhanVien
{
private:
	string ten;
	string diaChi;
	string SDT;
	string MSNV;
	string ngayHopDong;
protected:
	void getTenNV();
	void getMaNV();
public:
	NhanVien();
};

class MatHang
{
private:
	string maHang;
	string tenHang;
	float giaMua;
	float giaBan;
public:
	MatHang();
	MatHang(string TenHang, string MaHang, string GiaMua, string GiaBan);
	string getMaHang();
	string getTenHang();
	string getGiaMua();
	string getGiaBan();
};

class BanHang
{
	friend class NhanVien;
	friend class MatHang;
public:
	void BanHANG();
};

void BanHang::BanHANG()
{
	NhanVien nv;
	MaHang mh;
}

NhanVien::NhanVien(){};
MatHang::MatHang(){};
MatHang::MatHang(string TenHang, string Mahang, string GiaMua, string GiaBan)
{
	this->tenHang = TenHang;
	this->maHang = MaHang;
	this->giaMua = GiaMua;
	this->giaBan = GiaBan;
}

float MatHang::getGiaMua()
{
	return this->giaMua;
}

float MatHang::getGiaBan()
{
	return this->giaBan;
}

string MatHang::getMaHang()
{
	return this->maHang;
}

void writeFile(char *strfile, string strNoiDung);
string readFile(char *strfile);
void themMH(char *mh);
string DSMatHang(char *mh);
vector<string> split(string str, string c);
vector<MatHang> DSMH;
int str2int(string str);
int str2int(char *str);


int main()
{
	char mh[] = "MATHANG.DAT";
	char ql[] = "QLBH.DAT";
	char nv[] = "NhanVien.DAT";
	string manv, masp;
	vector<string> vMH, vNV, vQL, infoNV, infoMH;
	string str, rFile;
	string strMH, strNV, strQL;
	string giaBan;
	int luaChon;
	while(true)
	{
		cout << "Cac chuc nang: " << endl;
		cout << "1. Tao moi mat hang." << endl;
		cout << "2. Liet ke mat hang." << endl;
		cout << "3. Cau 2." << endl;
		cout << "4. Danh sach nhan vien." << endl;
		cout << "\nNhap lua chon: ";
		cin >> luaChon;
		if (luaChon == 1)
		{
			themMH(mh);
		}
		else if (luaChon == 2)
		{
			strMH=DSMatHang(mh);
			cout << "\nDanh sach mat hang: " << strMH << endl;
		}
		else if (luaChon == 3)
		{
			cout << "Ban hang" << endl;
			strMH=DSMatHang(mh);
			strNV=DSMatHang(nv);
			cout << "NV: " << strNV << endl;
			cout << "Chon ma nhan vien: ";
			cin >> manv;
			cout << "Giao dich san phan: " << strMH << endl;
			cin >> masp;
			vNV=split(strNV, "\n");
			for(int i=0; i<vNV.size();i++)
                 {
                     inforNV=split(vNV[i], "|");
                     if(manv==infoNV[0])
                         break;
                 }
                 vMH=split(strMH, "\n");
                 for(int i=0; i<vMH.size();i++)
                 {
                     inforMH=split(vMH[i], "|");
                     if(masp==infoMH[0])
                     {
                         giaban=infoMH[3];
                         break;
                     }
                 }
                 strQL=manv+"|"+masp+"|"+giaban;
                 cout<<strQL;
                 WriteFile(ql, strQL);
                 break;
		}
		else if (luaChon == 4)
		{
			cout << "\nDanh sach nhan vien: ";
			rFile = readFile(nv);
			vNV = split(rFile, "\n");
			vector<string> nv;
			for (int i=0; i<vNV.size(); i++)
			{
				cout << "Nhan vien " <<i++<< ": " << endl;
				nv = split(vNV[i], "|");
				cout << "Ma: " << nv[0] << endl;
				cout << "Ho ten: " << nv[1] << endl;
				cout << "Dia chi: " << nv[2] << endl;
			}
		}
		else 
			break;
	}
	
	getch();
	return 0;
}

int str2int(string str)
{
	int len = str.length();
	int num = 0;
	for (int i = len -1 ; i>=0; --i)
	{
		num += (int)(str[i] -'0') * pow(10, len-i-1);
	}
	return num;
}

int str2int(char *str)
{
	int num = atoi(str);
	return num;
}

void themMH(char *mh)
{
	string tenHang;
	string maHang;
	float giaMua;
	float giaBan;
	string str;

	cin.ignore();
	cout << "\nMa hang: ";
	getline(cin, maHang);
	cout << "\nTen hang: ";
	getline(cin, tenHang);
	cout << "\nGia mua: ";
	cin >> giaMua;
	cout << "\nGia ban: ";
	cin >> giaBan;

	MatHang MH(maHang, tenHang, giaMua, giaBan);
	DSMH.push_back(MH);
	str = maHang + " | " + tenHang + " | " + giaMua + " | " + giaBan;
	writeFile(mh, str);
}

string DSMatHang(char *mh)
{
	return readFile(mh);
}
// string DSNhanVien(char *nv)
// {
// 	return readFile(nv);
// }

vector<string> split (string str, string c)
{
	vector<string> V;
	while (!str.empty())
	{
		V.push_back(str.substr(), str.find(c));
		if (str.find(c) > str.size())
			break;
		else
			str.erase(0, str.find(c) + 1);
	}
	return V;
}

void writeFile(char *strfile, string strNoiDung)
{
	ofstream f(strFile, std::ios::out | std::ios::app);
	f << strNoiDung << endl;
	f.close();
}

string readFile(char *strfile)
{
	string str;
	ifstream textFile(strfile);
	stringstream ss;
	ss << textFile.rdbuf();
	str = ss.str();
	return str;
}
