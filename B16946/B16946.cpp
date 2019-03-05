#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
char a[1001][1001];
int d[1001][1001];
int dap[1001][1001];
int ab[1000001];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int n, m;
int bfs(int sx, int sy, int mark) {
	queue<pair<int, int>>q;
	q.push({ sx,sy });
	d[sx][sy] = mark;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
				if (a[nx][ny] == '0' && d[nx][ny] == 0) {
					d[nx][ny] = mark;
					q.push({ nx,ny });
					cnt++;
				}
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	 cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	int mark = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '0' && !d[i][j]) {
				int temp = bfs(i, j, mark);
				ab[mark++] = temp;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '1') {
				vector<int>hubo;
				for (int dir = 0; dir < 4; ++dir) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx >= 0 && nx < n&&ny >= 0 && ny < m && d[nx][ny]) {
						hubo.push_back(d[nx][ny]);
					}
				}
				sort(hubo.begin(), hubo.end());
				hubo.erase(unique(hubo.begin(), hubo.end()), hubo.end());
				for (auto & p : hubo) {
					dap[i][j] += ab[p];
					dap[i][j] %= 10;
				}
				++dap[i][j];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cout << dap[i][j] % 10;
		cout << '\n';
	}
}