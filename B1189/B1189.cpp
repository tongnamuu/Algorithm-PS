#include <iostream>
using namespace std;
char a[6][6];
bool visit[6][6];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int n, m, k;
int go(int x, int y, int dist) {
	if (x == 0 && y == m - 1) {
		return dist == k;
	}
	int cnt = 0;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < m && a[nx][ny]!='T'&&!visit[nx][ny]) {
			visit[nx][ny] = true;
			cnt += go(nx, ny, dist + 1);
			visit[nx][ny] = false;
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	visit[n - 1][0] = true;
	cout << go(n - 1, 0, 1) << '\n';
}