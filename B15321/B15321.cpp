#include <iostream>
#include <algorithm>
using namespace std;
#define N 501
int a[N];
int d[N][N];
int n;
int max_value[N][N];
int go(int s, int e) {
    if (s > e) return 0;
    int& ret = d[s][e];
    if (s == e) return ret = 0;
    if (ret != -1) return ret;
    ret = 500000000;
    for (int i = s; i <= e; ++i) {
        ret = min(ret, go(s, i) + go(i + 1, e) + abs(max_value[s][i] - max_value[i + 1][e]));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        max_value[i][i] = a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++ j) {
            d[i][j] = -1;
            for (int k = i; k <= j; ++k) {
                max_value[i][j] = max(max_value[i][j], a[k]);
            }
        }
    }
    cout << go(1, n);
}