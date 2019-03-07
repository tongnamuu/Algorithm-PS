#include <iostream>
#include <algorithm>
using namespace std;
struct info {
	int from, to, weight;
	bool operator<(const info a) const {
		return this->weight < a.weight;
	}
};
info a[100001];
int p[1001];
int Rank[1001];
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
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int from, to, weight; cin >> from >> to >> weight;
		a[i] = { from,to,weight };
	}
	for (int i = 1; i <= n; ++i) p[i] = i;
	sort(a, a + m);
	int ans = 0;
	for (int i = 0, cnt = 0; cnt < n&&i < m; ++i) {
		info temp = a[i];
		int px = findparent(temp.from);
		int py = findparent(temp.to);
		if (px != py) {
			Union(px, py);
			++cnt;
			ans += temp.weight;
		}
	}
	cout << ans << '\n';
}