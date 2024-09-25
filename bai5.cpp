#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HANGHOA {
private:
    string maHang;
    string tenHang;

public:
    HANGHOA(string ma, string ten) : maHang(ma), tenHang(ten) {} // constructor có tham số

    void input() {
        cout << "Nhap ma hang: "; 
        cin >> maHang;
        cout << "Nhap ten hang: ";
        cin >> tenHang;
    }

    void output() const {
        cout << "Ma hang: " << maHang << endl;
        cout << "Ten hang: " << tenHang << endl;
    }
};

class MAYTINH : public HANGHOA {
private:
    string nhaSanXuat;
    int namSanXuat;
    float giaBanNiemYet;
    static float tyLeKhuyenMai;

public:
    MAYTINH() : HANGHOA("", ""), namSanXuat(0), giaBanNiemYet(0) {} // constructor mặc định

    MAYTINH(string ma, string ten, string nhaSX, int namSX, float giaBan)
        : HANGHOA(ma, ten), nhaSanXuat(nhaSX), namSanXuat(namSX), giaBanNiemYet(giaBan) {} // constructor có tham số

    void input() {
        HANGHOA::input();
        cout << "Nhap nha san xuat: ";
        cin >> nhaSanXuat;
        cout << "Nhap nam san xuat: ";
        cin >> namSanXuat;
        cout << "Nhap gia ban niem yet: ";
        cin >> giaBanNiemYet;
    }

    void output() const {
        HANGHOA::output();
        cout << "Nha san xuat: " << nhaSanXuat << endl;
        cout << "Nam san xuat: " << namSanXuat << endl;
        cout << "Gia ban niem yet: " << giaBanNiemYet << endl;
        cout << "Gia ban thuc te: " << calculateRealPrice() << endl;
    }

    float calculateRealPrice() const {
        return giaBanNiemYet - giaBanNiemYet * tyLeKhuyenMai;
    }

    bool operator>(const MAYTINH& other) const {
        return calculateRealPrice() > other.calculateRealPrice();
    }

    static void setTyLeKhuyenMai(float tyLe) {
        tyLeKhuyenMai = tyLe;
    }
};

float MAYTINH::tyLeKhuyenMai = 0; // Khởi tạo biến static

int main() {
    int n;
    cout << "Nhap so luong may tinh: ";
    cin >> n;

    vector<MAYTINH> danhSachMayTinh(n);

    cout << "Nhap thong tin cho " << n << " may tinh:" << endl;
    for (int i = 0; i < n; ++i) {
        danhSachMayTinh[i].input();
    }

    cout << "Thong tin cac may tinh:" << endl;
    for (int i = 0; i < n; ++i) {
        danhSachMayTinh[i].output();
        cout << endl;
    }

    cout << "Danh sach may tinh sau khi sap xep theo gia ban thuc te giam dan:" << endl;
    sort(danhSachMayTinh.begin(), danhSachMayTinh.end(), greater<MAYTINH>());
    for (const auto& mayTinh : danhSachMayTinh) {
        mayTinh.output();
        cout << endl;
    }

    return 0;
}
