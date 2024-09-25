#include <iostream>
using namespace std;

int main() {
    int n = 8;
    int kt = n * 2 - 2;
    
    cout << "3. Tam giac can" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= kt; j++) {
            cout << " ";
        }
        for (int j = 1; j <= i * 2 - 1; j++) {
            cout << "* ";
        }
        kt -= 2;
        cout << "\n";
    }

    cout << "\n4. Tam giac can nguoc" << endl;
    kt = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= kt; j++) {
            cout << " ";
        }
        for (int j = 1; j <= i * 2 - 1; j++) {
            cout << "* ";
        }
        kt += 2;
        cout << "\n";
    }

    return 0;
}
