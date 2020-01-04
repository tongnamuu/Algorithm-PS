#include <iostream>
using namespace std;
int p[10001];
int cost[10001];
int min(int x, int y) { return x > y ? y : x; }
pair<int, int> findparent(int x, int c) {
	c = min(cost[x], c);
	if (x == p[x]) return { x,c };
	auto temp = findparent(p[x], c);
	p[x] = temp.first;
	cost[x] = temp.second;
	return temp;
}
int merge(int x, int y) {
	x = findparent(x, cost[x]).first;
	y = findparent(y, cost[y]).first;
	if (x == y) return 0;
	if (cost[x] < cost[y]) p[y] = x;
	else p[x] = y;
	return cost[y];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
		p[i] = i;
	}
	cost[0] = 2147483647;
	for (int i = 0, v, w; i < m; ++i) {
		cin >> v >> w;
		merge(v, w);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		findparent(i, 2147483647);
	}
	for (int i = 1; i <= n; ++i) {
		ans += merge(0, i);
	}
	if (ans > k) cout << "Oh no" << '\n';
	else cout << ans << '\n';
}