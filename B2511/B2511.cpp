#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int a[10];
	for (int i = 0; i < 10; ++i) cin >> a[i];
	int x = 0, y = 0;
	int win = 0;
	for (int i = 0 , num; i < 10; ++i) {
		cin >> num;
		if (num < a[i]) {
			x += 3;
			win = 1;
		}
		else if (num > a[i]) {
			y += 3;
			win = 2;
		}
		else {
			++x; ++y;
		}
	}
	cout << x << ' ' << y << '\n';
	if (x == y) {
		if (win == 0) cout << 'D';
		else if (win == 1) cout << 'A';
		else cout << 'B';
	}
	else cout << (x > y ? 'A' : 'B');
}