#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int x = 1, y = 0;
	while (n--) {
		int B = 0;
		if (x > 0) {
			B += x;
			x = 0;
		}
		if (y > 0) {
			x += y;
		}
		y += B;
	}
	cout << x << ' ' << y << '\n';
}