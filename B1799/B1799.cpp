#include <iostream>
using namespace std;
int map[11][11];
bool row[25];
bool col[25];
int n;
int ans[2];
int getrow(int x, int y) {
	return n - x + y;
}
int getcol(int x, int y) {
	return x + y;
}
void solve(int index, int node, int cnt) {
	int x = node / n;
	int y = node % n;
	if (x >= n) {
		ans[index] = ans[index] < cnt ? cnt : ans[index];
		return;
	}
	int add = 2;
	if (!(n & 1)) {
		if (y == n - 1) add = 1;
		else if (y == n - 2) add = 3;
	}
	solve(index, node + add, cnt);
	if (map[x][y] && !row[getrow(x, y)] && !col[getcol(x, y)]) {
		row[getrow(x, y)] = true;
		col[getcol(x, y)] = true;
		solve(index, node + add, cnt + 1);
		row[getrow(x, y)] = false;
		col[getcol(x, y)] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	solve(0, 0, 0);
	solve(1, 1, 0);
	cout << ans[0] + ans[1];
}
