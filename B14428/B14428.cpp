#include <iostream>
#include <algorithm>
using namespace std;
#define N 100002
long long a[N];
long long seg[4 * N];
void init(int node, int s, int e) {
	if (s == e) {
		seg[node] = s;
		return;
	}
	init(node << 1, s, s + e >> 1);
	init(node << 1 | 1, (s + e >> 1) + 1, e);
	if (a[seg[node << 1]] == a[seg[node << 1 | 1]]) seg[node] = min(seg[node << 1], seg[node << 1 | 1]);
	else seg[node] = a[seg[node << 1]] > a[seg[node << 1 | 1]] ? seg[node << 1 | 1] : seg[node << 1];
}
void update(int node, int s, int e, int index, int val) {
	if (index<s || index>e) return;
	if (s == e) {
		seg[node] = index;
		a[index] = val;
		return;
	}
	update(node << 1, s, s + e >> 1, index, val);
	update(node << 1 | 1, (s + e >> 1) + 1, e, index, val);
	if (a[seg[node << 1]] == a[seg[node << 1 | 1]]) seg[node] = min(seg[node << 1], seg[node << 1 | 1]);
	else seg[node] = a[seg[node << 1]] > a[seg[node << 1 | 1]] ? seg[node << 1 | 1] : seg[node << 1];
}
int query(int node, int s, int e, int i, int j) {
	if (e < i || j < s) return N - 1;
	if (i <= s && e <= j) return seg[node];
	int x = query(node << 1, s, s + e >> 1, i, j);
	int y = query(node << 1 | 1, (s + e >> 1) + 1, e, i, j);
	if (a[x] == a[y]) return min(x, y);
	else return a[x] > a[y] ? y : x;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	a[N - 1] = 2147483647;
	init(1, 1, n);
	int m; cin >> m;
	for (int i = 0, a, b, c; i < m; ++i) {
		cin >> a >> b >> c;
		if (a == 1) update(1, 1, n, b, c);
		else cout << query(1, 1, n, b, c) << '\n';
	}
}