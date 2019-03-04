#include <iostream>
using namespace std;
int map[11][11];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,-1,1,0,0 };
int n;
bool ok(int a, int b, int c, int d) {
	bool check[11][11] = { false, };
	for (int dir = 0; dir < 5; ++dir) {
		if (a + dx[dir] < n && a + dx[dir] >= 0 && b + dy[dir] >= 0 && b + dy[dir] < n)
			check[a + dx[dir]][b + dy[dir]] = true;
	}
	for (int dir = 0; dir < 5; ++dir) {
		if (c + dx[dir] < n && c + dx[dir] >= 0 && d + dy[dir] >= 0 && d + dy[dir] < n)
			if (check[c + dx[dir]][d + dy[dir]]) return false;
	}
	return true;
}
int cost(int a, int b) {
	int money = 0;
	for (int dir = 0; dir < 5; ++dir) if (a + dx[dir] < n && a + dx[dir] >= 0 && b + dy[dir] >= 0 && b + dy[dir] < n)  money+=map[a + dx[dir]][b + dy[dir]];
	return money;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int ans = 2147483647; cin >> n; for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j) cin >> map[i][j];
	for (int x1 = 1; x1 < n-1; ++x1) {
		for (int y1 = 1; y1 < n-1; ++y1) {
			for (int x2 = 1; x2 < n-1; ++x2) {
				for (int y2 = 1; y2 < n-1; ++y2) {
					for (int x3 = 1; x3 < n-1; ++x3) {
						for (int y3 = 1; y3 < n-1; ++y3) {
							if (ok(x1, y1, x2, y2) && ok(x2, y2, x3, y3) && ok(x1, y1, x3, y3)) {
								int temp = cost(x1, y1) + cost(x2, y2) + cost(x3, y3);
								if (temp < ans) ans = temp;
							}
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
}