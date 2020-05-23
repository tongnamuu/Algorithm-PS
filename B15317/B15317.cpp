#include <iostream>
#include <algorithm>
using namespace std;
#define N 100001
long long c[N];
long long s[N];
bool cal(int cnt, int money) {
    int idx = cnt;
    int r = 0;
    for (int i = 1; i <= cnt; ++i, --idx) {
        if (s[idx] >= c[i]) continue;
        r += c[i] - s[idx];
        if (r > money) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m, x; cin >> n >> m >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> s[i];
    }
    sort(s + 1, s + m + 1, [](const long long u, const long long v){
        return u > v;
    });
    int s = 0, e = min(n, m);
    int ans = 0;
    while (s <= e) {
        int m = s + e >> 1;
        if (cal(m, x)) s = m + 1;     
        else e = m - 1;
    }
    cout << e;
}