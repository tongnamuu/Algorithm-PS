#include <iostream>
#include <string>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
char a[251][251];
bool check[251][251];
int n, m;
int sheep, wolf;
int sans, wans;
void go(int x, int y) {
	check[x][y] = true;
	if(a[x][y]=='o') ++sheep;
	else if (a[x][y] == 'v') ++wolf;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < m && !check[nx][ny] && a[nx][ny]!='#') {
			go(nx, ny);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!check[i][j] && a[i][j] != '#') {
				sheep = 0, wolf = 0;
				go(i, j);
				if (sheep > wolf) sans += sheep;
				else wans += wolf;
			}
		}
	}
	cout << sans << ' ' << wans << '\n';
}