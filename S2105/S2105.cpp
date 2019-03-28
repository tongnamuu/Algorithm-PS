#include <iostream>
using namespace std;
int n;
int ans;
bool check[101];
int a[21][21];
int dx[] = { 1, -1, -1, 1 };
int dy[] = { 1, 1, -1, -1 };
int sx, sy;
void go(int x, int y, int dir, int val) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
		if (!check[a[nx][ny]]) {
			check[a[nx][ny]] = true;
			go(nx, ny, dir + 1, val + 1);
			go(nx, ny, dir, val + 1);
			check[a[nx][ny]] = false;
		}
		else if (nx == sx && ny == sy) {
			if (val > ans) ans = val;
			return;
		}
		else return;
	}
	else return;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		ans = -1;
		for (int i = 0; i <= 100; ++i) check[i] = false;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0 && j == n - 1) continue;
				else if (i == 0 && j == 0) continue;
				else if (i == n - 1 && j == 0) continue;
				else if (i == n - 1 && j == n - 1) continue;
				sx = i, sy = j;
				check[a[i][j]] = true;
				go(i, j, 0, 1);
				check[a[i][j]] = false;
			}
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}