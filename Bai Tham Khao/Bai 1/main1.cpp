#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

struct NhanVien {
	string Ma;
	string HoTen;
	string SDT;
	int LCB;
	float HSL;
};
NhanVien Nhap() {
	NhanVien x;
	cout << "\nNhap thong tin\n";
	cout << "Nhap ma: ";
	cin.ignore();
	cin >> x.Ma;
	fflush(stdin);
	cout << "Nhap ho ten: ";
	getline(cin, x.HoTen);
	cout << "Nhap sdt: ";
	cin >> x.SDT;
	cout << "Nhap luong co ban: ";
	cin >> x.LCB;
	cout << "Nhap he so luong: ";
	cin >> x.HSL;
	return x;
}
void Xuat(NhanVien x) {
	cout << "\n\tThong tin nhan vien\n";
	cout << "Ma nhan vien: " << x.Ma << endl;
	cout << "Ho va ten: " << x.HoTen << endl;
	cout << "So dien thoai: " << x.SDT << endl;
	cout << "Luong co ban: " << x.LCB << endl;
	cout << "He so luong: " << x.HSL << endl;
}
void Xuat(NhanVien* a, int n) {
	cout << "\nDANH SACH NHAN VIEN\n";
	for (int i = 0; i < n; i++)
    	cout << left << setw(15) << a[i].Ma << setw(30) << a[i].HoTen <<
    	setw(15) << a[i].SDT << setw(15) << a[i].LCB << setw(15) << a[i].HSL << endl;
}
void Chen(NhanVien* a, int& n, NhanVien x, int k) {
	k--;
	if(k >= n){
		a[n] = x;
		n++;
		return;
	}

	for (int i = n; i > k; i--){
		a[i] = a[i - 1];
	}
	n++;
	a[k] = x;
}
void Tim_kiem(NhanVien* a, int n, int Loai, string s) { // 1 - ma, 2 - Ho ten, 3 - sdt
	int d = 0;
	for(int i=0; i<n; i++)
		switch (Loai) {
		case 1: {
			if (a[i].Ma == s) {
				Xuat(a[i]);
				return;
			}
			break;
		}
		case 2: {
			if (a[i].HoTen == s){
				Xuat(a[i]);
				return;
			}
			break;
		}
		case 3: {
			if (a[i].SDT == s){
				Xuat(a[i]);
				return;
			}
			break;
		}
		}
	if (d == 0)
		cout << "Khong co trong danh sach!\n";
}
void Delete(NhanVien* a, int& n, int k) {
	n--;
	for (int i = k; i < n; i++)
		a[i] = a[i + 1];
}
void Delete(NhanVien* a, int& n, int Loai, string s) { // 1 - ma, 2 - SDT
	for(int i=0; i<n; i++)
		switch (Loai) {
		case 1: {
			if (a[i].Ma == s) {
				Delete(a, n, i);
				return;
			}
			break;
		}
		case 2: {
			if (a[i].SDT == s) {
				Delete(a, n, i);
				i--;
			}
			break;
		}
	}
}
void Sort(NhanVien* a, int n, int Loai) {
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			switch (Loai) {
				case 1: {
					if (a[i].Ma > a[j].Ma) {
						NhanVien t = a[i];
						a[i] = a[j];
						a[j] = t;
					}
					break;
				}
				case 2: {
					if (a[i].HoTen > a[j].HoTen) {
						NhanVien t = a[i];
						a[i] = a[j];
						a[j] = t;
					}
					break;
				}
				case 3: {
					if (a[i].HSL > a[j].HSL) {
						NhanVien t = a[i];
						a[i] = a[j];
						a[j] = t;
					}
					break;
				}
			}
}
int main()
{
	NhanVien a[100];
	int n = 0;
	int chuc_nang;
	do {
		cout << "\n\tMENU\n";
		cout << "1. Nhap danh sach nhan vien." << endl;
		cout << "2. Them nhan vien vao vi tri k." << endl;
		cout << "3. Tim kiem nhan vien." << endl;
		cout << "4. Xoa nhan vien." << endl;
		cout << "5. Sap xep nhan vien." << endl;
		cout << "0. Thoat." << endl;
		cout << "Chuc nang: "; cin >> chuc_nang;
		switch (chuc_nang) {
		case 1: {
			int m;
			cout << "Nhap so luong: "; cin >> m;
			for (int i = 0; i < m; i++)
				a[n++] = Nhap();
			break;
		}
		case 2: {
			cout << "Nhap vi tri muon chen: ";
			int k; cin >> k;
			NhanVien x;
			x = Nhap();
			Chen(a, n, x, k);
			Xuat(a, n);
			break;
		}
		case 3: {
			cout << "\nLua chon tieu chi tim kiem: " << endl;
			cout << "1. Ma NV" << endl;
			cout << "2. Ho Ten" << endl;
			cout << "3. SDT" << endl;
			int chitieu; cin>>chitieu;
			cout << "Nhap tieu chi: ";
			cin.ignore();
			string s; getline(cin, s);
			Tim_kiem(a, n, chitieu, s);
			break;
		}
		case 4: {
			cout << "\nLua chon tieu chi muon xoa: " << endl;
			cout << "1. Ma NV" << endl;
			cout << "2. SDT" << endl;
			int chitieu; cin>>chitieu;
			cout << "Nhap tieu chi: ";
			cin.ignore();
			string s; getline(cin, s);
			Delete(a, n, chitieu, s);
			Xuat(a, n);
			break;
		}
		case 5: {
			cout << "\nLua chon tieu chi sap xep: " << endl;
			cout << "1. Ma NV" << endl;
			cout << "2. Ho Ten" << endl;
			cout << "3. He So Luong" << endl;
			int chitieu; cin >> chitieu;
			Sort(a, n, chitieu);
			Xuat(a, n);
			break;
		}
		case 0: {
			chuc_nang = 0;
			break;
		}
		default: {
			break;
		}
		}
	} while (chuc_nang != 0);

	return 0;
}