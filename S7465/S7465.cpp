#include <iostream>
using namespace std;
int n, m;
int a[101][101];
bool check[101];
void go(int node) {
	check[node] = true;
	for (int i = 1; i <= n; ++i) {
		if (a[node][i] && !check[i]) go(i);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			check[i] = false;
			for (int j = 1; j <= n; ++j) a[i][j] = 0;
		}
		for (int i = 0; i < m; ++i) {
			int from, to; cin >> from >> to;
			a[from][to] = 1;
			a[to][from] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (!check[i]) {
				go(i);
				++ans;
			}
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}