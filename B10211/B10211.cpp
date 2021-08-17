#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int d[1001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int ans = -2147483648;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            d[i] = max(a[i] + d[i - 1], a[i]);
            ans = max(ans, d[i]);
        }
        cout << ans << '\n';
    }
}
