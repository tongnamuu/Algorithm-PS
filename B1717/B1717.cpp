#include <iostream>
using namespace std;
int p[1000001];
int Rank[1000001];
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
		if (Rank[x] == Rank[y]) Rank[x]++;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i <= n; ++i) p[i] = i;
	while (m--) {
		int cmd, a, b; cin >> cmd >> a >> b;
		if (cmd == 0) Union(a, b);
		else if (cmd == 1) cout << (findparent(a) == findparent(b) ? "YES\n" : "NO\n");
	}
}