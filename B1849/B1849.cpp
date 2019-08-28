#include <iostream>
using namespace std;
int a[100001];
int ans[100001];
int seg[400004];
void init(int node, int start, int end) {
	if (start == end) seg[node] = 1;
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
}
void update(int node, int start, int end, int index, int val) {
	if (index<start || index>end) return;
	if (start == end) seg[node] += val;
	else {
		update(node * 2, start, (start + end) / 2, index, val);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
}
int query(int node, int start, int end, int k) {
	if (start == end) return start;
	if (k <= seg[node * 2]) {
		return query(node * 2, start, (start + end) / 2, k);
	}
	else return query(node * 2 + 1, (start + end) / 2 + 1, end, k - seg[node * 2]);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	init(1, 1, n);
	for (int i = 1; i <= n; ++i) {
		int index = query(1, 1, n, a[i] + 1);
		ans[index] = i;
		update(1, 1, n, index, -1);
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
}