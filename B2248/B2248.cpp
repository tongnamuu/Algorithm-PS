#include <iostream>
#include <string>
#include <cassert>
using namespace std;
long long d[33][33];
string track(int n, int cnt, long long k) {
    if (n == 0) {
        return "";
    }
    if (cnt == 0 || k == 0) {
        return string(n, '0');
    }
    if (k >= d[n-1][cnt]) {
        return '1' + track(n - 1, cnt - 1, k - d[n - 1][cnt]);
    }
    else {
        return '0' + track(n - 1, cnt, k);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, l; long long k; cin >> n >> l >> k;
    d[1][0] = d[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            d[i][j] = d[i - 1][j];
            if (j) {
                d[i][j] += d[i - 1][j - 1];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            d[i][j] += d[i][j - 1];
        }
    }
    string ans = track(n, l, k - 1);
    cout << ans;
}
