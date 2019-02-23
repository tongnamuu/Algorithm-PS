#include <iostream>
using namespace std;
int d[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; i + j <= n; ++j) {
			for (int k = 0; i + j + k <= n; ++k) {
				int l = n - i - j - k;		
				d[i * 1 + j * 5 + 10 * k + 50 * l]++;			
			}
		}
	}
	int max = 50 * n;
	int ans = 0;
	for (int i = 0; i <= max; ++i) {
		if (d[i]) ++ans;
	}
	cout << ans << '\n';
}