#include <iostream>
using namespace std;
#define N 1000001
#define MOD 1000000007
long long seg[4 * N];
long long a[N];
void init(int node, int s, int e) {
    if (s == e) {
        seg[node] = a[s];
        return;
    }
    int m = s + e >> 1;
    init(node << 1, s, m);
    init((node << 1) | 1, m + 1, e);
    seg[node] = seg[node << 1] * seg[(node << 1) | 1] % MOD;
}
void update(int node, int s, int e, int idx, long long val) {
    if (idx<s || idx>e) return;
    if (s == e) {
        seg[node] = a[idx] = val;
        return;
    }
    int m = s + e >> 1;
    update(node << 1, s, m, idx, val);
    update((node << 1) | 1, m + 1, e, idx, val);
    seg[node] = seg[node << 1] * seg[(node << 1) | 1] % MOD;
}
long long query(int node, int s, int e, int i, int j) {
    if (e<i || s>j) return 1;
    if (i <= s && e <= j) return seg[node];
    int m = s + e >> 1;
    return query(node << 1, s, m, i, j)*query((node << 1) | 1, m + 1, e, i, j) % MOD;
}
int main() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    init(1, 1, n);
    for (int i = 0, cmd, u, v; i < m + k; ++i) {
        cin >> cmd >> u >> v;
        if (cmd == 1) {
            update(1, 1, n, u, v);
        }
        else if (cmd == 2) {
            cout << query(1, 1, n, u, v) << '\n';
        }
    }
}
