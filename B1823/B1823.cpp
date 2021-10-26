#include <iostream>
#include <algorithm>
using namespace std;
int d[2002][2002];
int a[2002];
int n;
int solve(int s, int e) {
    if (s > e) return 0;
    if (d[s][e] != -1) return d[s][e];
    int& ret = d[s][e];
    int k = n - (e - s + 1) + 1;
    ret = max(k*a[s] + solve(s + 1, e), k*a[e] + solve(s, e - 1));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 1; j <= n; ++j) d[i][j] = -1;
    }
    int ans = solve(1, n);
    cout << ans;
}
