#include <iostream>
using namespace std;
int n, m;
bool check[26];
char a[21][21];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int ans;
void go(int x, int y, int cnt) {
	if (ans == 26) return;
	bool canmove = false;
	check[a[x][y] - 'A'] = true;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < m && !check[a[nx][ny] - 'A']) {
			check[a[nx][ny] - 'A'] = true;
			go(nx, ny, cnt + 1);
			check[a[nx][ny] - 'A'] = false;
			canmove = true;
		}
	}
	if (!canmove) ans = ans < cnt ? cnt : ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	go(0, 0, 1);
	cout << ans << '\n';
}