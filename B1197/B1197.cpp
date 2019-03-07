#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int from, to, weight;
	bool operator<(const node a) const {
		return this->weight < a.weight;
	}
};
node adj[100001];
int p[10001];
int Rank[10001];
int findparent(int x) {
	if (x == p[x]) return x;
	else return p[x] = findparent(p[x]);
}
void Union(int x, int y) {
	x = findparent(x);
	y = findparent(y);
	if (Rank[x] > Rank[y]) {
		p[y] = x;
	}
	else {
		p[x] = y;
		if (Rank[y] == Rank[x]) Rank[y]++;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int v, e; cin >> v >> e;
	int k = 0;
	for (int i = 0; i < e; ++i) {
		int from, to, w;
		cin >> from >> to >> w;
		adj[k++] = { from,to,w };
	}
	for (int i = 0; i <= v; ++i) p[i] = i;
	sort(adj, adj + k);
	int ans = 0;
	for (int i = 0, cnt = 0; cnt < v&&i < e; ++i) {
		node temp = adj[i];
		int px = findparent(temp.from);
		int py = findparent(temp.to);
		if (p[px] != p[py]) {
			Union(px, py);
			++cnt;
			ans += temp.weight;
		}
	}
	cout << ans << '\n';
}