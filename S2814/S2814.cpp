#include <iostream>
#include <memory.h>
using namespace std;
int n, m;
int a[11][11];
bool check[11];
int ans;
int max(int a, int b) { return a > b ? a : b; }
void go(int index, int cnt) {
	bool move = false;
	for (int i = 1; i <= n; ++i) {
		if (check[i] || a[index][i] == 0) continue;
		check[i] = true;
		go(i, cnt + 1);
		check[i] = false;
	}
	if (!move) {
		if (cnt > ans) ans = cnt;
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		memset(a, 0, sizeof(a));
		memset(check, false, sizeof(check));
		cin >> n >> m;
		for (int i = 0, x, y; i < m; ++i) {
			cin >> x >> y;
			a[x][y] = 1;
			a[y][x] = 1;
		}
		ans = 0;
		for (int i = 1; i <= n; ++i) {
			check[i] = true;
			go(i, 1);
			check[i] = false;
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}