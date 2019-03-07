#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>   
#include <deque>
using namespace std;
int dx[] = { -1,0,1,-1,1,-1,0,1 };
int dy[] = { -1,-1,-1,0,0,1,1,1 };
struct tree {
	int age;
	bool dead = false;
	bool operator<(const tree a) const {
		return this->age < a.age;
	}
};
deque<tree>a[11 * 11];
int map[11][11];
int nut[11][11];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			nut[i][j] = 5;
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; ++i) {
		int x, y, age;
		cin >> x >> y >> age;
		--x, --y;
		a[x * 11 + y].push_back({ age,false });
	}
	int time = 0;
	while (time <  k) {
		int rest[11][11] = { 0, };
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int k = a[i * 11 + j].size();
				while (k--) {
					tree t = a[i * 11 + j].front();
					a[i * 11 + j].pop_front();
					if (t.age <= nut[i][j]) {
						nut[i][j] -= t.age;
						t.age++;
						a[i * 11 + j].push_back(t);
					}
					else {
						rest[i][j] += t.age / 2;
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) nut[i][j] += rest[i][j];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < a[i * 11 + j].size(); ++k) {
					if (a[i * 11 + j][k].dead) continue;
					if (a[i * 11 + j][k].age % 5 == 0) {
						for (int dir = 0; dir < 8; ++dir) {
							int nx = i + dx[dir];
							int ny = j + dy[dir];
							if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
								a[nx * 11 + ny].push_front({ 1,false });
							}
						}
					}
				}

			}
		}
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) nut[i][j] += map[i][j];		
		time++;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) ans += a[i * 11 + j].size();
	cout << ans << '\n';
}