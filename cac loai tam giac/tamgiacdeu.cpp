#include <iostream>
using namespace std;

int main() {
    int n, i, j;

    cout << "Nhap chieu cao cua tam giac: ";
    cin >> n;

    cout << "Ve tam giac deu: \n";
    for(i = 1; i <= n; i++) {
        // In khoảng trắng để dịch sang phải
        for(j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // In các dấu '*' tạo thành tam giác
        for(j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }

        cout << "\n";
    }

    return 0;
}
