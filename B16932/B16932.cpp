#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[1001][1001];
int d[1001][1001];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ab[1001 * 1001] = { 0, };
int n, m;
int go(int x, int y, int mark) {
	d[x][y] = mark;
	int c = 0;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < m && d[nx][ny]==0 && a[nx][ny]==1) {
			c+=go(nx, ny, mark);
		}
	}
	return c + 1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
	int mark = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 1 && d[i][j] == 0) {
				int temp = go(i, j, mark);
				ab[mark++] = temp;
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 0) {
				int cnt = 1;
				vector<int>hubo;
				for (int dir = 0; dir < 4; ++dir) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx >= 0 && nx < n&&ny >= 0 && ny < m) if (d[nx][ny]) hubo.push_back(d[nx][ny]);					
				}
				sort(hubo.begin(), hubo.end());
				hubo.erase(unique(hubo.begin(), hubo.end()), hubo.end());
				for (auto &k : hubo) cnt += ab[k];
				if (cnt > max) max = cnt;
			}
		}
	}
	cout << max << '\n';
}