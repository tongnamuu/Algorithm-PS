#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000
int a[101][101];
int b[101][101];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) if (i != j) b[i][j] = a[i][j] = INF;
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		a[u][v] = 1;
		b[v][u] = 1;
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				a[i][j] = min(a[i][k] + a[k][j], a[i][j]);
				b[i][j] = min(b[i][k] + b[k][j], b[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		int sum = 0;
		for (int j = 1; j <= n; ++j) 
			if (a[i][j] == INF && b[i][j] == INF) ++sum;
		cout << sum << '\n';
	}
}