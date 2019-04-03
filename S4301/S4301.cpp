#include <iostream>
using namespace std;
int d[5][5];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	d[1][1] = 1, d[1][2] = 2; d[1][3] = 2; d[1][4] = 2;
	d[2][1] = 2, d[2][2] = 4; d[2][3] = 4; d[2][4] = 4;
	d[3][1] = 2, d[3][2] = 4; d[3][3] = 5; d[3][4] = 6;
	d[4][1] = 2, d[4][2] = 4; d[4][3] = 6; d[4][4] = 8;
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n, m; cin >> n >> m;
		int ans = (n / 4)*(m / 4)*d[4][4] + (n / 4)*(d[4][m % 4]) + (m / 4)*(d[n % 4][4]) + d[n % 4][m % 4];
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}