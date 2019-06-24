#include <iostream>
using namespace std;
struct game {
	int x, y, g;
};
game a[101];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x >> a[i].y >> a[i].g;
	}
	int ans = 0;
	for (int j = 1; j <= 3; ++j) {
		int pos = j;
		int max = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i].x == pos) {
				pos = a[i].y;
			}
			else if (a[i].y == pos) {
				pos = a[i].x;
			}
			if (a[i].g == pos)++max;
		}
		if (ans < max) ans = max;
	}
	cout << ans << '\n';
}