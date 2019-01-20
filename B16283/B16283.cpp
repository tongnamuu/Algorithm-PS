#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b, n, w;
	cin >> a >> b >> n >> w;
	if (a == b) {
		if (w==a*n && n == 2) {
			cout << 1 << ' ' << 1 << '\n';
			return 0;
		}
		else {
			cout << -1 << '\n';
			return 0;
		}
	}
	if (w == a * n || w == b * n) {
		if (a != b) {
			cout << -1 << '\n';
			return 0;
		}
	}
	if ((w - a * n) % (b - a) != 0) cout << -1 << '\n';
	else if ((w - b * n) % (a - b) != 0) cout << -1 << '\n';
	else cout << (w - b * n) / (a - b) << ' ' << (w - a * n) / (b - a) << '\n';
}