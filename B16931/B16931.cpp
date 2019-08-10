#include <iostream>
using namespace std;
int a[102][102];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	int ans = 2 * n*m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int dir = 0; dir < 4; ++dir) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (a[i][j] - a[nx][ny] > 0) {
					ans += (a[i][j] - a[nx][ny]);
				}
			}
		}
	}
	cout << ans << '\n';
}