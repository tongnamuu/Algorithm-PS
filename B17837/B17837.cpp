#include <iostream>
using namespace std;
int a[14][14];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };
bool end_condition = false;
struct piece {
	int x, y;
	int dir;
	int below = -1;
	int above = -1;
};
piece p[11];
int get_top(int index) {
	while (p[index].above != -1) {
		index = p[index].above;
	}
	return index;
}
struct info {
	int piece_cnt = 0;
	int top = -1;
};
info map[13][13];
void push(int x, int y, int index) {
	if (map[x][y].top == -1) {
		map[x][y].top = index;
		map[x][y].piece_cnt++;
	}
	else {
		int temp = map[x][y].top;
		map[x][y].top = index;
		p[temp].above = index;
		p[index].below = temp;
		map[x][y].piece_cnt++;
	}
	if (map[x][y].piece_cnt >= 4) {
		end_condition = true;
	}
}
int make_reverse(int index) {
	int top = get_top(index);
	int x = top;
	while (top != -1) {
		int temp = p[top].below;
		p[top].below = p[top].above;
		p[top].above = temp;
		top = temp;
	}
	return x;
}
void move(int i) {
	int dir = p[i].dir;
	int nx = p[i].x + dx[dir];
	int ny = p[i].y + dy[dir];
	if (a[nx][ny] == 0) {
		map[p[i].x][p[i].y].piece_cnt--;
		map[p[i].x][p[i].y].top = p[i].below;
		if (p[i].below != -1) {
			p[p[i].below].above = -1;
			p[i].below = -1;
		}
		p[i].x = nx;
		p[i].y = ny;
		push(nx, ny, i);
		int index = p[i].above;
		while (index != -1) {
			map[p[index].x][p[index].y].piece_cnt--;
			p[index].x = p[i].x;
			p[index].y = p[i].y;
			push(nx, ny, index);
			index = p[index].above;
		}
	}
	else if (a[nx][ny] == 1) {
		map[p[i].x][p[i].y].top = p[i].below;
		if (p[i].below != -1) {
			p[p[i].below].above = -1;
			p[i].below = -1;
		}
		int index = make_reverse(i);
		while (index != -1) {
			map[p[index].x][p[index].y].piece_cnt--;
			p[index].x = nx;
			p[index].y = ny;
			push(nx, ny, index);
			index = p[index].above;
		}
	}
	else {
		dir = p[i].dir ^= 1;
		nx = p[i].x + dx[dir];
		ny = p[i].y + dy[dir];
		if (a[nx][ny] == 0) {
			map[p[i].x][p[i].y].piece_cnt--;
			map[p[i].x][p[i].y].top = p[i].below;
			if (p[i].below != -1) {
				p[p[i].below].above = -1;
				p[i].below = -1;
			}
			p[i].x = nx;
			p[i].y = ny;
			push(nx, ny, i);
			int index = p[i].above;
			while (index != -1) {
				map[p[index].x][p[index].y].piece_cnt--;
				p[index].x = p[i].x;
				p[index].y = p[i].y;
				push(nx, ny, index);
				index = p[index].above;
			}
		}
		else if (a[nx][ny] == 1) {
			map[p[i].x][p[i].y].top = p[i].below;
			if (p[i].below != -1) {
				p[p[i].below].above = -1;
				p[i].below = -1;
			}
			int index = make_reverse(i);
			while (index != -1) {
				map[p[index].x][p[index].y].piece_cnt--;
				p[index].x = nx;
				p[index].y = ny;
				push(nx, ny, index);
				index = p[index].above;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		a[0][i] = 2;
		a[i][0] = 2;
		a[n + 1][i] = 2;
		a[i][n + 1] = 2;
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];//0 white, 1 red, 2 blue
		}
	}
	for (int i = 1; i <= k; ++i) {
		cin >> p[i].x >> p[i].y >> p[i].dir;
		p[i].dir--;
		push(p[i].x, p[i].y, i);
	}
	for (int step = 1; step <= 1000; ++step) {
		for (int i = 1; i <= k; ++i) {
			move(i);
		}
		if (end_condition) {
			cout << step << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
}