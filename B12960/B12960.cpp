#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char a[5][48];
long long d[48 * 4][1 << 4];
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
    ret = solve(node + 1, s >> 1);
    if (a[x][y] == 'X') {
        return ret;
    }
    if (s & 1) return ret;
    if ((x + y) & 1) {
        int state = s >> 1;
        if (x + 1 < n && y + 1 < m && (state & 1) == 0 && (((state >> 1)&(1 << (n - 1))) == 0) && a[x + 1][y] == '.' && a[x + 1][y + 1] == '.') {
            state = s >> 2;
            state |= (1 << (n - 1));
            ret = max(ret, solve(node + 2, state) + 1);
        }
        state = s >> 2;
        if (x + 1 < n&&y + 1 < m&&a[x][y + 1] == '.' && a[x + 1][y + 1] == '.' && ((state & (1 << (n - 1))) == 0) && ((state & (1 << (n - 2))) == 0)) {
            state = s >> 2;
            state |= (1 << (n - 1));
            state |= (1 << (n - 2));
            ret = max(ret, solve(node + 2, state) + 1);
        }
        state = s >> 1;
        if (x - 1 >= 0 && y + 1 < m&&a[x - 1][y + 1] == '.' && a[x][y + 1] == '.' && ((state&(1 << (n - 1))) == 0) && ((state&(1 << (n - 2))) == 0)) {
            state = s >> 1;
            state |= (1 << (n - 1));
            state |= (1 << (n - 2));
            ret = max(ret, solve(node + 1, state) + 1);
        }
    }
    else {
        int state = s >> 1;
        if (x + 1 < n&&y + 1 < m && a[x + 1][y] == '.' && a[x][y + 1] == '.' && ((state & 1) == 0) && ((state&(1 << (n - 1))) == 0)) {
            state = s >> 2;
            state |= (1 << (n - 2));
            ret = max(ret, solve(node + 2, state) + 1);
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(d, -1, sizeof(d));
    long long ans = solve(0, 0);
    cout << ans;
}
