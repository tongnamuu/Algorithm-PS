#include <iostream>
using namespace std;
const int INF = 1000000000;
struct edge{
	int from;
	int to;
	int cost;
};
edge a[5201];
int dist[501];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, m, w;
		cin >> n >> m >> w;
		for (int i = 1; i <= n; ++i) dist[i] = INF;
		for (int i = 0; i < m; ++i) {
			cin >> a[i].from >> a[i].to >> a[i].cost;
			a[i + m].from = a[i].to;
			a[i + m].to = a[i].from;
			a[i + m].cost = a[i].cost;
		}
		for (int i = 0; i < w; ++i) {
			cin >> a[i + 2 * m].from >> a[i + 2 * m].to >> a[i + 2 * m].cost;
			a[i + 2 * m].cost *= -1;
		}
		dist[1] = 0;
		bool cycle = false;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 2 * m + w; ++j) {
				int x = a[j].from;
				int y = a[j].to;
				int c = a[j].cost;
				if (dist[x]!= INF && dist[y] > dist[x] + c) {
					dist[y] = dist[x] + c;
					if (i == n) {
						cycle = true;
					}
				}
			}
		}
		if (cycle) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}