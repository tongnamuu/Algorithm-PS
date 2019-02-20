#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int i = 1, j = 1;
	int sum = 0, ans = 1;
	while (i <= n && j <= n && i<=j) {
		if (sum < n) sum += j++;
		else if (sum > n) sum -= i++;
		else {
			ans++;
			sum += j++;
		}
	}
	cout << ans << '\n';
}