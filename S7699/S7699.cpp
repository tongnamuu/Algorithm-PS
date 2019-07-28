#include <iostream>
using namespace std;
int n, m;
char a[21][21];
bool check[26];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int ans;
void go(int x, int y, int cnt) {
	if (ans == 26) return;
	bool cango = false;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < m && !check[a[nx][ny] - 'A']) {
			check[a[nx][ny] - 'A'] = true;
			go(nx, ny, cnt + 1);
			check[a[nx][ny] - 'A'] = false;
			cango = true;
		}
	}
	if (!cango) {
		if (cnt > ans) ans = cnt;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < 26; ++i) check[i] = false;
		check[a[0][0] - 'A'] = true;
		ans = 1;
		go(0, 0, 1);
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}