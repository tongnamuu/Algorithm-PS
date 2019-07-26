#include <iostream>
using namespace std;
int a[1001];
int main() {
	int now = 1;
	for (int i = 1; i <= 1000;) {
		for (int j = 1; j <= now; ++j) {
			a[i++] = now;
		}
		now++;
	}
	int x, y; cin >> x >> y;
	int ans = 0;
	for (int i = x; i <= y; ++i) ans += a[i];
	cout << ans << '\n';
}