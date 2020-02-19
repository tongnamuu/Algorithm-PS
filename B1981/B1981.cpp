#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int a[101][101];
int n;
bool visit[101][101];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };
bool range(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= n; }
bool solve(int small, int large) {
	if (a[1][1]<small || a[1][1]>large) return false;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			visit[i][j] = false;
		}
	}
	queue<pair<int, int>>q;
	q.push({1,1});
	visit[1][1] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (!range(nx, ny) || visit[nx][ny]) continue;
			if (a[nx][ny] < small || a[nx][ny]>large) continue;
			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}
	return visit[n][n];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	vector<int>p;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			p.push_back(a[i][j]);
		}
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	int pn = p.size();
	int ans = 2147483647;
	int i = 0, j = 0;
	int small =p[0], large = p[0];
	while (i < pn&&j < pn && small <= large) {
		small = p[i], large = p[j];
		if (solve(small,large)) {
			if (large - small < ans) ans = large - small;
			i++;
		}
		else j++;
	}
	cout << ans << '\n';
}