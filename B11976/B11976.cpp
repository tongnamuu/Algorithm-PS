#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int a[4][2];
	int before = 0, after = 0;
	for (int i = 0; i < 4; ++i) {
		cin >> a[i][0] >> a[i][1];
		before += a[i][0];
		after += a[i][1];
	}
	int x = 0, y = 0, z = 0;
	x = after - before + a[0][0] - a[0][1];
	a[1][0] += x;
	y = a[1][0] - a[1][1];
	a[2][0] += y;
	z = a[2][0] - a[2][1];
	cout << x << '\n' << y << '\n' << z << '\n';
}