#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n; cin >> n;
		int d[51][51] = { 0, };
		int m; cin >> m;
		for (int i = 0; i < m; ++i) {
			int x, y; cin >> x >> y;
			d[x][y]++;
			int nx = x - 1;int T = 2;
			while (nx >= 0 && nx < n&&T--) d[nx--][y]++;
			nx = x + 1; T = 2;
			while (nx >= 0 && nx < n&&T--) d[nx++][y]++;
			nx = y + 1; T = 2;
			while (nx >= 0 && nx < n&&T--) d[x][nx++]++;
			nx = y - 1; T = 2;
			while (nx >= 0 && nx < n&&T--) d[x][nx--]++;
		}
		int max = 0;
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) if (max < d[i][j]) max = d[i][j];
		cout << '#' << test_case << ' ' << max << '\n';
	}
}