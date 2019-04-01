#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		string s; cin >> s;
		int d[26] = { 0, };
		for (int i = 0; s[i]; ++i) {
			++d[s[i] - 'a'];
		}
		int ans = 0;
		for (int i = 0; i < 26; ++i) {
			ans += (d[i] * d[i] + d[i]) / 2;
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}