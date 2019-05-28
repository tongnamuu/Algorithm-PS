#include <iostream>
using namespace std;
int p[100001];
struct UnionFind {
	UnionFind(int n) {
		for (int i = 1; i <= n; ++i) {
			p[i] = i;
		}
	}
	int findparent(int x) {
		if (x == p[x]) return x;
		else return p[x] = findparent(p[x]);
	}
	void merge(int x, int y) {
		x = findparent(x);
		y = findparent(y);
		if (x == y) return;
		p[x] = y;
	}
};
int a[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	UnionFind u(n);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 0, x, y; i < m; ++i) {
		cin >> x >> y;
		x = u.findparent(x);
		y = u.findparent(y);
		if (x == y) {
			cout << a[x] << '\n';
		}
		else {
			u.merge(x, y);
			int sum = a[x] + a[y];
			a[x] = sum;
			a[y] = sum;
			cout << sum << '\n';
		}
	}
}