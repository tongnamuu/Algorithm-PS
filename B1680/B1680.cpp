#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int w, n; cin >> w >> n;
		int sum = 0;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int dist, trash;
			cin >> dist >> trash;
			if (sum + trash > w) {
				ans += 2 * dist;
				sum = 0;
			}
			sum += trash;
			if (i == n - 1 || sum == w) {
				ans += 2 * dist;
				sum = 0;
			}
		}
		cout << ans << '\n';	
	}
}