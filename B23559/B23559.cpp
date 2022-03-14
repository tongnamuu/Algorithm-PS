#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> a[100001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        ans += a[i].second;
        m -= 1000;
    }
    sort(a, a + n, [](auto& u, auto& v) {
        int x = u.first - u.second;
        int y = v.first - v.second;
        if (x == y) return u.first > v.first;
        return x > y;
    });
    for (int i = 0; i < n; ++i) {
        if (a[i].first > a[i].second && m >= 4000) {
            m -= 4000;
            ans += a[i].first - a[i].second;
        }
    }
    cout << ans;
}