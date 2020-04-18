#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define N 202
bool map_check[N][N];
int n, m, k;
bool check[N];
int pred[N];
int dfs(int now) {
	if (now == -1) return 1;
	for (int i = 1; i <= m; ++i) {
		if (!map_check[now][i]) continue;
		if (!check[i]) {
			check[i] = true;
			if (dfs(pred[i])) {
				pred[i] = now;
				return 1;
			}
		}
	}
	return 0;
}
int flow() {
	int ans = 0;
	memset(pred, -1, sizeof(pred));
	for (int i = 1; i <= n; ++i) {
		memset(check, false, sizeof(check));
		ans += dfs(i);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		int x, y; cin >> x >> y;
		map_check[x][y] = true;
	}
	cout << n + m - flow();
}