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
    NhanVien* nextnv;

    NhanVien() : Ma(0), HoTen(0), SDT(0), LCB(0), HSL(0), TongLuong(0), nextnv(nullptr) {}
    NhanVien(string x, string y, string z, int t, float m, float n) : Ma(x), HoTen(y), SDT(z), LCB(t), HSL(m), TongLuong(n), nextnv(nullptr) {}
};
struct CongTy {
    string MaCy;
    string Ten;
    string DiaChi;
    
    NhanVien* nextnv;
    CongTy* nextcy;

    CongTy(NhanVien* nv) : MaCy(0), Ten(0), DiaChi(0), nextnv(nv), nextcy(nullptr) {}
    CongTy(string x, string y, string z, NhanVien* nv) : MaCy(x), Ten(y), DiaChi(z), nextnv(nv), nextcy(nullptr) {}
};
void Nhap(NhanVien *&head) {
    cout << "\nNhap thong tin nhan vien\n";
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
    pp->nextnv = head;
	head = pp;
}
void Nhapcy(CongTy *&head) {
	cout << "\nNhap thong tin\n";
	cout << "Nhap ma cong ty: ";
    cin.ignore();
	string ma; getline(cin, ma);
	cout << "Nhap ten cong ty: ";
	string ten; getline(cin, ten);
	cout << "Nhap dia chi: ";
	string dt; getline(cin, dt);
	cout << "So luong nhan vien trong cong ty: ";
    int x; cin>>x;
    NhanVien* head_nv = nullptr;
    if(x != 0){
        for(int i=0; i<x; i++){
            Nhap(head_nv);
        }
    }

    CongTy* pp = new CongTy(ma, ten, dt, head_nv);
    if(head == nullptr){
        head = pp;
        return;
    }
    
    pp->nextcy = head;
    head = pp;
}
void Xuat1NV(NhanVien* head){
    cout << "\n\tThong tin nhan vien\n";
	cout << "Ma nhan vien: " << head->Ma << endl;
	cout << "Ho va Ten: " << head->HoTen << endl;
	cout << "So dien thoai: " << head->SDT << endl;
	cout << "Luong co ban: " << head->LCB << endl;
	cout << "He so luong: " << head->HSL << endl;
    cout << "Tong luong: " << head->TongLuong << endl;
}
void XuatNV(NhanVien* head) {
    if(head == nullptr) return;
    NhanVien* p = head;

	cout << "Danh sach Nhan Vien\n";

    while(p != nullptr){
        cout << left << setw(15) << p->Ma << setw(30) << p->HoTen <<
    	setw(15) << p->SDT << setw(15) << p->LCB << setw(15) << p->HSL << setw(15) << p->TongLuong << endl;

        p = p->nextnv;
    }
}
void Xuat(CongTy* head_cy){
    CongTy* p = head_cy;

    cout << "\nDANH SACH CONG TY\n";

    while(p != nullptr){
        cout << "\nMa cong ty: " << p->MaCy << endl;
        cout << "Ten cong ty: " << p->Ten << endl;
        cout << "Dia chi cong ty: " << p->DiaChi << endl;
        XuatNV(p->nextnv);

        p = p->nextcy;
    }
}
void Chen(CongTy *&head_cy, int k) {
	cout << "\nNhap thong tin\n";
	cout << "Nhap ma cong ty: ";
    cin.ignore();
	string ma; getline(cin, ma);
    fflush(stdin);
	cout << "Nhap ten cong ty: ";
	string ten; getline(cin, ten);
	cout << "Nhap dia chi: ";
	string dt; getline(cin, dt);
	cout << "So luong nhan vien trong cong ty: ";
    int x; cin>>x;
    NhanVien* head_nv = nullptr;
    if(x != 0){
        for(int i=0; i<x; i++){
            Nhap(head_nv);
        }
    }

    CongTy* pp = new CongTy(ma, ten, dt, head_nv);

    if(k == 1){
		pp->nextcy = head_cy;
		head_cy = pp;
		return;
	}
	
	CongTy* p = head_cy;
    for(int i=0; i<k-2; i++){
		if(p->nextcy == nullptr){
    		p->nextcy = pp;
			return;
		}
		p = p->nextcy;
    }
    pp->nextcy = p->nextcy;
    p->nextcy = pp;
}
void Delete(CongTy *&head_cy, int Loai, string s) { // 1 - ma, 2 - ten cong ty
	if(head_cy == nullptr) return;
    
    CongTy* p = head_cy;
    CongTy* pp = nullptr;
    while(p != nullptr){
		switch (Loai) {
		case 1: {
			if (p->MaCy == s) {
                if(pp == nullptr){
                    head_cy = head_cy->nextcy;
                    return;
                }else{
                    pp->nextcy = p->nextcy;
				    return;
                }
				
			}
			break;
		}
		case 2: {
			if (p->Ten == s) {
				if(pp == nullptr){
                    head_cy = head_cy->nextcy;
                    return;
                }else{
                    pp->nextcy = p->nextcy;
				    return;
                }
			}
			break;
		}
	    }
        pp = p;
        p = p->nextcy;
    }
}
void Tim_kiem(CongTy* head_cy, int Loai, string s) { // 1 - ma, 2 - Ho ten, 3 - sdt
	if(head_cy == nullptr || head_cy->nextnv == nullptr) return;

    CongTy* pp = head_cy;
    while(pp != nullptr){
        NhanVien* p = pp->nextnv;
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
            }
            p = p->nextnv;
        }
        pp = pp->nextcy;
    }

    cout << "Khong co trong danh sach!\n";
}
void Push(CongTy *&head_cy, string s){
    CongTy* p = head_cy;

    while(p != nullptr){
        if(p->MaCy == s){
            Nhap(p->nextnv);
            return;
        }
        p = p->nextcy;
    }
    cout << "Khong tim thay cong ty do\n";
}
int main()
{
    NhanVien* head_nv = nullptr;
	CongTy* head_cy = nullptr;

	int chuc_nang;
	do {
		cout << "\n\tMENU\n";
		cout << "1. Nhap danh sach Cong ty va Nhan vien." << endl;
		cout << "2. Them 1 Cong ty vao vi tri bat ki." << endl;
		cout << "3. Xoa Cong ty." << endl;
		cout << "4. Tim nhan vien." << endl;
		cout << "5. Them mot nhan vien cong ty bat ky." << endl;
		cout << "0. Thoat." << endl;
		cout << "Chuc nang: "; cin >> chuc_nang;
		switch (chuc_nang) {
		case 1: {
			int m;
			cout << "Nhap so luong cong ty: "; cin >> m;
			for (int i = 0; i < m; i++)
				Nhapcy(head_cy);
			break;
		}
		case 2: {
			cout << "Nhap vi tri muon chen: ";
			int k; cin >> k;
			Chen(head_cy, k);
			Xuat(head_cy);
			break;
		}
		case 3: {
			cout << "\nLua chon tieu chi muon xoa: " << endl;
			cout << "1. Ma Cong ty" << endl;
			cout << "2. Ten Cong ty" << endl;
			int chitieu; cin>>chitieu;
			cout << "Nhap tieu chi: ";
            cin.ignore();
			string s; getline(cin, s);
			Delete(head_cy, chitieu, s);
            Xuat(head_cy);
			break;
		}
		case 4: {
			cout << "\nLua chon tieu chi muon tim kiem: " << endl;
			cout << "1. Ma NV" << endl;
			cout << "2. Ho Ten" << endl;
			int chitieu; cin>>chitieu;
			cout << "Nhap tieu chi: ";
            cin.ignore();
			string s; getline(cin, s);
			Tim_kiem(head_cy, chitieu, s);
			break;
		}
		case 5: {
			cout << "Ma Cong ty them 1 nhan vien: ";
            cin.ignore();
            string s; getline(cin, s);
            Push(head_cy, s);
            Xuat(head_cy);
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