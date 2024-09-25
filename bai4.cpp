#include <iostream>
#include <vector>

using namespace std;

class DATE {
protected:
    int ngay, thang, nam;

public:
    DATE() : ngay(1), thang(1), nam(2000) {}

    DATE(int ngay, int thang, int nam) : ngay(ngay), thang(thang), nam(nam) {}

    void nhap() {
        cout << "Nhap ngay, thang, nam: ";
        cin >> ngay >> thang >> nam;
    }

    void xuat() {
        cout << ngay << "/" << thang << "/" << nam << endl;
    }
};

class CANBO : public DATE {
private:
    int maCanBo;
    string tenCanBo;
    double luongCaoBan;

public:
    CANBO() : DATE(), maCanBo(0), tenCanBo(""), luongCaoBan(0) {}

    CANBO(int ngay, int thang, int nam, int maCanBo, string tenCanBo, double luongCaoBan)
        : DATE(ngay, thang, nam), maCanBo(maCanBo), tenCanBo(tenCanBo), luongCaoBan(luongCaoBan) {}

    void nhap() {
        DATE::nhap();
        cout << "Nhap ma can bo: ";
        cin >> maCanBo;
        cout << "Nhap ten can bo: ";
        cin.ignore();
        getline(cin, tenCanBo);
        cout << "Nhap luong cao ban: ";
        cin >> luongCaoBan;
    }

    void xuat() {
        DATE::xuat();
        cout << "Ma can bo: " << maCanBo << endl;
        cout << "Ten can bo: " << tenCanBo << endl;
cout << "Luong cao ban: " << luongCaoBan << endl;
        cout << "Luong: " << tinhLuong() << endl;
        cout << endl;
    }

    double tinhLuong() {
        return luongCaoBan + 100; // tiền phụ cấp chức vụ = 100
    }

    static void inCanBoLuongThapNhat(vector<CANBO>& canBo) {
        CANBO canBoLuongThapNhat = canBo[0];
        for (int i = 1; i < canBo.size(); i++) {
            if (canBo[i].tinhLuong() < canBoLuongThapNhat.tinhLuong()) {
                canBoLuongThapNhat = canBo[i];
            }
        }
        canBoLuongThapNhat.xuat();
    }
};

int main() {
    DATE date;
    date.nhap();
    date.xuat();

    int n;
    cout << "Nhap so luong can bo: ";
    cin >> n;

    vector<CANBO> canBo(n);
    for (int i = 0; i < n; i++) {
        canBo[i].nhap();
    }

    cout << "Thong tin cac can bo: " << endl;
    for (int i = 0; i < n; i++) {
        canBo[i].xuat();
    }

    cout << "Luong cua cac can bo: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Can bo " << i + 1 << ": " << canBo[i].tinhLuong() << endl;
    }

    cout << "Cac can bo co luong thap nhat: " << endl;
    CANBO::inCanBoLuongThapNhat(canBo);

    return 0;
}