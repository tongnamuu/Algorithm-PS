#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		x -= 1;
		y -= 1;
		bool find = false;
		int year = x;
		for (year = x; year <= n * m; year += m) {
			if (year%n == y) {
				find = true;
				cout << year + 1 << '\n';
				break;
			}
		}
		if (!find) cout << -1 << '\n';
	}
}