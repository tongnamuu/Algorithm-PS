#include <iostream>
using namespace std;
int a[100001];
int d[100001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0, u, v, k; i < m; ++i) {
        cin >> u >> v >> k;
        d[u] += k;
        d[v + 1] += -k;
    }
    for (int i = 1; i <= n; ++i) {
        d[i] += d[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] + d[i] << ' ';
    }
}
