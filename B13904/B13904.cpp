#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int>a[1001];
int d[1001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, [](const auto& u, const auto& v) {
        if (u.second == v.second) return u.first > v.first;
        return u.second > v.second;
    });
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = a[i].first; j >= 1; --j) {
            if (!d[j]) {
                ans += a[i].second;
                d[j] = 1;
                break;
            }
        }
    }
    cout << ans;
}
