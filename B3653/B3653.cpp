#include <iostream>
#include <memory.h>
using namespace std;
int seg[800008];
int a[200002];
void init(int node, int start, int end) {
	if (start == node) seg[node] = 1;
	init(node * 2, start, (start + end) / 2);
	init(node * 2 + 1, (start + end) / 2 + 1, end);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
void update(int node, int start, int end, int index, int val) {
	if (start > index || end < index) return;
	if (start == end) {
		seg[node] += val; return;
	}
	update(node * 2, start, (start + end) / 2, index, val);
	update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
int query(int node, int start, int end, int i, int j) {
	if (end<i || start>j) return 0;
	if (i <= start && end <= j) return seg[node];
	return query(node * 2, start, (start + end) / 2, i, j) + query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		memset(seg, 0, sizeof(seg));
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			update(1, 1, n + m, m + i, 1);
			a[i] = i + m;
		}
		for (int i = m; i >= 1; --i) {
			int num; cin >> num;
			cout << query(1, 1, n + m, 1, a[num] - 1) << ' ';
			update(1, 1, n + m, i, 1);
			update(1, 1, n + m, a[num], -1);
			a[num] = i;
		}
	}
}