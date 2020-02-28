#include <iostream>
using namespace std;
#define N 65537
long long  seg[N * 4];
int a[250001];
void update(int node, int l, int r, int index, int val) {
	if (index<l || index>r) return;
	if (l == r) {
		seg[node] += val;
		return;
	}
	int m = l + r >> 1;
	update(node * 2, l, m, index, val);
	update(node * 2 + 1, m + 1, r, index, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
long long query(int node, int l, int r, int k) {
	if (l == r) return l;
	if (seg[2 * node] >= k) {
		return query(node * 2, l, l + r >> 1, k);
	}
	else return query(node * 2 + 1, (l + r) / 2 + 1, r, k - seg[node * 2]);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> a[i];
		update(1, 0, N, a[i], 1);
	}
	long long ans = query(1, 0, N, (k + 1) / 2);
	for (int i = k + 1; i <= n; ++i) {
		cin >> a[i];
		update(1, 0, N, a[i], 1);
		update(1, 0, N, a[i - k], -1);
		ans += query(1, 0, N, (k + 1) / 2);
	}
	cout << ans << '\n';
}