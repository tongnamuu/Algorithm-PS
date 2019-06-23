#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n; cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		cout << '#' << test_case << ' ' << a[0] * a[n - 1] << '\n';
	}
}