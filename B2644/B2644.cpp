#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int>a[101];
int d[101];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int x, y; cin >> x >> y;
	int m; cin >> m;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	d[x] = 1;
	queue<int>q;
	q.push(x);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int next : a[now]) {
			if (d[next] == 0) {
				d[next] = d[now] + 1;
				q.push(next);
			}
		}
	}
	cout << d[y] - 1 << '\n';
}