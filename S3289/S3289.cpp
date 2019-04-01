#include <iostream>
#include <vector>
using namespace std;
struct UnionFind {
	vector<int>p;
	vector<int>Rank;
	UnionFind(int n) {
		p.resize(n + 1);
		Rank.resize(n + 1);
		for (int i = 0; i <= n; ++i) {
			p[i] = i;
			Rank[i] = 0;
		}
	}
	int findparent(int x) {
		if (x == p[x]) return x;
		else return p[x] = findparent(p[x]);
	}
	void Union(int x, int y) {
		x = findparent(x);
		y = findparent(y);
		if (Rank[x] < Rank[y]) p[x] = y;
		else {
			p[y] = x;
			if (Rank[x] == Rank[y]) ++Rank[x];
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n, m; cin >> n >> m;
		UnionFind u(n);
		cout << '#' << test_case << ' ';
		for (int i = 0; i < m; ++i) {
			int cmd, a, b;
			cin >> cmd >> a >> b;
			if (cmd == 0) {
				u.Union(a, b);
			}
			else if (cmd == 1) {
				if (u.findparent(a) == u.findparent(b)) cout << 1;
				else cout << 0;
			}
		}
		cout << '\n';
	}
}