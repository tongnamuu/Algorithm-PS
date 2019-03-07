#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int a[301][301];
bool check[301][301] = { false, };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue<pair<int, int>>q;
struct info {
	int first, second, cnt;
};
void go(int sx, int sy) {
	check[sx][sy] = true;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = sx + dx[dir];
		int ny = sy + dy[dir];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < m && a[nx][ny] && !check[nx][ny]) {
			go(nx, ny);
		}
	}
}
int solve() {
	int len = 0;
	while (!q.empty()) {
		int mark = 0;
		int k = q.size();
		for (int i = 0; i < n; ++i)for (int j = 0; j < m; ++j)check[i][j] = false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] && !check[i][j]) {
					go(i, j);
					mark++;
				}
			}
		}
		if (mark >= 2) return len;
		len++;
		vector<info>temp;
		while (k--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			int cnt = 0;
			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
					if (a[nx][ny] == 0) {
						cnt++;
					}
				}
			}
			temp.push_back({ x,y,cnt });
		}
		for (info &p : temp) {
			a[p.first][p.second] -= p.cnt;
			if (a[p.first][p.second] <= 0) a[p.first][p.second] = 0;
			else q.push({ p.first,p.second });
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j]) q.push({ i,j });
		}
	}
	cout << solve() << '\n';
}