#include <iostream>
#include <algorithm>
using namespace std;
#define N 2001
pair<int, int>a[N  *N];
long long seg[4 * N];
int init(int node, int s, int e) {
    if (s == e) return seg[node] = 1;
    int m = s + e >> 1;
    return seg[node] = init(node * 2, s, m) + init(node * 2 + 1, m + 1, e);
}
void update(int node, int s, int e, int idx, int val) {
    if (idx > e || idx < s) return;
    if (s == e) {
        seg[node] += val;
        return;
    }
    int m = s + e >> 1;
    update(node << 1, s, m, idx, val);
    update(node << 1 | 1, m + 1, e, idx, val);
    seg[node] = seg[node << 1] + seg[node << 1 | 1];
}
long long query(int node, int s, int e, int i, int j) {
    if (e<i || s>j) return 0;
    if (i <= s && e <= j) return seg[node];
    int m = s + e >> 1;
    return query(node << 1, s, m, i, j) + query(node << 1 | 1, m + 1, e, i, j);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + m);
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        int y = a[i].second;
        ans += query(1, 1, n, y + 1, n);
        update(1, 1, n, y, 1);
    }
    cout << ans;
}