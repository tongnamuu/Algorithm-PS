#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct edge {
	int from, to, weight;
};
edge a[10001];
int p[1001];
int r[1001];
struct UnionFind {
	void init(int n) {
		for (int i = 0; i <= n; ++i) {
			p[i] = i;
			r[i] = 0;
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
		if (r[x] < r[y]) p[x] = y;
		else {
			p[y] = x;
			if (r[x] == r[y]) r[x]++;
		}
	}
}; UnionFind u;
int main() {
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		u.init(n);
		for (int i = 0; i < m; ++i) {
			cin >> a[i].from >> a[i].to;
			a[i].weight = 1;
		}
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			int x = a[i].from;
			int y = a[i].to;
			if (u.findparent(x) != u.findparent(y)) {
				u.merge(x, y);
				++ans;
			}
		}
		cout << ans << '\n';
	}
}