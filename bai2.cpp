#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class NGUOI {
private:
    string maDinhDanh;
    string hoTen;

public:
    NGUOI() {}
    NGUOI(string ma, string ten) : maDinhDanh(ma), hoTen(ten) {}

    void nhapThongTin() {
        cout << "Nhap ma dinh danh: ";
        cin >> maDinhDanh;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
    }

    void xuatThongTin() {
        cout << "Ma dinh danh: " << maDinhDanh << endl;
        cout << "Ho ten: " << hoTen << endl;
    }

    ~NGUOI() {}
};

class NHANVIEN : public NGUOI {
private:
    int namSinh;
    float heSoLuong;
    static float tienPhuCap;

public:
    NHANVIEN() {}
    NHANVIEN(string ma, string ten, int nam, float heSo) : NGUOI(ma, ten), namSinh(nam), heSoLuong(heSo) {}

    static void setTienPhuCap(float tien) {
        tienPhuCap = tien;
    }

    void nhapThongTin() {
        NGUOI::nhapThongTin();
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cout << "Nhap he so luong: ";
        cin >> heSoLuong;
    }

    void xuatThongTin() {
        NGUOI::xuatThongTin();
        cout << "Nam sinh: " << namSinh << endl;
        cout << "He so luong: " << heSoLuong << endl;
    }

    float tinhLuong() const {
        return heSoLuong * 1550 + tienPhuCap;
    }

    bool operator>(const NHANVIEN& nv) const {
        return heSoLuong > nv.heSoLuong;
    }

    ~NHANVIEN() {}
};

float NHANVIEN::tienPhuCap = 0; // Khởi tạo biến tĩnh

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    vector<NHANVIEN> danhSachNV(n);

    cout << "Nhap thong tin cho " << n << " nhan vien:" << endl;
    for (int i = 0; i < n; ++i) {
        danhSachNV[i].nhapThongTin();
    }

    cout << "Thong tin cac nhan vien va luong tuong ung:" << endl;
    for (int i = 0; i < n; ++i) {
        danhSachNV[i].xuatThongTin();
        cout << "Luong: " << danhSachNV[i].tinhLuong() << endl;
        cout << endl;
    }

    // Sắp xếp danh sách nhân viên theo thứ tự giảm dần theo hệ số lương
    sort(danhSachNV.begin(), danhSachNV.end(), greater<NHANVIEN>());

    cout << "Danh sach nhan vien sau khi sap xep giam dan theo he so luong:" << endl;
    for (int i = 0; i < n; ++i) {
        danhSachNV[i].xuatThongTin();
        cout << "Luong: " << danhSachNV[i].tinhLuong() << endl;
        cout << endl;
    }

    return 0;
}
