#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int cnt[10];
int ans[10];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
char a[1001][1001];
int total;
int n, m, p;
queue<pair<int, int>>q[10];
bool rest() {
	for (int i = 1; i <= p; ++i) if (q[i].size()) return true;
	return false;
}
void bfs(int turn) {
	int chance = q[turn].size();
	while (chance--&&total) {
		int x = q[turn].front().first;
		int y = q[turn].front().second;
		q[turn].pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
				if (a[nx][ny] == '.') {
					q[turn].push({ nx,ny });
					a[nx][ny] = turn + '0';
					++ans[turn];
					--total;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> p;
	for (int i = 1; i <= p; ++i) cin >> cnt[i];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j < m; ++j) {
			if (a[i][j] >= '1' && a[i][j] <= '9') {
				q[a[i][j] - '0'].push({ i,j });
				ans[a[i][j] - '0']++;
			}
			else if (a[i][j] == '.') ++total;
		}
	}
	int turn = 1;
	while (rest()&&total) {
		int chance = cnt[turn];
		while (q[turn].size()&&chance--&&total) {
			bfs(turn);
		}
		++turn; if (turn > p) turn = 1;
	}
	for (int i = 1; i <= p; ++i) cout << ans[i] << ' ';
}