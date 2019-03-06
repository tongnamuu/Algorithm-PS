#include <iostream>
#include <queue>
using namespace std;
int d[301][301] = { 0, };
bool check[301][301] = { false, };
int dx[] = { -1,0,1,-1,1,-1,0,1 };
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int n;
void bfs(int sx, int sy) {
	queue<pair<int, int>>q;
	q.push({ sx,sy });
	d[sx][sy] = 9;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 8; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
				if (d[nx][ny] == 0) {
					d[nx][ny] = 9;
					q.push({ nx,ny });
				}
				else if (d[nx][ny] != -1) {
					check[nx][ny] = true;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		char a[301][301];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			for (int j = 0; j < n; ++j) {
				d[i][j] = 0;
				check[i][j] = false;
				if (a[i][j] == '*') {
					d[i][j] = -1;
					check[i][j] = true;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (d[i][j] == -1) {
					for (int dir = 0; dir < 8; ++dir) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];
						if (nx >= 0 && nx < n&&ny >= 0 && ny < n&&d[nx][ny] != -1) ++d[nx][ny];
					}
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (d[i][j] == 0) {
					bfs(i, j);
					++cnt;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) 
				if (d[i][j] != 9 && d[i][j] != -1 && !check[i][j]) ++cnt;
		}
		cout << '#' << test_case << ' ' << cnt << '\n';
	}
}