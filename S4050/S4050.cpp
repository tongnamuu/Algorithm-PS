#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n; cin >> n;
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		sort(a, a + n);
		for (int i = n - 3; i >= 0; i -= 3) sum -= a[i];
		cout << "#" << test_case << ' ' << sum << '\n';
	}
}