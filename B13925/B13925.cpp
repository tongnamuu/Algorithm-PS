#include <iostream>
using namespace std;
#define N 100001
#define MOD 1000000007
long long a[N];
long long seg[4 * N];
long long sum_lazy[4 * N];
long long mul_lazy[4 * N];
int cmd;
void init(int node, int s, int e) {
	mul_lazy[node] = 1;
	if (s == e) {
		seg[node] = a[s];
		return;
	}
	init(node << 1, s, (s + e) >> 1);
	init(node << 1 | 1, ((s + e) >> 1) + 1, e);
	seg[node] = (seg[node << 1] + seg[node << 1 | 1]) % MOD;
}
void lazy_update(int node, int s, int e) {
	if (sum_lazy[node] != 0 || sum_lazy[node] != 1) {
		seg[node] = (seg[node] * mul_lazy[node] + (long long)(e - s + 1)*sum_lazy[node]) % MOD;
		if (s != e) {
			mul_lazy[node << 1] = (mul_lazy[node << 1] * mul_lazy[node]) % MOD;
			mul_lazy[node << 1 | 1] = (mul_lazy[node << 1 | 1] * mul_lazy[node]) % MOD;
			sum_lazy[node << 1] = (mul_lazy[node] * sum_lazy[node << 1] + sum_lazy[node]) % MOD;
			sum_lazy[node << 1 | 1] = (mul_lazy[node] * sum_lazy[node << 1 | 1] + sum_lazy[node]) % MOD;
		}
		sum_lazy[node] = 0;
		mul_lazy[node] = 1;
	}
}
void update(int node, int s, int e, int i, int j, long long val) {
	lazy_update(node, s, e);
	if (e < i || j < s) return;
	if (i <= s && e <= j) {
		if (cmd == 1) {
			sum_lazy[node] = val;
		}
		else if (cmd == 2) {
			mul_lazy[node] = val;
		}
		else if (cmd == 3) {
			mul_lazy[node] = 0;
			sum_lazy[node] = val;
		}
		lazy_update(node, s, e);
		return;
	}
	update(node << 1, s, (s + e) >> 1, i, j, val);
	update(node << 1 | 1, ((s + e) >> 1) + 1, e, i, j, val);
	seg[node] = (seg[node << 1] + seg[node << 1 | 1]) % MOD;
}
long long query(int node, int s, int e, int i, int j) {
	lazy_update(node, s, e);
	if (e < i || j < s) return 0;
	if (i <= s && e <= j) return seg[node];
	return (query(node << 1, s, (s + e) >> 1, i, j) + query(node << 1 | 1, ((s + e) >> 1) + 1, e, i, j)) % MOD;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	init(1, 1, n);
	int m; cin >> m;
	for (int i = 0, x, y; i < m; ++i) {
		cin >> cmd;
		if (cmd <= 3) {
			long long v;
			cin >> x >> y >> v;
			update(1, 1, n, x, y, v);
		}
		else {
			cin >> x >> y;
			cout << query(1, 1, n, x, y) << '\n';
		}
	}
}