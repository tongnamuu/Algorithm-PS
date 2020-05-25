#include <iostream>
using namespace std;
int d[1001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    d[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (i >= 1) {
            if (!d[i - 1]) d[i] = 1;
        }
        if (i >= 3) {
            if (!d[i - 3]) d[i] = 1;
        }
        if (i >= 4) {
            if (!d[i - 4]) d[i] = 1;
        }
    }
    if (d[n]) cout << "SK";
    else cout << "CY";
}