#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1147483647;
int a[21][21];
int d[20][1 << 20];
int n;
int solve(int now, int state) {
    if (now == n) {
        if (state == (1 << n)  - 1) return 0;
        return INF;
    }
    int& ret = d[now][state];
    if (ret > 0) return ret;
    ret = INF;
    for (int i = 0; i < n; ++i) {
        if (state& (1 << i)) continue;
        ret = min(ret, solve(now + 1, state | (1 << i)) + a[i][now]);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    cout << solve(0, 0);
}
