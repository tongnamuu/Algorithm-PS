#include <iostream>
#include <vector>
using namespace std;
const long long INF = -200000000000000LL;
int n, m, dist;
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
vector<vector<long long>>d;
vector<vector<long long>>a;
long long go(long long x, long long y) {
	if (x == n - 1) return 0;
	if (d[x][y] != INF) return d[x][y];
	for(long long i = 1; i <= dist && x + i < n; ++i){
		for (long long j = max(y - (dist - i), 0); j <= min(y + (dist - i), m - 1); ++j) {
			d[x][y] = max(d[x][y], go(x + i, j) + (long long)a[x + i][j] * a[x][y]);
		}
	}
	return d[x][y];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> dist;
	a = vector<vector<long long>>(n, vector<long long>(m));
	d = vector<vector<long long>>(n, vector<long long>(m));
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			d[i][j] = INF;
		}
	}
	for (int i = 0; i < m;++i){
		go(0, i);
	}
	long long ans = INF;
	for (int i = 0; i < m; ++i) {
		ans = max(d[0][i], ans);
	}
	cout << ans << '\n';
}