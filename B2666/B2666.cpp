#include <iostream>
using namespace std;
int a[21];
int d[21][21][21];
int n, m;
int abs(int x) { return x > 0 ? x : -x; }
int min(int x, int y) { return x > y ? y : x; }
int go(int s1, int s2, int idx) {
    if (idx > m) return 0;
    int& ret = d[s1][s2][idx];
    if (ret != -1) return ret;
    ret = min(go(a[idx], s2, idx + 1) + abs(s1 - a[idx]), go(s1, a[idx], idx + 1) + abs(s2 - a[idx]));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    int s1, s2; cin >> s1 >> s2;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i <= 20; ++i) {
        for (int j = 0; j <= 20; ++j) {
            for (int k = 0; k <= 20; ++k) {
                d[i][j][k] = -1;
            }
        }
    }
    cout << go(s1, s2, 1);
}