#include <iostream>
using namespace std;
const int MAX = 65535;
int a[250001];
int seg[65536 * 4];
void update(int node, int start, int end, int index, int val) {
	if (index<start || index>end) return;
	if (start == end) {
		seg[node] += val;
		return;
	}
	update(node * 2, start, (start + end) / 2, index, val);
	update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
int query(int node, int start, int end, int kth) {
	if (start == end) return start;
	if (kth <= seg[node*2]) {
		return query(node * 2, start, (start + end) / 2, kth);
	}
	else return query(node * 2 + 1, (start + end) / 2 + 1, end, kth - seg[node * 2]);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < k - 1; ++i) update(1, 0, MAX, a[i], 1);
	long long ans = 0;
	for (int i = k - 1; i < n; ++i) {
		update(1, 0, MAX, a[i], 1);
		ans += query(1, 0, MAX, (k + 1) / 2);
		update(1, 0, MAX, a[i - k + 1], -1);
	}
	cout << ans << '\n';
}