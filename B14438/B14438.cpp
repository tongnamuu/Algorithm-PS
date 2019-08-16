#include <iostream>
using namespace std;
int a[100001];
int seg[400004];
int min(int x, int y) { return x > y ? y : x; }
int init(int node, int start, int end) {
	if (start == end) return seg[node] = a[start];
	else return seg[node] = min(init(node * 2, start, (start + end) / 2), init(node * 2 + 1, (start + end) / 2 + 1, end));
}
void update(int node, int start, int end, int index, int val) {
	if (index<start || index>end) return;
	else if (start == end) seg[node] = val;
	else {
		update(node * 2, start, (start + end) / 2, index, val);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
		seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
	}
}
int query(int node, int start, int end, int i, int j) {
	if (end < i || j < start) return 2000000000;
	else if (i <= start && end <= j) return seg[node];
	else return min(query(node * 2, start, (start + end) / 2, i, j), query(node * 2 + 1, (start + end) / 2 + 1, end, i, j));
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	init(1, 1, n);
	int m; cin >> m;
	for (int i = 0, a, b, c; i < m; ++i) {
		cin >> a >> b >> c;
		if (a == 1) update(1, 1, n, b, c);
		else if (a == 2) cout << query(1, 1, n, b, c) << '\n';
	}
}