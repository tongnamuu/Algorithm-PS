#include <iostream>
using namespace std;
int n, m, k;
pair<int, int> go_move(int len, int n, int d) {
	int move_length = len;
	int move_cnt = move_length / (n - 1);
	int dist = move_length % (n - 1);
	int start;
	if (d == 1 || d == 2) {
		if (dist == 0) {
			if (move_cnt & 1) {
				start = n;
				d ^= 1;
			}
			else {
				start = 1;
			}
			return { start,d };
		}
		else {
			if (move_cnt & 1) {
				start = n;
				start -= dist;
				d ^= 1;
			}
			else {
				start = 1;
				start += dist;
			}
			return { start,d };
		}
	}
	else {
		if (dist == 0) {
			if (move_cnt & 1) {
				start = 1;
				d ^= 1;
			}
			else {
				start = n;
			}
			return { start,d };
		}
		else {
			if (move_cnt & 1) {
				start = 1;
				start += dist;
				d ^= 1;
			}
			else {
				start = n;
				start -= dist;
			}
			return { start,d };
		}
	}
}
int a[101][101];
int b[101][101];
void shark_dead(int x, int y, int index);
struct shark {
	int x, y;
	int size;
	int d;
	int v;
	int index;
	bool dead = false;
	shark() {
		x = y = size = d = v = index = 0;
	}
	void small_move() {
		a[x][y] = 0;
		int ve = v;
		if (d & 2) {
			if (d & 1) { //왼쪽
				if (y - 1 >= ve) {
					y -= ve;
					if (y == 1) d ^= 1;
				}
				else {
					ve = ve - y + 1;
					d ^= 1;
					auto q = go_move(ve, m, d);
					y = q.first;
					d = q.second;
				}
			}
			else {//오른쪽
				if (m - y >= ve) {
					y += ve;
					if (y == m) d ^= 1;
				}
				else {
					ve = ve - (m - y);
					d ^= 1;
					auto q = go_move(ve, m, d);
					y = q.first;
					d = q.second;
				}
			}
		}
		else {
			if (d & 1) { //아래
				if (n - x >= ve) {
					x += ve;
					if (x == n) d ^= 1;
				}
				else {
					ve = ve - (n - x);
					d ^= 1;
					auto q = go_move(ve, n, d);
					x = q.first;
					d = q.second;
				}
			}
			else {//위
				if (x - 1 >= ve) {
					x -= ve;
					if (x == 1) d ^= 1;
				}
				else {
					ve = ve - x + 1;
					d ^= 1;
					auto q = go_move(ve, n, d);
					x = q.first;
					d = q.second;
				}
			}
		}
		shark_dead(x, y, index);
	}
};
shark sharks[10001];
int shark_move(int index) {
	int temp = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i][index]) {
			temp = a[i][index];
			a[i][index] = 0;
			sharks[temp].dead = true;
			break;
		}
	}
	for (int i = 1; i <= k; ++i) {
		if(!sharks[i].dead)
			sharks[i].small_move();
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			a[i][j] = b[i][j];
			b[i][j] = 0;
		}
	}
	return sharks[temp].size;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> sharks[i].x >> sharks[i].y >> sharks[i].v >> sharks[i].d >> sharks[i].size;
		sharks[i].d--;
		sharks[i].index = i;
		a[sharks[i].x][sharks[i].y] = i;
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		ans += shark_move(i);
	}
	cout << ans << '\n';
}
void shark_dead(int x, int y, int index) {
	if (b[x][y] == 0) {
		b[x][y] = index;
		return;
	}
	if (sharks[b[x][y]].size < sharks[index].size) {
		sharks[b[x][y]].dead = true;
		b[x][y] = index;
	}
	else {
		sharks[index].dead = true;
	}
}