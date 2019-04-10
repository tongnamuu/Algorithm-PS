#include <iostream>
#include <algorithm>
using namespace std;
struct pos {
	int from, to, weight;
	bool operator<(const pos& a) const {
		return this->weight < a.weight;
	}
};
pos a[1000001];
struct Unionfind {
	int Rank[100001] = { 0, };
	int p[100001] = { 0, };
	Unionfind() {
		for (int i = 0; i <= 100000; ++i) p[i] = i;
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
	for (int i = 0; i < m; ++i) {
		cin >> a[i].from >> a[i].to >> a[i].weight;
	}
	int rest = n;
	sort(a, a + m);
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		if (rest == 2) break;
		int x = u.findparent(a[i].from);
		int y = u.findparent(a[i].to);
		if (x != y) {
			u.Union(a[i].from, a[i].to);
			ans += a[i].weight;
			--rest;
		}
	}
	cout << ans << '\n';
}