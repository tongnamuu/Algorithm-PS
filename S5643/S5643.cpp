#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int n;
int a[501][501];
inline void go(int node) {
	if (a[node][0] != -1) return;
	for (register int i = 1; i <= n; ++i) {
		if (a[node][i] == 1) {
			go(i);
			for (register int j = 1; j <= n; ++j) {
				if (a[i][j] == 1) a[node][j] = 1;
			}
		}
	}
	int sum = 0;
	for (register int i = 1; i <= n; ++i) sum += a[node][i];
	a[node][0] = sum;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case) {
		int m; cin >> n >> m;
		memset(a, 0, sizeof(a));
		for (register int i = 0; i <= n; ++i) a[i][0] = -1;
		for (register int i = 0, small, large; i < m; ++i) {
			cin >> small >> large;
			a[small][large] = 1;
		}
		for (register int i = 1; i <= n; ++i) go(i);
		for (register int i = 1; i <= n; ++i) for (register int j = 1; j <= n; ++j) a[0][i] += a[j][i];
		int ans = 0;
		for (register int i = 1; i <= n; ++i) ans += (a[0][i] + a[i][0] == n - 1);
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}