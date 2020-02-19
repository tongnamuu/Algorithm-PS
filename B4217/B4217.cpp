#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define INF 100000000
char a[201][51];
int n, m;
int map[205][205];
int d[205][205];
char ancient_character[6] = { 'W','A','K','J','S','D' };
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int cnt;
bool range(int x, int y) { return x >= 0 && x <= n + 1 && y >= 0 && y <= m + 1; }
string decode(char x) {
	if (x == '0' || x == '1') {
		string temp = "000";
		temp += x;
		return temp;
	}
	else if (x >= '2'&&x <= '9') {
		int temp = x - '0';
		string r;
		while (temp) {
			if (temp & 1) {
				r.push_back('1');
			}
			else r.push_back('0');
			temp >>= 1;
		}
		reverse(r.begin(), r.end());
		int k = 4 - r.length();
		if(k>0) r = string(k, '0') + r;
		return r;
	}
	else if (x >= 'a'&&x <= 'f') {
		int temp = x - 'a' + 10;
		string r;
		while (temp) {
			if (temp & 1) {
				r.push_back('1');
			}
			else r.push_back('0');
			temp >>= 1;
		}
		reverse(r.begin(), r.end());
		int k = 4 - r.length();
		if (k>0) r = string(k, '0') + r;
		return r;
	}
}
void construct_map() {
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	memset(map, 0, sizeof(map));
	memset(d, -1, sizeof(d));
	for (int i = 1; i <= n; ++i) {
		int pn = 1;
		for (int j = 0; j < m; ++j) {
			string temp = decode(a[i][j]);
			for (int k = 0; k < 4; ++k) {
				map[i][pn++] = temp[k] - '0';
			}
		}
	}
	m *= 4;
}
void find_background(int x, int y) {
	d[x][y] = INF;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (range(nx, ny) && map[nx][ny]==0 && d[nx][ny] == -1) {
			find_background(nx, ny);
		}
	}
}
void get_count(int x, int y) {
	d[x][y] = 0;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (!range(nx, ny)) continue;
		if (d[nx][ny] != -1) continue;
		if (map[nx][ny] == 0) get_count(nx, ny);
	}
}
void get_line(int x, int y) {
	d[x][y] = 0;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (!range(nx, ny)) continue;
		if (d[nx][ny] != -1) continue;
		if (map[nx][ny] == 1) {
			get_line(nx, ny);
		}
		else {
			get_count(nx, ny);
			++cnt;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int tc = 0;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		construct_map();
		find_background(0, 0);
		vector<char>ans;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (map[i][j] == 1 && d[i][j] == -1) {
					cnt = 0;
					get_line(i, j);
					ans.push_back(ancient_character[cnt]);
				}
			}
		}
		sort(ans.begin(), ans.end());
		cout << "Case " << ++tc << ": ";
		for (char c : ans) cout << c;
		cout << '\n';
	}
}