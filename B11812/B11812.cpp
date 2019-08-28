#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n; int k, m; cin >> n >> k >> m;
	long long x, y;
	while (m--) {
		cin >> x >> y;
		if (k == 1) {
			if (x > y) cout << x - y << '\n';
			else cout << y - x << '\n';
			continue;
		}
		int cnt = 0;
		while (x != y) {
			while (x > y) {
				x = (x + k - 2) / k;
				++cnt;
			}
			while (x < y) {
				y = (y + k - 2) / k;
				++cnt;
			}
		}
		cout << cnt << '\n';
	}
}