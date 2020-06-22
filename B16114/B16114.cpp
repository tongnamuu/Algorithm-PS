#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int x, n; cin >> x >> n;
    if (x < 0) {
        if (n == 1) cout << "INFINITE";
        else if (n == 0) cout << 0;
        else if (n & 1) cout << "ERROR";
        else cout << "ERROR";
    }
    else if (x == 0) {
        if (n == 1) cout << 0;
        else if (n == 0) cout << 0;
        else if (n & 1) cout << "ERROR";
        else cout << 0;
    }
    else {
        if (n == 0) cout << "INFINITE";
        else if (n == 1) cout << 0;
        else if (n & 1) cout << "ERROR";
        else {
            n >>= 1;
            int cnt = 0;
            x -= n;
            while (x > 0) {
                x -= n;
                ++cnt;
            }
            cout << cnt;
        }
    }
}