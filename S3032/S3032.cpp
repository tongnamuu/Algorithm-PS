#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int a, b;
		cin >> a >> b;
		int x1 = 1, x2 = 0;
		int y1 = 0, y2 = 1;
		int pn = 2;
		while (b) {

			int r = a % b;
			int temp = x2;
			int q = a / b;
			x2 = x1 - x2 * q;
			x1 = temp;
			temp = y2;
			y2 = y1 - y2 * q;
			y1 = temp;
			a = b;
			b = r;
		}
		cout << '#' << test_case << ' ' << x1 << ' ' << y1 << '\n';
	}
}