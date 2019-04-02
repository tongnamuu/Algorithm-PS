#include <iostream>
#include <string>
using namespace std;
const char alp[] = { '2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9' };
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		string s; cin >> s;
		int n; cin >> n;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			string p; cin >> p;
			bool go = true;
			for (int j = 0; p[j]; ++j) {
				if (alp[p[j] - 'a'] != s[j]) {
					go = false;
					break;
				}
			}
			ans += go;
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}