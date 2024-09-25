#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class PhuongTienGiaoThong {
protected:
    string hangSanXuat;
    string tenPhuongTien;
    int namSanXuat;
    float vanTocToiDa;

public:
    PhuongTienGiaoThong() {}
    PhuongTienGiaoThong(string hang, string ten, int nam, float tocDo) 
        : hangSanXuat(hang), tenPhuongTien(ten), namSanXuat(nam), vanTocToiDa(tocDo) {}

    void nhapThongTin() {
        cout << "Nhap hang san xuat: ";
        cin.ignore();
        getline(cin, hangSanXuat);
        cout << "Nhap ten phuong tien: ";
        getline(cin, tenPhuongTien);
        cout << "Nhap nam san xuat: ";
        cin >> namSanXuat;
        cout << "Nhap van toc toi da: ";
        cin >> vanTocToiDa;
    }

    void xuatThongTin() {
        cout << "Hang san xuat: " << hangSanXuat << endl;
        cout << "Ten phuong tien: " << tenPhuongTien << endl;
        cout << "Nam san xuat: " << namSanXuat << endl;
        cout << "Van toc toi da: " << vanTocToiDa << endl;
    }

    virtual ~PhuongTienGiaoThong() {}
};

class OTo : public PhuongTienGiaoThong {
private:
    int soChoNgoi;
    string kieuDongCo;

public:
    OTo() {}
    OTo(string hang, string ten, int nam, float tocDo, int choNgoi, string dongCo) 
        : PhuongTienGiaoThong(hang, ten, nam, tocDo), soChoNgoi(choNgoi), kieuDongCo(dongCo) {}

    void nhapThongTin() {
        PhuongTienGiaoThong::nhapThongTin();
        cout << "Nhap so cho ngoi: ";
        cin >> soChoNgoi;
        cout << "Nhap kieu dong co: ";
        cin.ignore();
        getline(cin, kieuDongCo);
    }

    void xuatThongTin() {
        PhuongTienGiaoThong::xuatThongTin();
        cout << "So cho ngoi: " << soChoNgoi << endl;
        cout << "Kieu dong co: " << kieuDongCo << endl;
    }

    float tinhVanTocCoSo() const {
        return vanTocToiDa / 4; // Giả sử mỗi ô tô có 4 bánh
    }

    bool operator<(const OTo& oto) const {
        return tinhVanTocCoSo() < oto.tinhVanTocCoSo();
    }

    ~OTo() {}
};

int main() {
    int n;
    cout << "Nhap so luong oto: ";
    cin >> n;
    vector<OTo> danhSachOTo(n);

    cout << "Nhap thong tin cho " << n << " oto:" << endl;
    for (int i = 0; i < n; ++i) {
        danhSachOTo[i].nhapThongTin();
    }

    cout << "Thong tin cac oto va toc do co so tuong ung:" << endl;
    for (int i = 0; i < n; ++i) {
        danhSachOTo[i].xuatThongTin();
        cout << "Van toc co so: " << danhSachOTo[i].tinhVanTocCoSo() << endl;
        cout << endl;
    }

    sort(danhSachOTo.begin(), danhSachOTo.end());

    cout << "Danh sach oto sau khi sap xep giam dan theo van toc co so:" << endl;
    for (int i = 0; i < n; ++i) {
        danhSachOTo[i].xuatThongTin();
        cout << "Van toc co so: " << danhSachOTo[i].tinhVanTocCoSo() << endl;
        cout << endl;
    }

    return 0;
}
