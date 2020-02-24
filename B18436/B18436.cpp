#include <iostream>
using namespace std;
#define N 100001
int a[N];
int tree[N];
void update(int n, int index, int val) {
	for (int i = index; i <= n; i += i & -i) tree[i] += val;
}
int query(int index) {
	int sum = 0;
	for (int i = index; i > 0; i -= i & -i) sum += tree[i];
	return sum;
}
int count(int num, int l, int r) {
	if (num & 1) return query(r) - query(l - 1);
	return r - l + 1 - query(r) + query(l - 1);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] & 1) update(n, i, 1);
	}
	int m; cin >> m;
	while (m--) {
		int cmd, x, y; cin >> cmd >> x >> y;
		if (cmd == 1) {
			if (a[x] & 1) { if (!(y & 1)) update(n, x, -1); }
			else { if (y & 1) update(n, x, 1); }
			a[x] = y;
		}
		else if (cmd == 2) cout << count(2, x, y) << '\n';
		else cout << count(3, x, y) << '\n';
	}
}