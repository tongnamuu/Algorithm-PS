#include <iostream>
#include <queue>
using namespace std;
int a[3001][3001];
int d[3001][3001];
char input[3001];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	queue<pair<int, int>>q;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		for (int j = 0; j < m; ++j) {
			a[i][j] = input[j] - '0';
			if (a[i][j] == 2) {
				q.push({ i,j });
				d[i][j] = 1;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (a[x][y] >= 3) {
			cout << "TAK" << '\n';
			cout << d[x][y] - 1 << '\n';
			return 0;
		}
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < m&&d[nx][ny] == 0) {
				if (a[nx][ny] == 1) continue;
				d[nx][ny] = d[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	cout << "NIE" << '\n';
	return 0;
}