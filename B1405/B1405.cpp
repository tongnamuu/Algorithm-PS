#include <iostream>
using namespace std;
long double p[4];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool a[40][40];
int n;
long double ans = 0.0;
void go(int x, int y, long double now, int d) {
	if (d == n) {
		ans += now;
		return;
	}
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (a[nx][ny]) continue;
		a[nx][ny] = true;
		go(nx, ny, now*p[dir], d + 1);
		a[nx][ny] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < 4; ++i) {
		cin >> p[i];
		p[i] /= 100.0;
	}
	a[16][16] = true;
	go(16, 16, 1.0, 0);
	cout.fixed;
	cout.precision(9);
	cout << ans << '\n';
}