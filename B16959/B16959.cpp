#include <iostream>
#include <queue>
using namespace std;
int d[11][11][3][101];
int a[11][11];
const int kdx[] = { -2,-2,-1,-1,1,1,2,2 };
const int kdy[] = { -1,1,-2,2,-2,2,-1,1 };
const int bdx[] = { -1,1,-1,1 };
const int bdy[] = { -1,-1,1,1 };
const int rdx[] = { 0,0,-1,1 };
const int rdy[] = { -1,1,0,0 };
struct chess {
	int x, y, piece, number;
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	queue<chess>q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				d[i][j][0][1] = 1;
				d[i][j][1][1] = 1;
				d[i][j][2][1] = 1;
				q.push({ i,j,0,1 });
				q.push({ i,j,1,1 });
				q.push({ i,j,2,1 });
			}
		}
	}
	int ans = 0;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int piece = q.front().piece;
		int number = q.front().number;
		q.pop();
		if (number == n * n) {
			ans = d[x][y][piece][number] - 1;
			break;
		}
		for (int i = 0; i < 3; ++i) {
			if (i == piece)continue;
			if (d[x][y][i][number] == 0) {
				d[x][y][i][number] = d[x][y][piece][number] + 1;
				q.push({ x,y,i,number });
			}
		}
		if (piece == 0) {
			for (int dir = 0; dir < 8; ++dir) {
				int nx = x + kdx[dir];
				int ny = y + kdy[dir];
				if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
					if (a[nx][ny] == number + 1) {
						if (d[nx][ny][piece][number + 1] == 0) {
							d[nx][ny][piece][number + 1] = d[x][y][piece][number] + 1;
							q.push({ nx,ny,piece,number + 1 });
						}
					}
					else{
						if (d[nx][ny][piece][number] == 0) {
							d[nx][ny][piece][number] = d[x][y][piece][number] + 1;
							q.push({ nx,ny,piece,number });
						}
					}
				}
			}
		}
		else if (piece == 1) {
			for (int dir = 0; dir < 4; ++dir) {
				for (int l = 1;; ++l) {
					int nx = x + bdx[dir]*l;
					int ny = y + bdy[dir]*l;
					if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
						if (a[nx][ny] == number + 1) {
							if (d[nx][ny][piece][number + 1] == 0) {
								d[nx][ny][piece][number + 1] = d[x][y][piece][number] + 1;
								q.push({ nx,ny,piece,number + 1 });
							}
						}
						else {
							if (d[nx][ny][piece][number] == 0) {
								d[nx][ny][piece][number] = d[x][y][piece][number] + 1;
								q.push({ nx,ny,piece,number });
							}
						}
					}
					else break;
				}
			}
		}
		else if (piece == 2) {
			for (int dir = 0; dir < 4; ++dir) {
				for (int l = 1;; ++l) {
					int nx = x + rdx[dir] * l;
					int ny = y + rdy[dir] * l;
					if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
						if (a[nx][ny] == number + 1) {
							if (d[nx][ny][piece][number + 1] == 0) {
								d[nx][ny][piece][number + 1] = d[x][y][piece][number] + 1;
								q.push({ nx,ny,piece,number + 1 });
							}
						}
						else {
							if (d[nx][ny][piece][number] == 0) {
								d[nx][ny][piece][number] = d[x][y][piece][number] + 1;
								q.push({ nx,ny,piece,number });
							}
						}
					}
					else break;
				}
			}
		}
	}
	cout << ans << '\n';
}