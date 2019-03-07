#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int a[20] = { 0, }, b[20] = { 0, };
	int ans = 0;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	for (int i = 0; i < (1 << n); ++i) {
		int hp = 100;
		int score = 0;
		for (int j = 0; j < n; ++j) {
			if (i&(1 << j)) {
				hp -= a[j];
				score += b[j];
				if (hp < 0) break;
			}
		}
		if (hp > 0) {
			if (ans < score) ans = score;
		}
	}
	cout << ans << '\n';
}