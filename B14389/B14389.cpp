#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char a[11][26];
long long d[251][1 << 10];
int n, m;
long long solve(int node, int s) {
    if (node == n * m) {
        if (s == 0) return 0;
        return -2147483647;
    }
    if (node > n*m) return -2147483647;
    long long& ret = d[node][s];
    if (ret != -1) return ret;
    int x = node % n;
    int y = node / n;
    ret = solve(node + 1, s >> 1) + 1;
    if (s & 1) return ret = ret - 1;
    if (a[x][y] == '1') return ret;
    if (x + 1 < n&&y + 1 < m&&a[x + 1][y] == '.'&&a[x][y + 1] == '.'&&a[x + 1][y + 1] == '.' && (s & 1) == 0 && (s & 2) == 0) {
        int state = s >> 2;
        state |= (1 << (n - 2));
        state |= (1 << (n - 1));
        ret = max(ret, solve(node + 2, state) + 16);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n*m; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            d[i][j] = -1;
        }
    }
    long long ans = solve(0, 0);
    cout << ans;
}
