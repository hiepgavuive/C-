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
    float TongLuong;
    NhanVien* next;

    NhanVien() : Ma(0), HoTen(0), SDT(0), LCB(0), HSL(0), TongLuong(0), next(nullptr) {}
    NhanVien(string x, string y, string z, int t, float m, float n) : Ma(x), HoTen(y), SDT(z), LCB(t), HSL(m), TongLuong(n), next(nullptr) {}
};
void Nhap(NhanVien *&head) {

	cout << "\nNhap thong tin\n";
	cout << "Nhap ma: ";
	cin.ignore();
	string ma; getline(cin, ma);
	fflush(stdin);
	cout << "Nhap ho ten: ";
	string hoten; getline(cin, hoten);
	fflush(stdin);
	cout << "Nhap sdt: ";
	string sdt; getline(cin, sdt);
	cout << "Nhap luong co ban: ";
	int lcb; cin>>lcb;
	cout << "Nhap he so luong: ";
	float hsl; cin>>hsl;
    float tl = hsl*lcb;

    NhanVien* pp = new NhanVien(ma, hoten, sdt, lcb, hsl, tl);
    pp->next = head;
	head = pp;
}
void Xuat1NV(NhanVien* head){
    cout << "\n\tThong tin nhan vien\n";
	cout << "Ma nhan vien  " << head->Ma << endl;
	cout << "Ho va Ten     " << head->HoTen << endl;
	cout << "So dien thoai " << head->SDT << endl;
	cout << "Luong co ban  " << head->LCB << endl;
	cout << "He so luong   " << head->HSL << endl;
    cout << "Tong luong    " << head->TongLuong << endl;
}
void Xuat(NhanVien* head) {
	if(head == nullptr){
		cout << "\nKHONG CO NHAN VIEN NAO TRONG DANH SACH\n";
	}

    NhanVien* p = head;

	cout << "\nDANH SACH NHAN VIEN\n";

    while(p != nullptr){
        cout << left << setw(15) << p->Ma << setw(30) << p->HoTen <<
    	setw(15) << p->SDT << setw(15) << p->LCB << setw(15) << p->HSL << setw(15) << p->TongLuong << endl;

        p = p->next;
    }
}
void Chen(NhanVien *&head, int k) {
	cout << "\nNhap thong tin nhan vien duoc them vao\n";
	cout << "Nhap ma: ";
	cin.ignore();
	string ma; getline(cin, ma);
	fflush(stdin);
	cout << "Nhap ho ten: ";
	string hoten; getline(cin, hoten);
	cout << "Nhap sdt: ";
	string sdt; getline(cin, sdt);
	cout << "Nhap luong co ban: ";
	int lcb; cin>>lcb;
	cout << "Nhap he so luong: ";
	float hsl; cin>>hsl;
    float tl = hsl*lcb;

    NhanVien* pp = new NhanVien(ma, hoten, sdt, lcb, hsl, tl);
    
	if(k == 1){
		pp->next = head;
		head = pp;
		return;
	}
	
	NhanVien* p = head;
    for(int i=0; i<k-2; i++){
		if(p->next == nullptr){
    		p->next = pp;
			return;
		}
		p = p->next;
	}
    pp->next = p->next;
    p->next = pp;
}
void Tim_kiem(NhanVien* head, int Loai, string s) { // 1 - ma, 2 - Ho ten, 3 - sdt
	if(head == nullptr) return;

    NhanVien* p = head;
	while(p != nullptr){
		switch (Loai) {
		case 1: {
			if (p->Ma == s) {
				Xuat1NV(p);
                return;
			}
			break;
		}
		case 2: {
			if (p->HoTen == s){
				Xuat1NV(p);
                return;
			}
			break;
		}
		case 3: {
			if (p->SDT == s){
				Xuat1NV(p);
                return;
			}
			break;
		}
		}
		p = p->next;
	}
	cout << "Khong co trong danh sach!\n";
}
void Delete(NhanVien *&head, int Loai, string s) { // 1 - ma, 2 - SDT
	if(head == nullptr) return;

    NhanVien* p = head;
    NhanVien* pp = nullptr;
    while(p != nullptr){
		switch (Loai) {
		case 1: {
			if (p->Ma == s) {
				if(pp == nullptr){
					head = head->next;
					return;
				}else{
					pp->next = p->next;
					return;
				}
			}
			break;
		}
		case 2: {
			if (p->SDT == s) {
				if(pp == nullptr){
					head = head->next;
					return;
				}else{
					pp->next = p->next;
					return;
				}
			}
			break;
		}
		}
		pp = p;
        p = p->next;
	}
}
void Swap(NhanVien *&p, NhanVien *&pp){
    p->Ma.swap(pp->Ma);
    p->SDT.swap(pp->SDT);
    p->HoTen.swap(pp->HoTen);
    swap(p->LCB, pp->LCB);
    swap(p->HSL, pp->HSL);
    swap(p->TongLuong, pp->TongLuong);
}
void Sort(NhanVien *&head, int Loai) {
    if(head == nullptr) return;

	NhanVien* p = head;
    while(p->next != nullptr){
        NhanVien* pp = p;
        while(pp->next != nullptr){
            switch (Loai) {
				case 1: {
					if (pp->next->Ma < pp->Ma) {
						Swap(pp->next, pp);
					}
					break;
				}
				case 2: {
					if (pp->next->HoTen < pp->HoTen) {
						Swap(pp->next, pp);
					}
					break;
				}
				case 3: {
					if (pp->next->HSL < pp->HSL) {
						Swap(pp->next, pp);
					}
					break;
				}
			}
            pp = pp->next;
        }
        p = p->next;
    }
}
int main()
{
	NhanVien* head = nullptr;

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
				Nhap(head);
			break;
		}
		case 2: {
			cout << "Nhap vi tri muon chen: ";
			int k; cin >> k;
			Chen(head, k);
			Xuat(head);
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
			Tim_kiem(head, chitieu, s);
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
			Delete(head, chitieu, s);
			Xuat(head);
			break;
		}
		case 5: {
			cout << "\nLua chon tieu chi sap xep: " << endl;
			cout << "1. Ma NV" << endl;
			cout << "2. Ho Ten" << endl;
			cout << "3. He So Luong" << endl;
			int chitieu; cin >> chitieu;
			Sort(head, chitieu);
			Xuat(head);
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