#include <iostream>
#include <vector>
using namespace std;
char a[12][7];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool find4 = false;
void move() {
	for (int i = 0; i < 6; ++i) {
		char hole[12] = { '.','.', '.','.', '.','.', '.','.', '.','.', '.','.' };
		int pn = 11;
		for (int j = 11; j >= 0; --j) {
			if (a[j][i] == '.') continue;
			hole[pn--] = a[j][i];
		}
		for (int j = 0; j < 12; ++j) {
			a[j][i] = hole[j];
		}
	}
}
void dfs(vector<pair<int, int>>&hubo, bool check[][7], int x, int y, char now) {
	check[x][y] = true;
	hubo.push_back({ x, y });
	bool ismoved = false;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6 && a[nx][ny] == now && !check[nx][ny]) {
			dfs(hubo, check, nx, ny, now);
			ismoved = true;
		}
	}
	if (!ismoved && hubo.size() >= 4) {
		find4 = true;
		for (auto &p : hubo) {
			a[p.first][p.second] = '.';
		}
	}
}
bool find() {
	find4 = false;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 12; ++j) {
			if (a[j][i] == '.') continue;
			vector<pair<int, int>>hubo;
			bool check[12][7] = { false, };
			char temp = a[j][i];
			dfs(hubo, check, j, i, temp);
		}
	}
	return find4;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 12; ++i) cin >> a[i];
	int ans = 0;
	while (find()) {
		move();
		ans++;
	}
	cout << ans << '\n';
}