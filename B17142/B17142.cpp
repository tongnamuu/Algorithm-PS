#include <iostream>
#include <queue>
using namespace std;
int a[51][51];
int d[51][51];
int n, m, k;
int ans = 2147483647;
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };
void go(int node, int cnt) {
	if (cnt == m ) {
		queue<pair<int, int>>q;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[i][j] == 3) {
					q.push({ i,j });
					d[i][j] = 0;
				}
				else d[i][j] = -1;
			}
		}

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
					if (a[nx][ny] != 1 && d[nx][ny] == -1) {
						d[nx][ny] = d[x][y] + 1;
						q.push({ nx,ny });
					}
				}
			}
		}
		int temp = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[i][j] == 0 && temp < d[i][j]) temp = d[i][j];
				if (d[i][j] == -1 && a[i][j] == 0) {
					return;
				}
			}
		}
		if (ans > temp) ans = temp;
		return;
	}
	
	for (int i = node + 1; i < k; ++i) {
		int x = i / n;
		int y = i % n;
		if (a[x][y] == 2) {
			a[x][y] = 3;
			go(i, cnt + 1);
			a[x][y] = 2;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	k = n * n;
	for (int i = 0; i < k; ++i) {
		int x = i / n;
		int y = i % n;
		if (a[x][y] == 2) {
			a[x][y] = 3;
			go(i, 1);
			a[x][y] = 2;
		}
	}
	if (ans == 2147483647) ans = -1;
	cout << ans << '\n';
}