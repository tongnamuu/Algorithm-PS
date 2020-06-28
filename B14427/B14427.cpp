#include <iostream>
#include <algorithm>
using namespace std;
#define N 100002
int a[N + 1];
int seg[4*N];
void init(int node, int s, int e) {
    if (s == e) {
        seg[node] = s;
        return;
    }
    int m = s + e >> 1;
    init(node << 1, s, m);
    init((node << 1) | 1, m + 1, e);
    if (a[seg[node << 1]] < a[seg[(node << 1) | 1]]) {
        seg[node] = seg[node << 1];
    }
    else if (a[seg[node << 1]] > a[seg[(node << 1) | 1]]) {
        seg[node] = seg[(node << 1)|1];
    }
    else {
        seg[node] = min(seg[node << 1], seg[(node << 1) | 1]);
    }
}
void update(int node, int s, int e, int idx, int val) {
    if (idx > e || idx < s) return;
    if (s == e) {
        a[idx] = val;
        return;
    }
    int m = s + e >> 1;
    update(node << 1, s, m, idx, val);
    update((node << 1) | 1, m + 1, e, idx, val);
    if (a[seg[node << 1]] < a[seg[(node << 1) | 1]]) {
        seg[node] = seg[node << 1];
    }
    else if (a[seg[node << 1]] > a[seg[(node << 1) | 1]]) {
        seg[node] = seg[(node << 1) | 1];
    }
    else {
        seg[node] = min(seg[node << 1], seg[(node << 1) | 1]);
    }
}
int query(int node, int s, int e, int i, int j) {
    if (e<i || s>e) return N;
    if (i <= s && e <= j) return seg[node];
    int m = s + e >> 1;
    int m1 = query(node << 1, s, m, i, j);
    int m2 = query((node << 1) | 1, m + 1, e, i, j);
    if (a[m1] < a[m2]) return m1;
    else if (a[m1] > a[m2]) return m2;
    else return min(m1, m2);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    init(1, 1, n);
    a[N] = 2147483647;
    int q; cin >> q;
    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int idx, val; cin >> idx >> val;
            update(1, 1, n, idx, val);
        }
        else {
            cout << query(1, 1, n, 1, n) << '\n';
        }
    }
}