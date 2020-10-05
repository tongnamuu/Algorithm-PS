#include <iostream>
#include <string>
using namespace std;
int a[2000001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int f = 0, r = 0;
    int n; cin >> n;
    while (n--) {
        string cmd; cin >> cmd;
        if (cmd == "push") {
            int num; cin >> num;
            a[r++] = num;
        }
        else if (cmd == "pop") {
            if (r == f) cout << -1 << '\n';
            else {
                cout << a[f] << '\n';
                ++f;
            }
        }
        else if (cmd == "size") {
            cout << r - f << '\n';
        }
        else if (cmd == "empty") {
            if (r == f) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (cmd == "front") {
            if (r == f) cout << -1 << '\n';
            else cout << a[f] << '\n';
        }
        else if (cmd == "back") {
            if (r == f) cout << -1 << '\n';
            else cout << a[r - 1] << '\n';
        }
    }
}