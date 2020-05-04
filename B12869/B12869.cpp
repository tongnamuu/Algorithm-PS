#include <iostream>
#include <queue>
using namespace std;
int d[61][61][61];
int t[3];
const int m[6][3] = { {9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 3, 9}, {1, 9, 3} };
struct scv {
	int a = 0, b = 0, c = 0;
	scv(int _a, int _b, int _c) {
		a = _a, b = _b, c = _c;
	}
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	queue<scv> q;
	q.push({ t[0], t[1], t[2] });
	d[t[0]][t[1]][t[2]] = 1;
	while (!q.empty()) {
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();
		for (int i = 0; i < 6; ++i) {
			int na = a - m[i][0];
			int nb = b - m[i][1];
			int nc = c - m[i][2];
			if (na < 0) na = 0;
			if (nb < 0) nb = 0;
			if (nc < 0) nc = 0;
			if (d[na][nb][nc] == 0) {
				q.push({ na, nb, nc });
				d[na][nb][nc] = d[a][b][c] + 1;
			}
		}
	}
	cout << d[0][0][0] - 1;
	return 0;
}