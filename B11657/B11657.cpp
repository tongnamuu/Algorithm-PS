#include <iostream>
#include <vector>
using namespace std;
struct edge {
	int from, to, cost;
};
edge a[6000];
int d[501];
const int inf = 1000000000;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 2; i <= n; ++i) d[i] = inf;
	for (int i = 0; i < m; ++i) {
		cin >> a[i].from >> a[i].to >> a[i].cost;
	}
	bool cycle = false;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x = a[j].from;
			int y = a[j].to;
			int z = a[j].cost;
			if (d[x] != inf && d[y] > d[x] + z) {
				d[y] = d[x] + z;
				if (i == n) {
					cycle = true;
				}
			}
		}
	}
	if (cycle) cout << -1 << '\n';
	else {
		for (int i = 2; i <= n; ++i) {
			if (d[i] != inf) cout << d[i] << '\n';
			else cout << -1 << '\n';
		}
	}
}