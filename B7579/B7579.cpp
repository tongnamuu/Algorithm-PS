#include <iostream>
using namespace std;
int memory[101];
int cost[101];
int d[101][100001];
int max(int a, int b) { return a > b ? a : b; }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> memory[i];
	for (int i = 1; i <= n; ++i) cin >> cost[i];
	int ans = 2147483647;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 10000; ++j) {
			d[i][j] = d[i - 1][j];
			if(j-cost[i]>=0) d[i][j] = max(d[i][j], d[i - 1][j - cost[i]] + memory[i]);
			if (d[i][j] >= m && ans > j) ans = j;
		}
	}
	cout << ans << '\n';
}