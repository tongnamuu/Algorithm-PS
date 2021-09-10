#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[3];
void solve(const int k, const int N, int val, int& ans) {
    if (val > N) return;
    if (val <= N && ans < val) ans = val;
    for (int i = 0; i < k; ++i) {
        solve(k, N, val * 10 + a[i], ans);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    int ans = a[0];
    solve(k, n, 0, ans);
    cout << ans;
}
