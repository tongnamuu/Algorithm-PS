#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	int start = 1;
	int end = 1000000000;
	while (start <= end) {
		int mid = start + end >> 1;
		int cnt = 0;
		int same = 0;
		for (int i = 1; i <= n; ++i) {
			cnt += mid / i > n ? n : mid / i;
			if (mid%i == 0 && mid / i <= n) ++same;
		}
		if (k <= cnt) {
			end = mid - 1;
			if (cnt - same < k) {
				cout << mid << '\n';
				return 0;
			}
		}
		else {
			start = mid + 1;
		}
	}
	cout << start << '\n';
}