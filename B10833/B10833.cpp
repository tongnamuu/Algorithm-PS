#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int ans = 0;
	for (int i = 0, a, b; i < n; ++i) {
		cin >> a >> b;
		ans += b % a;
	}
	cout << ans << '\n';
}