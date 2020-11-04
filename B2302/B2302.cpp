#include <iostream>
using namespace std;
#define INF 2147483647
int a[41];
int d[41][3];
int get_value(int x, int y) {
    if (x == INF && y == INF) return INF;
    else if (x == INF) return y;
    else if (y == INF) return x;
    return x + y;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0, x; i < m; ++i) {
        cin >> x;
        a[x] = 1;
        d[x][1] = d[x][2] = INF;
    }
    d[1][0] = 1;
    if (!a[1]) d[1][2] = 1;
    for (int i = 2; i <= n; ++i) {
        d[i][0] = get_value(d[i - 1][0], d[i - 1][1]); // 제자리를 유지하는 경우
        if (a[i]) continue;
        d[i][2] = get_value(d[i - 1][0], d[i - 1][1]); //오른쪽으로 가는 경우
        d[i][1] = d[i - 1][2]; // 왼쪽으로 가는 경우
    }
    int ans = get_value(d[n][0], d[n][1]);
    cout << ans;
}
