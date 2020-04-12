#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	int sum = 0;
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		sum += x + 1;
	}
	if (sum >= m) {
		cout << 0 << '\n';
		return 0;
	}
	int rest = m - sum;
	int q = rest / (n + 1); 
	int r = rest % (n + 1);
	int ans = 0;
	for (int i = 1; i <= q; ++i) {
		ans += (n + 1) * i*i;
	}
	ans += r * (q + 1)*(q + 1);
	cout << ans;
}