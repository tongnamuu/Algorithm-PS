#include <iostream>
using namespace std;
#define N 100001
int seg[4 * N];
int lazy[4 * N];
void update_lazy(int node, int s, int e) {
    if (!lazy[node]) return;
    if (lazy[node] & 1) {
        seg[node] = (e - s + 1) - seg[node];
    }
    if (s != e) {
        lazy[node << 1] += lazy[node];
        lazy[(node << 1) | 1] += lazy[node];
    }
    lazy[node] = 0;
}
void update(int node, int s, int e, int i, int j, int val) {
    update_lazy(node, s, e);
    if (e<i || s > j) return;
    if (i <= s && e <= j) {
        seg[node] = (e - s + 1) - seg[node];
        if (s != e) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }
    int m = s + e >> 1;
    update(node << 1, s, m, i, j, val);
    update((node << 1) | 1, m + 1, e, i, j, val);
    seg[node] = seg[node << 1] + seg[(node << 1) | 1];
}
int query(int node, int s, int e, int i, int j) {
    update_lazy(node, s, e);
    if (e<i || s>j) return 0;
    if (i <= s && e <= j) return seg[node];
    int m = s + e >> 1;
    return query(node << 1, s, m, i, j) + query((node << 1) | 1, m + 1, e, i, j);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0, cmd, u, v; i < m; ++i) {
        cin >> cmd >> u >> v;
        if (cmd == 0) {
            update(1, 1, n, u, v, 1);
        }
        else if (cmd == 1) {
            cout << query(1, 1, n, u, v) << '\n';
        }
    }
}
