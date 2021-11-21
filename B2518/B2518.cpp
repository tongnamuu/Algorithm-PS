#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 1000000000
int a[3][101];
int d[3][101][101][101];
int len[3];
int n;
int move(int x, int y) {
    if (x < y) swap(x, y);
    return min(x - y, abs(y - x + n));
}
int pos(int before, int x, int y, int z) {
    if (before == 0) {
        return a[0][x - 1];
    }
    else if (before == 1) {
        return a[1][y - 1] + 2 * n / 3;
    }
    else if (before == 2) {
        return a[2][z - 1] + n / 3;
    }
}
int solve(int before, int x, int y, int z) {
    if (x == len[0] + 1 && y == len[1] + 1 && z == len[2] + 1) return 0;
    if (x > len[0] + 1 || y > len[1] + 1 || z > len[2] + 1) return INF;
    int& ret = d[before][x][y][z];
    if (ret != -1) return ret;
    ret = INF;
    ret = min(solve(0, x + 1, y, z) + move(pos(before, x, y, z), a[0][x]), ret);
    ret = min(solve(1, x, y + 1, z) + move(pos(before, x, y, z), a[1][y] + 2 * n / 3), ret);
    ret = min(solve(2, x, y, z + 1) + move(pos(before, x, y, z), a[2][z] + n / 3 ), ret);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    memset(d, -1, sizeof(d));

    for (int i = 0, x; i < 3; ++i) {
        cin >> x;
        len[i] = x;
        for (int j = 1; j <= x; ++j) {
            cin >> a[i][j];
        }
    }
    a[0][0] = 1;
    int ans = solve(0, 1, 1, 1);
    cout << ans;
}