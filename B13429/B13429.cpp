#include <iostream>
using namespace std;
int a[13];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int t; cin >> t;
    int cnt = 0;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i&(1 << j)) {
                for (int k = 0; k < n; ++k) {
                    if (i&(1 << k)) continue;
                    if (a[j] < a[k] && a[j] + t >= a[k] - t) ++cnt;
                }
            }
        }
    }
    double ans = (double)cnt / (1 << n);
    cout << ans;
}
