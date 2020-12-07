#include <iostream>
using namespace std;
#define N 1000001
long long a[N];
long long seg[4 * N];
void update(int node, int s, int e, int idx, int val) {
    if (s > idx || e < idx) return;
    if (s == e) {
        seg[node] += val;
        return;
    }
    int m = s + e >> 1;
    update(node << 1, s, m, idx, val);
    update(node * 2 + 1, m + 1, e, idx, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
long long query(int node, int s, int e, int i, int j) {
    if (e<i || s > j) return 0;
    if (i <= s && e <= j) return seg[node];
    int m = s + e >> 1;
    return query(node << 1, s, m, i, j) + query(node * 2 + 1, m + 1, e, i, j);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0, x, y, z; i < m; ++i) {
        cin >> x >> y >> z;
        if (x == 0) {
            if (y > z) y ^= z ^= y ^= z;
            cout << query(1, 1, n, y, z) << '\n';
        }
        else if (x == 1) {
            int diff = z - a[y];
            a[y] = z;
            update(1, 1, n, y, diff);
        }
    }
}
