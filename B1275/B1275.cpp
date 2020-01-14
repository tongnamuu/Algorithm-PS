#include <iostream>
using namespace std;
long long a[100001];
long long seg[400004];
void init(int node, int start, int end) {
	if (start == end) {
		seg[node] = a[start];
		return;
	}
	init(node * 2, start, (start + end) / 2);
	init(node * 2 + 1, (start + end) / 2 + 1, end);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
void update(int node, int start, int end, int index, int val) {
	if (index<start || index>end) return;
	if (start == end) {
		seg[node] = val;
	}
	else {
		update(node * 2, start, (start + end) / 2, index, val);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
}
long long query(int node, int start, int end, int i, int j) {
	if (end < i || j < start) return 0;
	if (i <= start && end <= j) return seg[node];
	return query(node * 2, start, (start + end) / 2, i, j) + query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	init(1, 1, n);
	for (int i = 0, x, y, index, val; i < q; ++i) {
		cin >> x >> y >> index >> val;
		if (x > y) x ^= y ^= x ^= y;
		cout << query(1, 1, n, x, y) << '\n';
		update(1, 1, n, index, val);
	}
}