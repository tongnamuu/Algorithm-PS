#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string>st;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
char a[5][5];
void go(int x, int y, int cnt, string s) {
	if (cnt == 5) {
		st.insert(s);
		return;
	}
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
			go(nx, ny, cnt + 1, s + a[nx][ny]);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) cin >> a[i][j];
	string t = "";
	for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) go(i, j, 0, t+a[i][j] );
	cout << st.size() << '\n';
}