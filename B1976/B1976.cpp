#include <iostream>
using namespace std;
int a[201][201];
struct Unionfind {
	int p[201],Rank[201];
	Unionfind() {
		for (int i = 0; i <= 200; ++i) {
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
		if (x != y) {
			if (Rank[x] > Rank[y]) p[y] = x;
			else {
				p[x] = y;
				if (Rank[x] == Rank[y]) ++Rank[y];
			}
		}
	}
};
Unionfind u;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				u.Union(i, j);
			}
		}
	}
	int start;
	cin >> start;
	start = u.findparent(start);
	bool ans = true;
	for (int i = 1; i < m; ++i) {
		int s; cin >> s;
		if (u.findparent(s) != start) {
			ans = false;
			break;
		}
	}
	if (ans) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}