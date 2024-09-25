#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SACH {
private:
    string maSach;
    string tenSach;

public:
    SACH() {}
    SACH(string ma, string ten) : maSach(ma), tenSach(ten) {}

    void input() {
        cout << "Nhap ma sach: ";
        cin >> maSach;
        cout << "Nhap ten sach: ";
        cin >> tenSach;
    }

    void output() const {
        cout << "Ma sach: " << maSach << endl;
        cout << "Ten sach: " << tenSach << endl;
    }

    string getMaSach() const {
        return maSach;
    }
};

class MUONTRA : public SACH {
private:
    string maDocGia;
    int soLuong;
    static float phiMuonTra;

public:
    MUONTRA() : soLuong(0) {}
    MUONTRA(string ma, string ten, string maDG, int sl) : SACH(ma, ten), maDocGia(maDG), soLuong(sl) {}

    void input() {
        SACH::input();
        cout << "Nhap ma doc gia: ";
        cin >> maDocGia;
        cout << "Nhap so luong: ";
        cin >> soLuong;
    }

    void output() const {
        SACH::output();
        cout << "Ma doc gia: " << maDocGia << endl;
        cout << "So luong: " << soLuong << endl;
        cout << "So tien muon tra: " << calculateFee() << endl;
    }

    float calculateFee() const {
        return soLuong * phiMuonTra;
    }

    static void setPhiMuonTra(float phi) {
        phiMuonTra = phi;
    }

    int getSoLuong() const {
        return soLuong;
    }

    string getMaDocGia() const {
        return maDocGia;
    }
};

float MUONTRA::phiMuonTra = 10000; // Khởi tạo biến static

int main() {
    int n;
    cout << "Nhap so luong muon tra: ";
    cin >> n;

    vector<MUONTRA> danhSachMuonTra(n);

    cout << "Nhap thong tin cho " << n << " muon tra:" << endl;
    for (int i = 0; i < n; ++i) {
        danhSachMuonTra[i].input();
    }

    cout << "Thong tin cac muon tra:" << endl;
    for (int i = 0; i < n; ++i) {
        danhSachMuonTra[i].output();
        cout << endl;
    }

    // In ra màn hình các độc giả có số lượng mượn > 10 cuốn
    cout << "Danh sach doc gia muon tren 10 cuon: " << endl;
    for (const auto& muonTra : danhSachMuonTra) {
        if (muonTra.getSoLuong() > 10) {
            cout << muonTra.getMaDocGia() << endl;
        }
    }

    // Tìm mã các độc giả có số tiền cược nhiều nhất
    float maxFee = 0;
    vector<string> maxFeeReaders;
    for (const auto& muonTra : danhSachMuonTra) {
        float fee = muonTra.calculateFee();
        if (fee > maxFee) {
            maxFee = fee;
            maxFeeReaders.clear();
            maxFeeReaders.push_back(muonTra.getMaDocGia());
        } else if (fee == maxFee) {
            maxFeeReaders.push_back(muonTra.getMaDocGia());
        }
    }

    // In ra mã các độc giả có số tiền cược nhiều nhất
    cout << "Doc gia co so tien muon tra nhieu nhat: ";
    for (const auto& reader : maxFeeReaders) {
        cout << reader << " ";
    }
    cout << endl;

    return 0;
}
