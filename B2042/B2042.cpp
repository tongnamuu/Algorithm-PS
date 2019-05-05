#include <iostream>
using namespace std;
int n, m, k;
int a[1000001];
long long seg[4000001];
long long init(int start, int end, int node) {
	if (start == end) return seg[node] = a[start];
	int mid = (start + end) / 2;
	return seg[node] = init(start, mid, 2 * node) + init(mid + 1, end, 2 * node + 1);
}
long long query(int start, int end, int l, int r, int node) {//l부터 r까지의 합
	if (end<l || start>r) return 0;
	if (start >= l && end <= r) return seg[node];
	int mid = (start + end) / 2;
	return query(start, mid, l, r, 2 * node) + query(mid + 1, end, l, r, 2 * node + 1);
}
long long update(int start, int end, int idx, long long val, int node) {
	if (start > idx || end < idx) return seg[node];
	if (start == end) return seg[node] = val;
	int mid = (start + end) / 2;
	return seg[node] = update(start, mid, idx, val, 2 * node) + update(mid + 1, end, idx, val, 2 * node + 1);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	init(1, n, 1);
	for (int i = 0; i < m + k; ++i) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, b, c, 1);
		}
		else cout << query(1, n, b, c, 1) << '\n';
	}
}