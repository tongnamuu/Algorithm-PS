#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int num, ans = 0;
	int x, y;
	for (int i = 1; i <= 9; ++i) {//За
		for (int j = 1; j <= 9; ++j) {//ї­
			cin >> num;
			if (num > ans) {
				ans = num;
				x = i, y = j;
			}
		}
	}
	cout << ans << '\n';
	cout << x << ' ' << y << '\n';
}