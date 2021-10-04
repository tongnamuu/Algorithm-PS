#include <iostream>
#include <algorithm>
using namespace std;
#define N 501
#define INF 2147483647
pair<int, int> a[N];
int d[N][N];
int n;
int solve(int s, int e) {
    if (s > e) return INF;
    if (s == e) return 0;
    int& ret = d[s][e];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = s; i + 1 <= e; ++i) {
        int x = solve(s, i);
        if (x == INF) continue;
        int y = solve(i + 1, e);
        if (y == INF) continue;
        ret = min(ret, x + y + a[s].first*a[i].second*a[e].second);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        for (int j = 0; j < n; ++j) d[i][j] = -1;
    }
    cout << solve(0, n - 1);
}
