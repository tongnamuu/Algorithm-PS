#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n; cin >> n;
		int d[28] = { 0, };
		char a[31];
		for (int i = 0; i < n; ++i) {
			cin >> a;
			d[a[0] - 'A']++;
		}
		int ans = 0;
		for (int i = 0; i <= 'Z' - 'A'; ++i) {
			if (d[i]) ++ans;
			else break;
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}