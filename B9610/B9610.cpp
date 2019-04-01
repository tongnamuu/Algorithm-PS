#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int a[5] = { 0, };
	for (int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		if (x == 0 || y == 0) ++a[0];
		else if (x > 0 && y > 0) ++a[1];
		else if (x < 0 && y > 0) ++a[2];
		else if (x < 0 && y < 0) ++a[3];
		else if (x > 0 && y < 0) ++a[4];
	}
	for (int i = 1; i <= 4; ++i) {
		cout << "Q" << i << ": " << a[i] << '\n';
	}
	cout << "AXIS: " << a[0] << '\n';
}