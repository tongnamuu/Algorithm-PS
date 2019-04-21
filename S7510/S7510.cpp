#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n; cin >> n;
		int start = 1, end = 1;
		int sum = 1;
		int ans = 0;
		while (start <= end&&end<=n&&start<=n) {
			if (sum == n) {
				++end;
				sum += end;
				++ans;
			}
			else if (sum > n) {
				sum -= start;
				++start;
			}
			else if (sum < n) {
				++end;
				sum += end;
			}
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}