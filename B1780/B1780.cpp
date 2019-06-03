#include <iostream>
using namespace std;
int a[3000][3000];
int ans[3];
int check(int xstart, int xend, int ystart,int yend) {
	int temp = a[xstart][ystart];
	for (int i = xstart; i < xend; ++i) {
		for (int j = ystart; j < yend; ++j) {
			if (a[i][j] != temp) {
				return -2;
			}
		}
	}
	return temp;
}
void solve(int xstart, int xend, int ystart, int yend) {
	int result = check(xstart, xend, ystart, yend);
	if (result != -2) ans[result + 1]++;
	else {
		int x = (xend - xstart) / 3;
		int y = (yend - ystart) / 3;
		solve(xstart, xstart + x, ystart, ystart + y);
		solve(xstart + x, xstart + 2 * x, ystart, ystart + y);
		solve(xstart + 2 * x, xstart + 3 * x, ystart, ystart + y);

		solve(xstart, xstart + x, ystart + y, ystart + 2 * y);
		solve(xstart + x, xstart + 2 * x, ystart + y, ystart + 2 * y);
		solve(xstart + 2 * x, xstart + 3 * x, ystart + y, ystart + 2 * y);

		solve(xstart, xstart + x, ystart + 2 * y, ystart + 3 * y);
		solve(xstart + x, xstart + 2 * x, ystart + 2 * y, ystart + 3 * y);
		solve(xstart + 2 * x, xstart + 3 * x, ystart + 2 * y, ystart + 3 * y);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
	solve(0, n, 0, n);
	cout << ans[0] << '\n' << ans[1] << '\n' << ans[2] << '\n';
}